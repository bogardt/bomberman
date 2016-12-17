//
// Bomberman
//

#ifndef _POWER_UP_COMPONENT_HH_
# define _POWER_UP_COMPONENT_HH_

# include "Component.hh"

class				PowerUpComponent : public Component
{
public:
  enum Type
    {
      FIRE_UP,
      BOMB_UP,
      SPEED_UP,
      LIVE_UP
    };

  PowerUpComponent(PowerUpComponent::Type type);
  const PowerUpComponent::Type	&getType() const;

private:
  PowerUpComponent::Type	_type;
};

#endif /* !_POWER_UP_COMPONENT_HH_ */
