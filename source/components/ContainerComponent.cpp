//
// Bomberman
//

#include "ContainerComponent.hh"

ContainerComponent::ContainerComponent(PowerUpComponent::Type containedType)
  : Component(Component::CONTAINER_COMPONENT),
    _containedType(containedType)
{}

ContainerComponent::~ContainerComponent()
{}

PowerUpComponent::Type	        ContainerComponent::getContainedType()
{
  return (this->_containedType);
}
