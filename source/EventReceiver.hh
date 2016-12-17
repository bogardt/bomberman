//
// Bomberman
//

#ifndef _EVENT_RECEIVER_HH_
# define _EVENT_RECEIVER_HH_

# include	"irrlicht.h"

class		EventReceiver : public irr::IEventReceiver
{
public:
  EventReceiver();

  virtual bool OnEvent(const irr::SEvent& event);
  virtual bool IsKeyUp(const irr::EKEY_CODE &keyCode) const;
  virtual bool IsKeyDown(const irr::EKEY_CODE &keyCode) const;

private:
  bool                          _KeyIsUp[irr::KEY_KEY_CODES_COUNT];
  bool                          _KeyIsDown[irr::KEY_KEY_CODES_COUNT];
};


#endif /* !_EVENT_RECEIVER_HH_ */
