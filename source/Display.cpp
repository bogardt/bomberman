//
// Display.cpp for indie studio in /home/bogard_t/rendu/cpp_indie_studio/source
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Mon May  2 17:12:27 2016 Thomas Bogard
// Last update Mon Jun 13 19:51:45 2016 Thomas Bogard
//

# include "Display.hh"

Display::Display()
{}

Display::~Display()
{
}

int		Display::driverChoice()
{
  this->_driverType = irr::driverChoiceConsole();
  if (this->_driverType == irr::video::EDT_COUNT)
    return (-1);
  return (0);
}

void		Display::showFpsDriver(int last_tick)
{
  const int	&fps = this->_driver->getFPS();

  if (last_tick != fps)
    {
      irr::core::stringw str = L"Bomberman - driver : [";
      str += this->_driver->getName();
      str += "] FPS:[";
      str += fps;
      str += "]";
      this->_device->setWindowCaption(str.c_str());
      last_tick = fps;
    }
}

int		Display::initDevice()
{
  irr::SIrrlichtCreationParameters params;

  params.DriverType = this->_driverType;
  params.WindowSize = irr::core::dimension2d<irr::u32>(1200, 800);
  this->_device = createDeviceEx(params);
  if (!this->_device)
    return (-1);
  return (0);
}

const unsigned int	Display::getTimer()
{
  return (this->_device->getTimer()->getTime());
}

void		Display::removeGround()
{
  for (unsigned int id = 0; id < 225; ++id)
    {
      auto search = this->_ground.find(id);
      if (search != this->_ground.end())
  	{
  	  search->second->remove();
  	  this->_ground.erase(id);
  	}
    }
}

void		Display::initGround()
{
  unsigned int	id = 0;

  std::cout << "creating map" << std::endl;
  for (int row = 0; row < MAP_SIZE; row++)
    for (int column = 0; column < MAP_SIZE; column++)
      {
	irr::scene::IAnimatedMeshSceneNode *node =
	  this->_smgr->addAnimatedMeshSceneNode(this->_smgr->getMesh("./models/cube.obj"));
	node->setMaterialTexture(0, this->_driver->getTexture("./textures/sand.jpg"));
	node->setPosition(irr::core::vector3df(row * 500, -375, column * 500));
	node->setAnimationSpeed(40);
	node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	node->setScale(irr::core::vector3df(375, 375, 375));
	node->setRotation(irr::core::vector3df(0, 0, 0));
	this->_ground.emplace(id, node);
	id++;
      }
}

void		Display::initSkybox()
{
  this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
  this->_skybox =
    this->_smgr->addSkyBoxSceneNode(this->_driver->getTexture("./textures/planet.jpg"), // up
				    this->_driver->getTexture("./textures/space.jpg"),  // down
				    this->_driver->getTexture("./textures/space.jpg"),  // left
				    this->_driver->getTexture("./textures/space.jpg"),  // right
				    this->_driver->getTexture("./textures/space.jpg"),  // ft
				    this->_driver->getTexture("./textures/space.jpg")); // bk
  this->_driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);
}

void		Display::initCamera()
{
  this->_camera =
    this->_smgr->addCameraSceneNode(0,
  				    irr::core::vector3df(4050, 6080, 2560), // position
  				    irr::core::vector3df(4050, -1570, 3730), // target
  				    -1, true);
  this->_camera->setFarValue(42000.0f);
}

int		Display::refreshScreen()
{
  const int&	last_tick = -1;

  if (this->_device->run() && this->_device)
    {
      this->_driver->beginScene(true, true, 0);
      this->_smgr->drawAll();
      this->_driver->endScene();
      this->showFpsDriver(last_tick);
    }
}

int		Display::init(irr::IrrlichtDevice *device, EventReceiver *receiver)
{
  this->_device = device;
  this->_driver = this->_device->getVideoDriver();
  this->_smgr = this->_device->getSceneManager();
  this->_env = this->_device->getGUIEnvironment();
  this->_receiver = receiver;
  this->removeGround();
  this->initGround();
  this->initSkybox();
  this->initCamera();
}

