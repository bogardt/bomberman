//
// ContainerComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Thu Jun  2 22:50:54 2016 Barthelemy Gouby
// Last update Thu Jun  2 23:18:33 2016 Barthelemy Gouby
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
