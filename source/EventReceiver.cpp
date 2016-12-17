//
// Bomberman
//

#include <iostream>
#include "EventReceiver.hh"

EventReceiver::EventReceiver()
{
  for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
    this->_KeyIsDown[i] = false;
}

bool EventReceiver::OnEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    this->_KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  return false;
}

bool EventReceiver::IsKeyUp(const irr::EKEY_CODE &keyCode) const
{
  return this->_KeyIsUp[keyCode];
}

bool EventReceiver::IsKeyDown(const irr::EKEY_CODE &keyCode) const
{
  return this->_KeyIsDown[keyCode];
}
