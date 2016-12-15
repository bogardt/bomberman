//
// EventListener.hh for indiStudio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Wed May 18 15:27:32 2016 Barthelemy Gouby
// Last update Wed May 25 14:28:02 2016 Erwan Dupard
//

#ifndef _EVENT_LISTENER_HH_
# define _EVENT_LISTENER_HH_

# include <vector>
# include "irrlicht.h"
# include "EventReceiver.hh"

class				EventListener
{
public:
  EventListener(const std::vector<irr::EKEY_CODE> &keys, const EventReceiver *receiver);
  std::vector<irr::EKEY_CODE>	*getKeysDown();
  
private:
  std::vector<irr::EKEY_CODE>	_keys;
  const EventReceiver		*_receiver;
};

#endif /* !_EVENT_LISTENER_HH_ */