int		Display::closeDisplay()
{
  this->_device->drop();
  return (0);
}

void		Display::setCursorVisibility(bool visibility)
{
   this->_device->getCursorControl()->setVisible(visibility);
}

const bool	Display::windowIsActive() const
{
  return ((!this->_device || !this->_device->run()) ? false : true);
}

// models for gui
int             Display::guiCreateModel(const std::string mesh,
					const std::string texture,
					const int &x, const int &y,
					irr::core::vector3df rotation,
					const int &scale)
{
  std::string	pos = std::to_string(x) + std::to_string(y);
  unsigned int position = atoi(pos.c_str());

  if (!this->_guimodel.count(position))
    {
      irr::scene::IAnimatedMeshSceneNode *node =
	this->_smgr->addAnimatedMeshSceneNode(this->_smgr->getMesh(mesh.c_str()));
      node->setMaterialTexture(0, this->_driver->getTexture(texture.c_str()));
      node->setPosition(irr::core::vector3df(x, 1500, y));
      node->setAnimationSpeed(40);
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setScale(irr::core::vector3df(scale, scale, scale));
      node->setRotation(rotation);
      this->_guimodel.emplace(position, node);
    }
}

int		Display::guiRemoveModel(const int &x,
					const int &y)
{
  std::string	pos = std::to_string(x) + std::to_string(y);
  unsigned int position = atoi(pos.c_str());
  auto search	= this->_guimodel.find(position);
  if (search != this->_guimodel.end())
    {
      search->second->remove();
      this->_guimodel.erase(position);
    }
}

// models for entity
int		Display::createModel(Entity *entity)
{
  unsigned int				id = entity->getId();
  ModelComponent			*model =
    (ModelComponent*)entity->getComponent(Component::MODEL_COMPONENT);
  PositionComponent			*pos =
    (PositionComponent*)entity->getComponent(Component::POSITION_COMPONENT);

  irr::scene::IAnimatedMeshSceneNode	*node =
    this->_smgr->addAnimatedMeshSceneNode(this->_smgr->getMesh(model->getModel(ModelComponent::DEFAULT).c_str()));

  if (!node)
    {
      std::cerr << "model : " << model->getModel(ModelComponent::DEFAULT) << " cannot be open." << std::endl;
      return (1);
    }
  node->setMaterialTexture(0, this->_driver->getTexture(model->getTexture().c_str()));
  node->setPosition(irr::core::vector3df(pos->getX(), 300, pos->getY()));
  node->setAnimationSpeed(40);
  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  node->setMaterialType(irr::video::EMT_SOLID);
  node->setScale(irr::core::vector3df(model->getScale(), model->getScale(), model->getScale()));
  node->setRotation(irr::core::vector3df(0, pos->getRotation(), 0));
  this->_models.emplace(id, node);
  return (0);
}

void		Display::removeModel(Entity *entity)
{
  unsigned int	id = entity->getId();
  auto		search = this->_models.find(id);

  if (search != this->_models.end())
    {
      search->second->remove();
      this->_models.erase(id);
    }
}

int			Display::updateModel(Entity *entity, ModelComponent::ModelType type)
{
  auto			search = _models.find(entity->getId());
  ModelComponent	*modelComponent =
    (ModelComponent*) entity->getComponent(Component::MODEL_COMPONENT);
  irr::scene::IAnimatedMeshSceneNode	*node;

  if (search != _models.end())
    {
      if ((modelComponent->getSelectedModel() != type && !modelComponent->getModel(type).empty())
	  || type == ModelComponent::DROP)
	{
	  node = search->second;
	  if (type == ModelComponent::DROP)
	    node->setMesh(this->_smgr->getMesh("./models/BOMBERDROP.b3d"));
	  else
	    node->setMesh(this->_smgr->getMesh(modelComponent->getModel(type).c_str()));
	  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  node->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
	  node->setMaterialTexture(0, this->_driver->getTexture(modelComponent->getTexture().c_str()));
	  node->setScale(irr::core::vector3df(modelComponent->getScale(),
	  				      modelComponent->getScale(),
	  				      modelComponent->getScale()));
	  modelComponent->setSelectedModel(type);
	}
    }
}

