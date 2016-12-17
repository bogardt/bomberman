//
// Bomberman
//

#include <iostream>
#include "EventListener.hh"


EventListener::EventListener(const std::vector<irr::EKEY_CODE> &keys, const EventReceiver *receiver)
  :  _keys(keys), _receiver(receiver)
{}

std::vector<irr::EKEY_CODE>	*EventListener::getKeysDown()
{
  std::vector<irr::EKEY_CODE> *keysDown = new std::vector<irr::EKEY_CODE>;

  for (irr::EKEY_CODE key : _keys)
    {
      if (this->_receiver->IsKeyDown(key))
	keysDown->push_back(key);
    }
  return (keysDown);
}
