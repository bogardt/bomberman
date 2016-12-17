//
// Bomberman
//

#include "PlayerInputComponent.hh"

PlayerInputComponent::PlayerInputComponent(const irr::EKEY_CODE &keyUp,
					   const irr::EKEY_CODE &keyDown,
					   const irr::EKEY_CODE &keyLeft,
					   const irr::EKEY_CODE &keyRight,
					   const irr::EKEY_CODE &keyBomb,
					   const unsigned int &maxBombs,
					   const unsigned int &explosionSize,
					   const unsigned int &speed)
  : Component(Component::PLAYER_INPUT_COMPONENT),
    _keyUp(keyUp),
    _keyDown(keyDown),
    _keyLeft(keyLeft),
    _keyRight(keyRight),
    _keyBomb(keyBomb),
    _maxBombs(maxBombs),
    _activeBombs(0),
    _explosionSize(explosionSize),
  _speed(speed)
{}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyUp() const
{
  return (this->_keyUp);
}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyDown() const
{
  return (this->_keyDown);
}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyLeft() const
{
  return (this->_keyLeft);
}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyRight() const
{
  return (this->_keyRight);
}

const irr::EKEY_CODE		&PlayerInputComponent::getKeyBomb() const
{
  return (this->_keyBomb);
}

const unsigned int		&PlayerInputComponent::getMaxBombs() const
{
  return (this->_maxBombs);
}

const unsigned int		&PlayerInputComponent::getActiveBombs() const
{
  return (this->_activeBombs);
}

const unsigned int		&PlayerInputComponent::getExplosionSize() const
{
  return (this->_explosionSize);
}

const unsigned int		&PlayerInputComponent::getSpeed() const
{
  return (this->_speed);
}

void				PlayerInputComponent::setMaxBombs(const unsigned int &maxBombs)
{
  this->_maxBombs = maxBombs;
}

void				PlayerInputComponent::setActiveBombs(const unsigned int &activeBombs)
{
  this->_activeBombs = activeBombs;
}

void				PlayerInputComponent::setExplosionSize(const unsigned int &explosionSize)
{
  this->_explosionSize = explosionSize;
}

void				PlayerInputComponent::setSpeed(const unsigned int &speed)
{
  this->_speed = speed;
}

void				PlayerInputComponent::incrementActiveBombs()
{
  this->_activeBombs++;
}

void				PlayerInputComponent::decrementActiveBombs()
{
  this->_activeBombs--;
}