int		Display::updateModelPosition(const unsigned int &id, const unsigned int &rotation,
					     const unsigned int &x, const unsigned int &y)
{
  auto		search = _models.find(id);
  if (search != _models.end())
    {
      irr::scene::IAnimatedMeshSceneNode  *node = search->second;
      node->setPosition(irr::core::vector3df(x, 300, y));
      node->setRotation(irr::core::vector3df(0, rotation, 0));
      node->updateAbsolutePosition();
    }
}

void		Display::changeMaterialType(Entity *entity,
					    irr::video::E_MATERIAL_TYPE type)
{
  auto		search = _models.find(entity->getId());
  irr::scene::IAnimatedMeshSceneNode  *node;
  ModelComponent	*modelComponent;

  if (search != _models.end())
    {
      node = search->second;
      node->setMaterialType(type);
    }
}

const bool	Display::tileIsOccupiedBomb(const unsigned int &x,
					const unsigned int &y,
					Entity* entity)
{
  bool		result;
  irr::scene::IAnimatedMeshSceneNode *node = this->_models.find(entity->getId())->second;

  result = node->getTransformedBoundingBox().isPointInside(irr::core::vector3df(x, 400, y));
  return (result);
}


const bool	Display::tileIsOccupied(const unsigned int &x,
					const unsigned int &y,
					Entity* entity)
{
  irr::scene::IAnimatedMeshSceneNode *node = this->_models.find(entity->getId())->second;

  return (node->getTransformedBoundingBox().isPointInside(irr::core::vector3df(x, 400, y)));
}

const bool	Display::collision(const unsigned int &firstId, const unsigned int &secondId)
{
  irr::scene::IAnimatedMeshSceneNode *firstNode = this->_models.find(firstId)->second;
  irr::scene::IAnimatedMeshSceneNode *secondNode = this->_models.find(secondId)->second;

  return (firstNode->getTransformedBoundingBox().
	  intersectsWithBox(secondNode->getTransformedBoundingBox()));
}

const bool	Display::collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
				   irr::scene::IAnimatedMeshSceneNode *mesh2)
{
  return (mesh1->getTransformedBoundingBox().
	  intersectsWithBox(mesh2->getTransformedBoundingBox()));
}

const bool	Display::collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
				   irr::scene::IAnimatedMeshSceneNode *mesh2, const int& size)
{
  if (mesh1->getAbsolutePosition().getDistanceFrom(mesh2->getAbsolutePosition()) < size)
    return (true);
  return (false);
}

// event listener
void		Display::createEventListener(unsigned int id, std::vector<irr::EKEY_CODE> keys)
{
  this->_listeners.emplace(id, new EventListener(keys, this->_receiver));
}

std::vector<irr::EKEY_CODE>	*Display::getKeysDownForId(unsigned int id)
{
  return (this->_listeners.find(id)->second->getKeysDown());
}

void			Display::createImage(const std::string &texture, const irr::core::rect<irr::s32> &rect)
{
  irr::gui::IGUIImage *img = this->_env->addImage(rect);
  img->setImage(this->_driver->getTexture(texture.c_str()));
  img->setScaleImage(true);
}

// private for debug
void			Display::showPosCam()
{
  const irr::core::vector3df& camera_position = this->_camera->getPosition();
  const irr::core::vector3df& camera_target = this->_camera->getTarget();

  const long& X1 = camera_position.X;
  const long& Y1 = camera_position.Y;
  const long& Z1 = camera_position.Z;
  std::cout << "position == " << X1 << " && " << Y1 << " && " << Z1 << std::endl;

  const long& X2 = camera_target.X;
  const long& Y2 = camera_target.Y;
  const long& Z2 = camera_target.Z;
  std::cout << "target == " << X2 << " && " << Y2 << " && " << Z2 << std::endl;
}
