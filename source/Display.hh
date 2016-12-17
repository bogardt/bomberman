//
// Bomberman
//

#ifndef		__DISPLAY_HH__
# define	__DISPLAY_HH__

# include	<map>
# include	<vector>
# include	<thread>
# include	<mutex>
# include	"irrlicht.h"
# include	"driverChoice.h"
# include	"Entity.hh"
# include	"EventReceiver.hh"
# include	"EventListener.hh"
# include	"Resources.hh"

# include	"./components/ModelComponent.hh"
# include	"./components/PositionComponent.hh"
# include	"./components/SpeedComponent.hh"
# include	"./components/SolidityComponent.hh"

#ifdef _MSC_VER
# pragma comment(lib, "Irrlicht.lib")
#endif

# define	TILE_SIZE (500)
# define	MAP_SIZE (15)

class		Display
{
public:
  Display();
  ~Display();
  int								init(irr::IrrlichtDevice *device,
								     EventReceiver *receiver);
  int								refreshScreen();
  int								closeDisplay();
  const bool							windowIsActive() const;
  const unsigned int						getTimer();
  int								guiCreateModel(const std::string mesh,
									       const std::string texture,
									       const int &x, const int &y,
									       irr::core::vector3df rotation,
									       const int &scale);
  int								guiRemoveModel(const int &x,
									       const int &y);
  int								createModel(Entity *entity);
  void								removeModel(Entity *Entity);
  int								updateModel(Entity *entity,
									    ModelComponent::ModelType type);
  int								updateModelPosition(const unsigned int &id,
										    const unsigned int &rotation,
										    const unsigned int &x,
										    const unsigned int &y);
  void								changeMaterialType(Entity *entity,
										   irr::video::E_MATERIAL_TYPE type);
  const bool							tileIsOccupied(const unsigned int &x,
									       const unsigned int &y,
									       Entity *entity);
  const bool							tileIsOccupiedBomb(const unsigned int &x,
										   const unsigned int &y,
										   Entity *entity);
  const bool							collision(const unsigned int &firstId,
									  const unsigned int &secondId);
  void								createImage(const std::string &texture,
									    const irr::core::rect<irr::s32> &rect);

  // event listener
  void								createEventListener(unsigned int id,
										    std::vector<irr::EKEY_CODE>
										    keys);
  std::vector<irr::EKEY_CODE>					*getKeysDownForId(unsigned int id);
public:
  // video and device
  irr::IrrlichtDevice						*_device;
  irr::video::IVideoDriver					*_driver;
  irr::video::E_DRIVER_TYPE					_driverType;

  // scene
  irr::scene::ICameraSceneNode					*_camera;
  irr::scene::ISceneManager					*_smgr;
  irr::scene::ISceneNode					*_skybox;

  //mesh
  irr::scene::IAnimatedMeshSceneNode				*_model;
  std::map<unsigned int, irr::scene::IAnimatedMeshSceneNode *>	_models;
  std::map<unsigned int, irr::scene::IAnimatedMeshSceneNode *>	_guimodel;
  std::map<unsigned int, irr::scene::IAnimatedMeshSceneNode *>	_ground;

  // positions
  irr::core::vector3df						_model_position;
  irr::core::vector3df						_camera_position;

  //Event receiver
  EventReceiver							*_receiver;
  std::map<unsigned int, EventListener *>			_listeners;

  // gui
  irr::gui::IGUIEnvironment					*_env;

public:
  int								driverChoice();
  void								showFpsDriver(int last_tick);
  int								initDevice();
  void								initCamera();
  void								removeGround();
  void								initGround();
  void								initSkybox();
  void								setCursorVisibility(bool visibility);
  const bool							collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
									  irr::scene::IAnimatedMeshSceneNode *mesh2);
  const bool							collision(irr::scene::IAnimatedMeshSceneNode *mesh1,
									  irr::scene::IAnimatedMeshSceneNode *mesh2,
									  const int& size);
  void								showPosCam();

};

#endif		// __DISPLAY_HH__
