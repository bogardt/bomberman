//
// Bomberman
//

#include "PowerUpComponent.hh"

PowerUpComponent::PowerUpComponent(PowerUpComponent::Type type)
  : Component(Component::POWER_UP_COMPONENT),
    _type(type)
{}

const PowerUpComponent::Type	&PowerUpComponent::getType() const
{
  return (this->_type);
}
