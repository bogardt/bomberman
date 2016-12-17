//
// Bomberman
//

#include "Engine.hh"
#include "Menu.hh"
#include "Resources.hh"

int				main(int argc, char **argv, char **env)
{
  Engine			engine;
  Menu				menu;

  if (!env)
    exit(1);
  menu.startMenu();
  return (RETURN_SUCCESS);
}
