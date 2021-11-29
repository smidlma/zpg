#include <SceneManager.hpp>

SceneManager::SceneManager(glm::vec2 resolution) {
  camera = new Camera(resolution);
  CallbackController::getInstance()->registerCamera(camera);
  scenes.push_back(makeSimpleScene());
  // scenes.push_back(makeForestScene());
  // scenes.push_back(makeTestScene());
  currentScene = scenes.at(0);
}

SceneManager::~SceneManager() {}

void SceneManager::makeTree(glm::vec3 pos) {
  Transform *t = new Transform();
  t->translate(pos);

  currentScene->addObject(new DrawableObject(
      ModelFactory::makeSphere(), t, currentScene->objects[2]->getShader()));
}

Scene *SceneManager::getCurrentScene() { return currentScene; }
int SceneManager::setScene(int index) {
  if (index >= scenes.size()) {
    return false;
  }

  currentScene = scenes.at(index);
  return true;
}

Scene *SceneManager::makeTestScene() {
  Scene *scene = new Scene();

  AbstractShader *textureTest = new ConstantShader();
  camera->registerObserver(textureTest);
  AbstractModel *plain = ModelFactory::makePlain();
  Material *material = new Material({0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 2.0,
                                    new Texture("textures/test.png"));

  // Material *m = new Material({0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 2.0,
  //                            new Texture("assets/house/test.png"));

  Transform *t = new Transform();
  t->scale(50.0f);

  DrawableObject *h = ObjectLoader::load("assets/house/model.obj");
  camera->registerObserver(h->getShader());
  scene->addObject(h);

  DrawableObject *tree = ObjectLoader::load("assets/tree/tree.obj");
  camera->registerObserver(tree->getShader());
  scene->addObject(tree);

  // scene->addObject(new DrawableObject(plain, new Transform(), textureTest,
  // m));
  scene->addObject(new DrawableObject(plain, t, h->getShader(), material));

  // scene->addLight(new PointLight());
  // scene->addLight(new PointLight());
  return scene;
}

Scene *SceneManager::makeSimpleScene() {
  Scene *scene = new Scene();
  AbstractShader *loadedS = new PhongShader();
  camera->registerObserver(loadedS);

  AbstractModel *sphere = ModelFactory::makeSphere();
  Transform *tr1 = new Transform();
  Transform *tr2 = new Transform();
  Transform *tr3 = new Transform();
  Transform *tr4 = new Transform();

  AbstractShader *textureTest = new ConstantShader();
  camera->registerObserver(textureTest);
  AbstractModel *plain = ModelFactory::makePlain();
  Material *material = new Material({0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 2.0,
                                    new Texture("textures/test.png"));

  CubeMapShader *cms = new CubeMapShader();
  camera->registerObserver(cms);
  Material *m = new Material(
      {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 2.0,
      new CubeMap("textures/cubemap/posx.jpg", "textures/cubemap/negx.jpg",
                  "textures/cubemap/posy.jpg", "textures/cubemap/negy.jpg",
                  "textures/cubemap/posz.jpg", "textures/cubemap/negz.jpg"));

  Transform *tt = new Transform();
  tt->scale(2.0f);

  scene->addObject(new DrawableObject(new SkyBox(), tt, cms, m));

  tr1->translate(glm::vec3(1.0f, 0.0f, 0.0f));
  tr2->translate(glm::vec3(-1.0f, 0.0f, 0.0f));
  tr3->translate(glm::vec3(0.0f, 0.0f, 1.0f));
  tr4->translate(glm::vec3(0.0f, 0.0f, -1.0f));
  tr1->scale(0.4f);
  tr2->scale(0.4f);
  tr3->scale(0.4f);
  tr4->scale(0.4f);
  Transform *tr5 = new Transform();
  tr5->scale(5.0f);
  // DrawableObject *h = ObjectLoader::load("assets/house/model.obj");
  // camera->registerObserver(h->getShader());
  // scene->addObject(h);
  AbstractShader *ls = new LambertShader();
  camera->registerObserver(ls);
  scene->addObject(new DrawableObject(plain, tr5, textureTest, material));
  scene->addObject(new DrawableObject(sphere, tr1, loadedS));
  scene->addObject(new DrawableObject(sphere, tr2, ls));
  scene->addObject(new DrawableObject(sphere, tr3, loadedS));
  scene->addObject(new DrawableObject(sphere, tr4, loadedS));

  // Lights
  scene->addLight(LightFactory::makePointLight(
      {0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 1, 0}, 1.0f, 0.09, 0.32, loadedS));

  scene->addLight(LightFactory::makePointLight(
      {0, 1, 0}, {1, 0, 0}, {0, 1, 0}, {2, 1, 0}, 1.0f, 0.09, 0.32, loadedS));

  return scene;
}

Scene *SceneManager::makeForestScene() {
  AbstractShader *loadedS = new PhongShader();
  AbstractShader *lambert = new LambertShader();

  camera->registerObserver(loadedS);
  camera->registerObserver(lambert);
  Scene *scene = new Scene();
  AbstractModel *plain = ModelFactory::makePlain();
  Transform *tr = new Transform();
  tr->scale(50.0f);
  tr->translate(glm::vec3(0, 0, 0));
  scene->addObject(new DrawableObject(plain, tr, loadedS));

  AbstractModel *tree = ModelFactory::makeTree();
  AbstractModel *suzi = ModelFactory::makeSuzi();
  srand(time(NULL));
  for (int i = 0; i < 20; i++) {
    Transform *tran = new Transform();
    float x = rand() % 61 - 30;
    float z = rand() % 61 - 30;
    tran->translate(glm::vec3(x, 0, z));
    tran->scale(rand() % 3 + 1);
    scene->addObject(new DrawableObject(tree, tran, loadedS));
    Transform *tr2 = new Transform();

    tr2->translate(glm::vec3(x / 2, 1, z / 2));
    scene->addObject(new DrawableObject(suzi, tr2, lambert));
  }
  return scene;
}
