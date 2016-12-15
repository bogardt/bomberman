//
// PowerUpComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue May 24 17:27:27 2016 Barthelemy Gouby
// Last update Wed May 25 12:34:59 2016 Barthelemy Gouby
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
