//
// Bomberman
//

#ifndef _COMPONENT_HH_
# define _COMPONENT_HH_

# include <string>

class						Component
{
public:
  enum ComponentType : unsigned int
  {
    POSITION_COMPONENT			= 0,
      SPEED_COMPONENT				= 1,
      MODEL_COMPONENT				= 2,
      SOLIDITY_COMPONENT			= 3,
      HEALTH_COMPONENT				= 4,
      EXPLOSIVE_COMPONENT			= 5,
      EXPLOSION_COMPONENT			= 6,
      POWER_UP_COMPONENT			= 7,
      PLAYER_INPUT_COMPONENT			= 8,
      BASIC_ENEMY_COMPONENT			= 9,
      CONTAINER_COMPONENT			= 10
      };

  Component(Component::ComponentType type);
  ~Component();
  const Component::ComponentType		&getType() const;
private:
  const Component::ComponentType		_type;
};

#endif /* !_COMPONENT_HH_ */
