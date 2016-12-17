//
// Bomberman
//

#include "Component.hh"

#ifndef _PLAYER_INPUT_COMPONENT_HH_
# define _PLAYER_INPUT_COMPONENT_HH_

# include "IEventReceiver.h"

class			PlayerInputComponent : public Component
{
public:
  PlayerInputComponent(const irr::EKEY_CODE &keyUp,
		       const irr::EKEY_CODE &keyDown,
		       const irr::EKEY_CODE &keyLeft,
		       const irr::EKEY_CODE &keyRight,
		       const irr::EKEY_CODE &keyBomb,
		       const unsigned int &maxBombs,
		       const unsigned int &explosionSize,
		       const unsigned int &speed);
  const irr::EKEY_CODE		&getKeyUp() const;
  const irr::EKEY_CODE		&getKeyDown() const;
  const irr::EKEY_CODE		&getKeyLeft() const;
  const irr::EKEY_CODE		&getKeyRight() const;
  const irr::EKEY_CODE		&getKeyBomb() const;
  const unsigned int		&getMaxBombs() const;
  const unsigned int		&getActiveBombs() const;
  const unsigned int		&getExplosionSize() const;
  const unsigned int		&getSpeed() const;
  void				setMaxBombs(const unsigned int &maxBombs);
  void				setActiveBombs(const unsigned int &activeBombs);
  void				setExplosionSize(const unsigned int &explosionSize);
  void				setSpeed(const unsigned int &speed);
  void				incrementActiveBombs();
  void			        decrementActiveBombs();
private:
  irr::EKEY_CODE	_keyUp;
  irr::EKEY_CODE	_keyDown;
  irr::EKEY_CODE	_keyLeft;
  irr::EKEY_CODE	_keyRight;
  irr::EKEY_CODE	_keyBomb;
  unsigned int		_maxBombs;
  unsigned int		_activeBombs;
  unsigned int		_explosionSize;
  unsigned int		_speed;
};

#endif /* !_PLAYER_INPUT_COMPONENT_HH_ */
