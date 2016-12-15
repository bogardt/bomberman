//
// Menu.hh for indie studio
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Sun Jun  5 15:47:40 2016 Thomas Bogard
// Last update Mon Jun 13 17:47:57 2016 Thomas Bogard
//

#ifndef _MENU_HH_
# define _MENU_HH_

# include <vector>
# include <iostream>
# include "driverChoice.h"
# include "irrlicht.h"
# include "IGUIImage.h"
# include "Engine.hh"

# define BUTTON_WIDTH	(280)
# define BUTTON_HEIGHT	(92)
# define BUTTON_SPACING (10)

# define SCROLL_WIDTH	(271)
# define SCROLL_HEIGHT	(43)
# define SCROLL_SPACING (20)

enum    menuContext
  {
    BASE,
    NEWGAME,
    SOLO,
    MULTI,
    IN_GAME
  };

class Menu
{
public:
  Menu();
  ~Menu();

  void					startMenu();
  void					clearGui();
  void					setSkinTransparency(irr::s32 alpha, irr::gui::IGUISkin * skin);

private:
  void					setTimer();
  void				        doButtonsActions();
  void					drawMenu();
  void					init();
  void					initButtons();

private:
  //game engine
  Engine				_engine;

  //serialization
  EntityManager				_entityManager;

  //device
  irr::video::IVideoDriver		*_driver;
  irr::IrrlichtDevice			*_device;
  irr::scene::ISceneManager		*_sceneManager;
  irr::video::ITexture			*_background;
  irr::gui::IGUIImage			*_img_music;
  irr::gui::IGUIListBox			*_listbox;
  irr::gui::IGUIEnvironment		*_gui;
  EventReceiver				_receiver;
  int					_timer;
  bool					_isPress;

  //responsive
  irr::core::dimension2d<irr::u32>	_screenSize;
  bool					_fileDialogOpen;
  bool					_fileIsSelected;
  bool					_textIsEntered;

  //boutons
  irr::gui::IGUIButton			*_first;
  irr::gui::IGUIButton			*_second;
  irr::gui::IGUIButton			*_third;
  irr::gui::IGUIButton			*_fourth;
  irr::gui::IGUIFileOpenDialog		*_fileDialog;
  irr::gui::IGUIEditBox			*_editBox;
  irr::gui::IGUIScrollBar		*_scrollMusic;
  irr::gui::IGUIScrollBar		*_scrollSound;
  bool					_isSet;
  bool					_menuIsOn;
  menuContext				_menuContext;
};

#endif /* MENU_HH_ */
