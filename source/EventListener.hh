//
// Bomberman
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
