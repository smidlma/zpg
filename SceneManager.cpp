#include <SceneManager.hpp>

SceneManager::SceneManager(glm::vec2 resolution) {
  camera = new Camera(resolution);
  CallbackController::getInstance()->registerCamera(camera);
  //   scenes.push_back(makeSimpleScene());
  // scenes.push_back(makeForestScene());
  scenes.push_back(makeTestScene());
  currentScene = scenes.at(0);
  
}

SceneManager::~SceneManager() {}

void SceneManager::makeTree(glm::vec3 pos) {
  Transform *t = new Transform();
  t->translate(pos);
  Material *spM = new Material({0.1, 0.1, 0.1}, {0.9, 0.2, 1}, {1, 0, 0}, 124);

  currentScene->addObject(
      new DrawableObject(ModelFactory::makeSphere(), t,
                         currentScene->objects[2]->getShader(), spM));
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
  // Create shader and register them to camera
  AbstractShader *phongShader = new PhongShader();
  camera->registerObserver(phongShader);
  AbstractShader *cubemapShader = new CubeMapShader();
  camera->registerObserver(cubemapShader);

  // Create skybox
  Material *skyboxMaterial = new Material(
      {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 2.0,
      new CubeMap("assets/skybox/right.jpg", "assets/skybox/left.jpg",
                  "assets/skybox/top.jpg", "assets/skybox/bottom.jpg",
                  "assets/skybox/front.jpg", "assets/skybox/back.jpg"));
  scene->addObject(new DrawableObject(new SkyBox(), new Transform,
                                      cubemapShader, skyboxMaterial));

  // Terain
  DrawableObject *teren = ObjectLoader::load("assets/terain/teren.obj",
                                             phongShader, new Transform());
  teren->isSelectable = false;
  scene->addObject(teren);

  // 4 Spheres
  AbstractModel *sphere = ModelFactory::makeSphere();
  Transform *sphereTr1 = new Transform();
  Transform *sphereTr2 = new Transform();
  Transform *sphereTr3 = new Transform();
  Transform *sphereTr4 = new Transform();

  sphereTr1->translate(glm::vec3(1.0f, 0.5f, 0.0f));
  sphereTr2->translate(glm::vec3(-1.0f, 0.5f, 0.0f));
  sphereTr3->translate(glm::vec3(0.0f, 0.5f, 1.0f));
  sphereTr4->translate(glm::vec3(0.0f, 0.5f, -1.0f));
  sphereTr1->scale(0.4f);
  sphereTr2->scale(0.4f);
  sphereTr3->scale(0.4f);
  sphereTr4->scale(0.4f);

  Material *spereMaterial =
      new Material({0.1, 0.1, 0.1}, {0.1, 1, 0.6}, {1, 1, 1}, 124);

  scene->addObject(
      new DrawableObject(sphere, sphereTr1, phongShader, spereMaterial));
  scene->addObject(
      new DrawableObject(sphere, sphereTr2, phongShader, spereMaterial));
  scene->addObject(
      new DrawableObject(sphere, sphereTr3, phongShader, spereMaterial));
  scene->addObject(
      new DrawableObject(sphere, sphereTr4, phongShader, spereMaterial));

  // 2 houses
  Transform *houseTr1 = new Transform();
  Transform *houseTr2 = new Transform();
  houseTr1->translate({-10, 0, 0});
  houseTr2->translate({10, 0, 0});

  DrawableObject *house1 =
      ObjectLoader::load("assets/house/model.obj", phongShader, houseTr1);

  DrawableObject *house2 = new DrawableObject(
      house1->getModel(), houseTr2, phongShader, house1->getMaterials());

  scene->addObject(house1);
  scene->addObject(house2);

  // Add movable obj
  MovableObject *zombie = ObjectLoader::loadMovable(
      "assets/zombie/zombie.obj", phongShader, new Transform());
  zombie->setControlPoints(
      glm::mat4x3({0, 0, -20}, {10, 0, 0}, {-10, 0, 0}, {0, 0, 20}));
  zombie->setSpeed(0.003f);
  scene->addObject(zombie);

  // Lights
  AbstractLight *spot = LightFactory::makeSpotLight(
      {0.1, 0.1, 0.1}, {1, 1, 1}, {1, 1, 1}, {0, 1, 0}, {0, 0, 0});
  camera->registerObserver(spot);
  scene->addLight(spot);

  scene->addLight(LightFactory::makePointLight(
      {0.1, 0.1, 0.1}, {1, 1, 1}, {1, 1, 1}, {0, 5, 0}, 1.0f, 0.09f, 0.032f));
  scene->addLight(LightFactory::makeDirectionalLight(
      {0.1, 0.1, 0.1}, {0.1, 0.1, 0.1}, {0.1, 0.1, 0.1}));

  // Normal map obj
  AbstractShader *normalShader = new NormalShader();
  camera->registerObserver(normalShader);
  Transform *boxT = new Transform();
  boxT->translate({0, 1, 0});
  scene->addObject(
      ObjectLoader::load("./assets/Box/model.obj", normalShader, boxT));

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
  // Material *m = new Material(
  //     {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 2.0,
  //     new CubeMap("textures/cubemap/posx.jpg", "textures/cubemap/negx.jpg",
  //                 "textures/cubemap/posy.jpg", "textures/cubemap/negy.jpg",
  //                 "textures/cubemap/posz.jpg", "textures/cubemap/negz.jpg"));

  Material *m = new Material(
      {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 2.0,
      new CubeMap("assets/skybox/right.jpg", "assets/skybox/left.jpg",
                  "assets/skybox/top.jpg", "assets/skybox/bottom.jpg",
                  "assets/skybox/front.jpg", "assets/skybox/back.jpg"));

  Transform *tt = new Transform();
  tt->scale(2.0f);

  scene->addObject(new DrawableObject(new SkyBox(), tt, cms, m));

  tr1->translate(glm::vec3(1.0f, 0.5f, 0.0f));
  tr2->translate(glm::vec3(-1.0f, 0.5f, 0.0f));
  tr3->translate(glm::vec3(0.0f, 0.5f, 1.0f));
  tr4->translate(glm::vec3(0.0f, 0.5f, -1.0f));
  tr1->scale(0.4f);
  tr2->scale(0.4f);
  tr3->scale(0.4f);
  tr4->scale(0.4f);
  Transform *tr5 = new Transform();
  tr5->scale(5.0f);
  tr5->translate(glm::vec3(0, 1, 0));
  DrawableObject *h =
      ObjectLoader::load("assets/house/model.obj", loadedS, new Transform());
  // scene->addObject(h);

  Material *spM = new Material({0.1, 0.1, 0.1}, {0.1, 1, 0.6}, {1, 1, 1}, 124);

  AbstractShader *ls = new LambertShader();
  camera->registerObserver(ls);
  // scene->addObject(new DrawableObject(plain, tr5, loadedS, material));
  scene->addObject(new DrawableObject(sphere, tr1, loadedS, spM));
  scene->addObject(new DrawableObject(sphere, tr2, loadedS, spM));
  scene->addObject(new DrawableObject(sphere, tr3, loadedS, spM));
  scene->addObject(new DrawableObject(sphere, tr4, loadedS, spM));
  Transform *terTnew = new Transform();
  terTnew->translate({60, 0, 0});
  terTnew->scale(5.0f);
  DrawableObject *mo =
      ObjectLoader::load("assets/test/part.obj", loadedS, terTnew);

  scene->addObject(mo);

  DrawableObject *teren =
      ObjectLoader::load("assets/terain/teren.obj", loadedS, new Transform());

  // scene->addObject(teren);
  // Lights
  AbstractLight *spot = LightFactory::makeSpotLight(
      {0.1, 0.1, 0.1}, {1, 1, 1}, {1, 1, 1}, {0, 1, 0}, {0, 0, 0});
  camera->registerObserver(spot);
  scene->addLight(spot);

  scene->addLight(LightFactory::makePointLight(
      {0.1, 0.1, 0.1}, {1, 1, 1}, {1, 1, 1}, {0, 5, 0}, 1.0f, 0.09f, 0.032f));

  // scene->addLight(LightFactory::makePointLight({0.1, 0.1, 0.1}, {0, 0.5, 1},
  //                                              {1, 1, 1}, {1, 1, 1}, 1.0f,
  //                                              0.09, 0.32,
  //                                              teren->getShader()));

  scene->addLight(LightFactory::makeDirectionalLight(
      {0.1, 0.1, 0.1}, {0.1, 0.1, 0.1}, {0.1, 0.1, 0.1}));

  // Add movable objects
  MovableObject *movableObj =
      new MovableObject(sphere, new Transform(), loadedS, spM);
  movableObj->setControlPoints(
      glm::mat4x3({0, 0, 0}, {5, 0, 10}, {5, 0, -10}, {20, 0, 0}));
  scene->addObject(movableObj);

  return scene;
}

Scene *SceneManager::makeForestScene() {
  // AbstractShader *loadedS = new PhongShader();
  // AbstractShader *lambert = new LambertShader();

  // camera->registerObserver(loadedS);
  // camera->registerObserver(lambert);
  // Scene *scene = new Scene();
  // AbstractModel *plain = ModelFactory::makePlain();
  // Transform *tr = new Transform();
  // tr->scale(50.0f);
  // tr->translate(glm::vec3(0, 0, 0));
  // scene->addObject(new DrawableObject(plain, tr, loadedS));

  // AbstractModel *tree = ModelFactory::makeTree();
  // AbstractModel *suzi = ModelFactory::makeSuzi();
  // srand(time(NULL));
  // for (int i = 0; i < 20; i++) {
  //   Transform *tran = new Transform();
  //   float x = rand() % 61 - 30;
  //   float z = rand() % 61 - 30;
  //   tran->translate(glm::vec3(x, 0, z));
  //   tran->scale(rand() % 3 + 1);
  //   scene->addObject(new DrawableObject(tree, tran, loadedS));
  //   Transform *tr2 = new Transform();

  //   tr2->translate(glm::vec3(x / 2, 1, z / 2));
  //   scene->addObject(new DrawableObject(suzi, tr2, lambert));
  // }
  // return scene;
  return nullptr;
}
