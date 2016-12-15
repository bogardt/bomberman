//
// Main.cpp for cpp_indie_studio in /home/dupard_e/rendus/cpp_indie_studio/source
//
// Made by Erwan Dupard
// Login   <dupard_e@epitech.net>
//
// Started on  Tue May 10 16:01:52 2016 Erwan Dupard
// Last update Wed Jun 22 14:17:34 2016 Thomas Bogard
//

#include "Engine.hh"
#include "Menu.hh"
#include "Resources.hh"

int				main(int argc, char **argv, char **env)
{
  Engine			engine;
  Menu				menu;

  if (env == NULL)
    exit(1);
  else
    menu.startMenu();
  return (RETURN_SUCCESS);
}
