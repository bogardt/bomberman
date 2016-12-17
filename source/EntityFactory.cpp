//
// Bomberman
//

#include "EntityFactory.hh"

EntityFactory::EntityFactory()
  : _nextFreeId(1)
{}

EntityFactory::~EntityFactory()
{}

PositionComponent	*getClosestTileCenter(const unsigned int &x,
					      const unsigned int &y,
					      const unsigned int &rotation)
{
  PositionComponent	*positionComponent = new PositionComponent((x / TILE_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (y / TILE_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   rotation);
  return (positionComponent);
}

Entity			*EntityFactory::createBomb(const unsigned int &x,
						   const unsigned int &y,
						   const unsigned int &rotation,
						   const unsigned int &ownerId,
						   const ExplosiveComponent::Owner &ownerType,
						   const unsigned int &explosionSize)
{
  Entity		*normalBomb = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/MegaBomb/MegaBomb.obj",
							     "./models/MegaBomb/textureA.png",
							     30);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  ExplosiveComponent	*explosiveComponent = new ExplosiveComponent(100, explosionSize, ownerId, ownerType);

  normalBomb->addComponent(modelComponent);
  normalBomb->addComponent(positionComponent);
  normalBomb->addComponent(explosiveComponent);
  this->_nextFreeId++;
  return (normalBomb);
}

Entity			*EntityFactory::createExplosion(const unsigned int &x,
					 const unsigned int &y,
					 const unsigned int &rotation)
{
  Entity		*explosion = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/cube.obj",
							     "./textures/fire.jpg",
							     310);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  ExplosionComponent	*explosionComponent = new ExplosionComponent(50);

  explosion->addComponent(modelComponent);
  explosion->addComponent(positionComponent);
  explosion->addComponent(explosionComponent);
  this->_nextFreeId++;
  return (explosion);
}

Entity			*EntityFactory::createSolidBlock(const unsigned int &x,
							 const unsigned int &y,
							 const unsigned int &rotation)
{
  Entity		*solidBlock = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/cube.obj",
							     "./textures/metalbox.jpg",
							     375);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  SolidityComponent	*solidityComponent = new SolidityComponent;

  solidBlock->addComponent(modelComponent);
  solidBlock->addComponent(positionComponent);
  solidBlock->addComponent(solidityComponent);
  this->_nextFreeId++;
  return (solidBlock);
}

Entity			*EntityFactory::createDestructibleBlock(const unsigned int &x,
								const unsigned int &y,
								const unsigned int &rotation)
{
  Entity		*destructibleBlock = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/cube.obj",
							     "./textures/woodbox.png",
							     375);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, rotation);
  SolidityComponent	*solidityComponent = new SolidityComponent;
  HealthComponent	*healthComponent = new HealthComponent(1);

  destructibleBlock->addComponent(modelComponent);
  destructibleBlock->addComponent(positionComponent);
  destructibleBlock->addComponent(solidityComponent);
  destructibleBlock->addComponent(healthComponent);
  this->_nextFreeId++;
  return (destructibleBlock);
}

Entity			*EntityFactory::createPlayer(const unsigned int &x,
						     const unsigned int &y,
						     const unsigned int &rotation,
						     const irr::EKEY_CODE &keyUp,
						     const irr::EKEY_CODE &keyDown,
						     const irr::EKEY_CODE &keyRight,
						     const irr::EKEY_CODE &keyLeft,
						     const irr::EKEY_CODE &keyBomb,
						     const unsigned int &maxBombs,
						     const unsigned int &explosionSize,
						     const unsigned int &speed,
						     const std::string &texture,
						     Display *display)
{
  Entity		*player = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/BOMBERSTAND.b3d",
							     texture,
							     250);
  PositionComponent	*positionComponent = new PositionComponent(x, y, rotation);
  SpeedComponent	*speedComponent = new SpeedComponent(0, 0, 0);
  HealthComponent	*healthComponent = new HealthComponent(1);
  PlayerInputComponent	*playerInputComponent = new PlayerInputComponent(keyUp,
									 keyDown,
									 keyLeft,
									 keyRight,
									 keyBomb,
									 maxBombs,
									 explosionSize,
									 speed);

  modelComponent->setModel("./models/BOMBERRUN.b3d", ModelComponent::RUN);
  player->addComponent(modelComponent);
  player->addComponent(positionComponent);
  player->addComponent(playerInputComponent);
  player->addComponent(speedComponent);
  player->addComponent(healthComponent);
  display->createEventListener(player->getId(), {keyUp, keyDown, keyRight, keyLeft, keyBomb});
  this->_nextFreeId++;
  return (player);
}

Entity			*EntityFactory::createBasicEnemy(const unsigned int &x,
							 const unsigned int &y)
{
  Entity		*basicEnemy = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/BOMBERSTAND.b3d",
							     "./textures/bomberman_red.png",
							     250);
  PositionComponent	*positionComponent = new PositionComponent(x, y, 0);
  SpeedComponent	*speedComponent = new SpeedComponent(0, 0, 0);
  HealthComponent	*healthComponent = new HealthComponent(1);
  BasicEnemyComponent	*basicEnemyComponent = new BasicEnemyComponent(x, y);

  modelComponent->setModel("./models/BOMBERRUN.b3d", ModelComponent::RUN);
  basicEnemy->addComponent(modelComponent);
  basicEnemy->addComponent(positionComponent);
  basicEnemy->addComponent(speedComponent);
  basicEnemy->addComponent(healthComponent);
  basicEnemy->addComponent(basicEnemyComponent);
  this->_nextFreeId++;
  return (basicEnemy);
}

Entity			*EntityFactory::createPowerUp(const unsigned int &x,
						      const unsigned int &y,
						      PowerUpComponent::Type type)
{
  Entity		*powerUp = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/cube.obj",
							     300);
  PositionComponent	*positionComponent = new PositionComponent(x, y, 0);
  PowerUpComponent	*powerUpComponent = new PowerUpComponent(type);

  if (type == PowerUpComponent::BOMB_UP)
    modelComponent->setTexture("./textures/powerup/bombup.png");
  if (type == PowerUpComponent::FIRE_UP)
    modelComponent->setTexture("./textures/powerup/fireup.png");
  if (type == PowerUpComponent::SPEED_UP)
    modelComponent->setTexture("./textures/powerup/speedup.png");
  if (type == PowerUpComponent::LIVE_UP)
    modelComponent->setTexture("./textures/powerup/heart.png");
  powerUp->addComponent(modelComponent);
  powerUp->addComponent(positionComponent);
  powerUp->addComponent(powerUpComponent);
  this->_nextFreeId++;
  return (powerUp);
}

Entity			*EntityFactory::createPowerUpContainer(const unsigned int &x,
							       const unsigned int &y,
							       PowerUpComponent::Type containedType)
{
  Entity		*powerUpContainer = new Entity(this->_nextFreeId);
  ModelComponent	*modelComponent = new ModelComponent("./models/cube.obj",
							     "./textures/woodbox.png",
							     375);
  PositionComponent	*positionComponent = getClosestTileCenter(x, y, 0);
  SolidityComponent	*solidityComponent = new SolidityComponent;
  HealthComponent	*healthComponent = new HealthComponent(1);
  ContainerComponent	*containerComponent = new ContainerComponent(containedType);

  powerUpContainer->addComponent(modelComponent);
  powerUpContainer->addComponent(positionComponent);
  powerUpContainer->addComponent(solidityComponent);
  powerUpContainer->addComponent(healthComponent);
  powerUpContainer->addComponent(containerComponent);
  this->_nextFreeId++;
  return (powerUpContainer);
}
