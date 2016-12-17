//
// Bomberman
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
