//
// ExplosiveComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 11:26:56 2016 Barthelemy Gouby
// Last update Wed May 25 12:04:28 2016 Barthelemy Gouby
//

#include "ExplosiveComponent.hh"

ExplosiveComponent::ExplosiveComponent(const unsigned int &timerLength,
				       const unsigned int &explosionSize,
				       const unsigned int &ownerId,
				       ExplosiveComponent::Owner ownerType)
  : Component(Component::EXPLOSIVE_COMPONENT),
    _timerLength(timerLength),
    _explosionSize(explosionSize),
    _ownerId(ownerId),
    _ownerType(ownerType)
{}

const unsigned int		&ExplosiveComponent::getTimerLength() const
{
  return (this->_timerLength);
}

const unsigned int		&ExplosiveComponent::getExplosionSize() const
{
  return (this->_explosionSize);
}

const unsigned int		&ExplosiveComponent::getOwnerId() const
{
  return (this->_ownerId);
}

const ExplosiveComponent::Owner	&ExplosiveComponent::getOwnerType() const
{
  return (this->_ownerType);
}

void				ExplosiveComponent::setTimerLength(const unsigned int &newLength)
{
  this->_timerLength = newLength;
}
