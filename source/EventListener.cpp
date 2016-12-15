//
// EventListener.cpp for indieStudio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 18 15:28:59 2016 Barthelemy Gouby
// Last update Fri Jun  3 16:39:50 2016 Barthelemy Gouby
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

