//
// Bomberman
//

#ifndef _CONTAINER_COMPONENT_HH_
# define _CONTAINER_COMPONENT_HH_

# include "PowerUpComponent.hh"

class		ContainerComponent : public Component
{
public:
  ContainerComponent(PowerUpComponent::Type containedType);
  ~ContainerComponent();

  PowerUpComponent::Type		getContainedType();

private:
  PowerUpComponent::Type	_containedType;
};

#endif /* !_CONTAINER_COMPONENT_HH_ */
