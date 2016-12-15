//
// ContainerComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Jun  2 22:46:53 2016 Barthelemy Gouby
// Last update Thu Jun  2 23:16:58 2016 Barthelemy Gouby
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
