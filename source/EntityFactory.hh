//
// Bomberman
//

#ifndef _ENTITY_FACTORY_HH_
# define _ENTITY_FACTORY_HH_

# include "Entity.hh"
# include "irrlicht.h"
# include "Display.hh"
# include "components/Component.hh"
# include "components/PositionComponent.hh"
# include "components/ModelComponent.hh"
# include "components/SpeedComponent.hh"
# include "components/PlayerInputComponent.hh"
# include "components/SolidityComponent.hh"
# include "components/ExplosiveComponent.hh"
# include "components/ExplosionComponent.hh"
# include "components/HealthComponent.hh"
# include "components/PowerUpComponent.hh"
# include "components/ContainerComponent.hh"
# include "components/BasicEnemyComponent.hh"

class				EntityFactory
{
public:

  enum EntityType
    {
      EMPTY			= 0,
      SOLID_BLOCK		= 1,
      DESTRUCTIBLE_BLOCK	= 2,
      BOMB_UP_POWER_UP		= 3,
      FIRE_UP_POWER_UP		= 4,
      SPEED_UP_POWER_UP		= 5,
      LIVE_UP_POWER_UP		= 6,
      BASIC_ENEMY		= 7,
      PLAYER_ONE		= 8,
      PLAYER_TWO		= 9
    };

  EntityFactory();
  ~EntityFactory();

  Entity			*createEntity(EntityFactory::EntityType);

  Entity			*createSolidBlock(const unsigned int &x,
						  const unsigned int &y,
						  const unsigned int &rotation);
  Entity			*createDestructibleBlock(const unsigned int &x,
							 const unsigned int &y,
							 const unsigned int &rotation);
  Entity			*createBomb(const unsigned int &x,
					    const unsigned int &y,
					    const unsigned int &rotation,
					    const unsigned int &ownerId,
					    const ExplosiveComponent::Owner &ownerType,
					    const unsigned int &explosionSize);
  Entity			*createExplosion(const unsigned int &x,
						 const unsigned int &y,
						 const unsigned int &rotation);
  Entity			*createPlayer(const unsigned int &x,
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
					      Display *display);
  Entity			*createBasicEnemy(const unsigned int &x,
						 const unsigned int &y);
  Entity			*createPowerUp(const unsigned int &x,
					       const unsigned int &y,
					       PowerUpComponent::Type type);
  Entity			*createPowerUpContainer(const unsigned int &x,
							const unsigned int &y,
							PowerUpComponent::Type containedType);

private:
  unsigned int			_nextFreeId;
};

#endif /* !_ENTITY_FACTORY_HH_ */
