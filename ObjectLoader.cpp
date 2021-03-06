#include "ObjectLoader.hpp"
struct Vertex {
  float Position[3];
  float Normal[3];
  float Texture[2];
  float Tangent[3];
};

ObjectLoader::ObjectLoader() {}

ObjectLoader::~ObjectLoader() {}

MovableObject* ObjectLoader::loadMovable(std::string fileName,
                                         AbstractShader* shader,
                                         Transform* transform) {
  Assimp::Importer importer;
  unsigned int importOptions =
      aiProcess_Triangulate |
      aiProcess_OptimizeMeshes           // sloučení malých plošek
      | aiProcess_JoinIdenticalVertices  // NUTNÉ jinak hodně duplikuje
      | aiProcess_Triangulate            // prevod vsech ploch na trojuhelniky
      | aiProcess_CalcTangentSpace;      // vypocet tangenty, nutny pro spravne
                                         // pouziti normalove mapy

  // aiProcess_GenNormals/ai_Process_GenSmoothNormals - vypocet normal s jemnych
  // prechodem v pripade, ze objekt neobsahuje normaly

  const aiScene* scene = importer.ReadFile(fileName, importOptions);

  if (scene) {  // pokud bylo nacteni uspesne
    printf("scene->mNumMeshes = %d\n", scene->mNumMeshes);
    printf("scene->mNumMaterials = %d\n", scene->mNumMaterials);

    for (unsigned int i = 0; i < scene->mNumMeshes; i++)  // Objects
    {
      aiMesh* mesh = scene->mMeshes[i];

      Vertex* pVertices = new Vertex[mesh->mNumVertices];
      std::memset(pVertices, 0, sizeof(Vertex) * mesh->mNumVertices);

      for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        if (mesh->HasPositions()) {
          pVertices[i].Position[0] = mesh->mVertices[i].x;
          pVertices[i].Position[1] = mesh->mVertices[i].y;
          pVertices[i].Position[2] = mesh->mVertices[i].z;
        }
        if (mesh->HasNormals()) {
          pVertices[i].Normal[0] = mesh->mNormals[i].x;
          pVertices[i].Normal[1] = mesh->mNormals[i].y;
          pVertices[i].Normal[2] = mesh->mNormals[i].z;
        }
        if (mesh->HasTextureCoords(0)) {
          pVertices[i].Texture[0] = mesh->mTextureCoords[0][i].x;
          pVertices[i].Texture[1] = mesh->mTextureCoords[0][i].y;
        }
        if (mesh->HasTangentsAndBitangents()) {
          pVertices[i].Tangent[0] = mesh->mTangents[i].x;
          pVertices[i].Tangent[1] = mesh->mTangents[i].y;
          pVertices[i].Tangent[2] = mesh->mTangents[i].z;
        }
      }

      // Only one material will be loaded
      Material* material;
      // Matrials
      for (unsigned int i = 1; i < scene->mNumMaterials; i++) {
        aiMaterial* mat = scene->mMaterials[i];
        aiString name;
        mat->Get(AI_MATKEY_NAME, name);
        aiColor3D amb, dif, spe;
        mat->Get(AI_MATKEY_COLOR_AMBIENT, amb);
        mat->Get(AI_MATKEY_COLOR_DIFFUSE, dif);
        mat->Get(AI_MATKEY_COLOR_SPECULAR, spe);

        float shininess;
        mat->Get(AI_MATKEY_SHININESS, shininess);

        std::cout << name.C_Str() << std::endl;
        std::cout << amb.r << std::endl;
        std::cout << dif.r << std::endl;
        std::cout << spe.r << std::endl;

        // Textures
        std::vector<AbstractTexture*> textures;
        aiString path;
        // diffuse, specular, height map
        if (mat->GetTexture(aiTextureType_DIFFUSE, 0, &path, NULL, NULL, NULL,
                            NULL, NULL) == AI_SUCCESS) {
          std::string fullPath = std::string(path.C_Str());
          std::cout << fullPath << std::endl;
          textures.push_back(new Texture(fullPath));
        }

        if (mat->GetTexture(aiTextureType_HEIGHT, 0, &path, NULL, NULL, NULL,
                            NULL, NULL) == AI_SUCCESS) {
          std::string fullPath = std::string(path.C_Str());
          std::cout << fullPath << std::endl;
          textures.push_back(new Texture(fullPath));
        }
        if (mat->GetTexture(aiTextureType_SPECULAR, 0, &path, NULL, NULL, NULL,
                            NULL, NULL) == AI_SUCCESS) {
          std::string fullPath = std::string(path.C_Str());
          std::cout << fullPath << std::endl;
          textures.push_back(new Texture(fullPath));
        }

        material = new Material({amb.r, amb.g, amb.b}, {dif.r, dif.g, dif.b},
                                {spe.r, spe.g, spe.b}, shininess, textures);
      }

      unsigned int* pIndices = nullptr;

      if (mesh->HasFaces()) {
        pIndices = new unsigned int[mesh->mNumFaces * 3];
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
          pIndices[i * 3] = mesh->mFaces[i].mIndices[0];
          pIndices[i * 3 + 1] = mesh->mFaces[i].mIndices[1];
          pIndices[i * 3 + 2] = mesh->mFaces[i].mIndices[2];
        }
      }
      GLuint VAO = 0;
      glGenVertexArrays(1, &VAO);
      GLuint VBO = 0;
      glGenBuffers(1, &VBO);
      GLuint IBO = 0;
      glGenBuffers(1, &IBO);

      glBindVertexArray(VAO);
      glBindBuffer(GL_ARRAY_BUFFER, VBO);

      glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mesh->mNumVertices,
                   pVertices, GL_STATIC_DRAW);

      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                            (GLvoid*)(0));
      glEnableVertexAttribArray(1);
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                            (GLvoid*)(3 * sizeof(GLfloat)));
      glEnableVertexAttribArray(2);
      glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                            (GLvoid*)(6 * sizeof(GLfloat)));
      glEnableVertexAttribArray(3);
      glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                            (GLvoid*)(8 * sizeof(GLfloat)));

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                   sizeof(GLuint) * mesh->mNumFaces * 3, pIndices,
                   GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindVertexArray(VAO);

      glBindVertexArray(0);

      GLsizei indicesCount = mesh->mNumFaces * 3;

      delete[] pVertices;
      delete[] pIndices;

      return new MovableObject(new Model(VAO, indicesCount), transform, shader,
                               material);
    }
  } else {
    printf("Error during parsing mesh from %s : %s \n", fileName.c_str(),
           importer.GetErrorString());
  }
  return nullptr;
}

DrawableObject* ObjectLoader::load(std::string fileName, AbstractShader* shader,
                                   Transform* transform) {
  Assimp::Importer importer;
  unsigned int importOptions =
      aiProcess_Triangulate |
      aiProcess_OptimizeMeshes           // sloučení malých plošek
      | aiProcess_JoinIdenticalVertices  // NUTNÉ jinak hodně duplikuje
      | aiProcess_Triangulate            // prevod vsech ploch na trojuhelniky
      | aiProcess_CalcTangentSpace;      // vypocet tangenty, nutny pro spravne
                                         // pouziti normalove mapy

  // aiProcess_GenNormals/ai_Process_GenSmoothNormals - vypocet normal s jemnych
  // prechodem v pripade, ze objekt neobsahuje normaly

  const aiScene* scene = importer.ReadFile(fileName, importOptions);

  if (scene) {  // pokud bylo nacteni uspesne
    printf("scene->mNumMeshes = %d\n", scene->mNumMeshes);
    printf("scene->mNumMaterials = %d\n", scene->mNumMaterials);

    for (unsigned int i = 0; i < scene->mNumMeshes; i++)  // Objects
    {
      aiMesh* mesh = scene->mMeshes[i];

      Vertex* pVertices = new Vertex[mesh->mNumVertices];
      std::memset(pVertices, 0, sizeof(Vertex) * mesh->mNumVertices);

      for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
        if (mesh->HasPositions()) {
          pVertices[i].Position[0] = mesh->mVertices[i].x;
          pVertices[i].Position[1] = mesh->mVertices[i].y;
          pVertices[i].Position[2] = mesh->mVertices[i].z;
        }
        if (mesh->HasNormals()) {
          pVertices[i].Normal[0] = mesh->mNormals[i].x;
          pVertices[i].Normal[1] = mesh->mNormals[i].y;
          pVertices[i].Normal[2] = mesh->mNormals[i].z;
        }
        if (mesh->HasTextureCoords(0)) {
          pVertices[i].Texture[0] = mesh->mTextureCoords[0][i].x;
          pVertices[i].Texture[1] = mesh->mTextureCoords[0][i].y;
        }
        if (mesh->HasTangentsAndBitangents()) {
          pVertices[i].Tangent[0] = mesh->mTangents[i].x;
          pVertices[i].Tangent[1] = mesh->mTangents[i].y;
          pVertices[i].Tangent[2] = mesh->mTangents[i].z;
        }
      }

      Material* material;
      // Matrials
      for (unsigned int i = 1; i < scene->mNumMaterials; i++) {
        aiMaterial* mat = scene->mMaterials[i];
        aiString name;
        mat->Get(AI_MATKEY_NAME, name);
        aiColor3D amb, dif, spe;
        mat->Get(AI_MATKEY_COLOR_AMBIENT, amb);
        mat->Get(AI_MATKEY_COLOR_DIFFUSE, dif);
        mat->Get(AI_MATKEY_COLOR_SPECULAR, spe);

        float shininess;
        mat->Get(AI_MATKEY_SHININESS, shininess);

        std::cout << name.C_Str() << std::endl;
        std::cout << amb.r << std::endl;
        std::cout << dif.r << std::endl;
        std::cout << spe.r << std::endl;

        // Textures
        std::vector<AbstractTexture*> textures;
        aiString path;
        // diffuse, specular, height map
        if (mat->GetTexture(aiTextureType_DIFFUSE, 0, &path, NULL, NULL, NULL,
                            NULL, NULL) == AI_SUCCESS) {
          std::string fullPath = std::string(path.C_Str());
          std::cout << fullPath << std::endl;
          textures.push_back(new Texture(fullPath));
        }

        if (mat->GetTexture(aiTextureType_HEIGHT, 0, &path, NULL, NULL, NULL,
                            NULL, NULL) == AI_SUCCESS) {
          std::string fullPath = std::string(path.C_Str());
          std::cout << fullPath << std::endl;
          textures.push_back(new Texture(fullPath));
        }
        if (mat->GetTexture(aiTextureType_SPECULAR, 0, &path, NULL, NULL, NULL,
                            NULL, NULL) == AI_SUCCESS) {
          std::string fullPath = std::string(path.C_Str());
          std::cout << fullPath << std::endl;
          textures.push_back(new Texture(fullPath));
        }
        if (textures.empty()) {
          // textures.push_back(new Texture("./assets/Box/albedo.png"));
          // textures.push_back(new NormalTexture("./assets/Box/normalmap.png"));
          // material = new Material({0.1, 0.1, 0.1}, {dif.r, dif.g, dif.b},
          //                         {1, 1, 1}, 64, textures);

        } else {
          material = new Material({amb.r, amb.g, amb.b}, {dif.r, dif.g, dif.b},
                                  {spe.r, spe.g, spe.b}, shininess, textures);
        }
      }

      unsigned int* pIndices = nullptr;

      if (mesh->HasFaces()) {
        pIndices = new unsigned int[mesh->mNumFaces * 3];
        for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
          pIndices[i * 3] = mesh->mFaces[i].mIndices[0];
          pIndices[i * 3 + 1] = mesh->mFaces[i].mIndices[1];
          pIndices[i * 3 + 2] = mesh->mFaces[i].mIndices[2];
        }
      }
      GLuint VAO = 0;
      glGenVertexArrays(1, &VAO);
      GLuint VBO = 0;
      glGenBuffers(1, &VBO);
      GLuint IBO = 0;
      glGenBuffers(1, &IBO);

      glBindVertexArray(VAO);
      glBindBuffer(GL_ARRAY_BUFFER, VBO);

      glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * mesh->mNumVertices,
                   pVertices, GL_STATIC_DRAW);

      glEnableVertexAttribArray(0);
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                            (GLvoid*)(0));
      glEnableVertexAttribArray(1);
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                            (GLvoid*)(3 * sizeof(GLfloat)));
      glEnableVertexAttribArray(2);
      glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                            (GLvoid*)(6 * sizeof(GLfloat)));
      glEnableVertexAttribArray(3);
      glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
                            (GLvoid*)(8 * sizeof(GLfloat)));

      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
      glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                   sizeof(GLuint) * mesh->mNumFaces * 3, pIndices,
                   GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
      glBindVertexArray(VAO);

      glBindVertexArray(0);

      GLsizei indicesCount = mesh->mNumFaces * 3;

      delete[] pVertices;
      delete[] pIndices;

      return new DrawableObject(new Model(VAO, indicesCount), transform, shader,
                                material);
    }
  } else {
    printf("Error during parsing mesh from %s : %s \n", fileName.c_str(),
           importer.GetErrorString());
  }
  return nullptr;
}