//
// Audio.hh for indie studio
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Thu Jun  2 16:06:03 2016 Thomas Bogard
// Last update Sun Jun  5 16:29:18 2016 Thomas Bogard
//

#ifndef		__AUDIO_HH__
# define	__AUDIO_HH__

# include	<string>
# include	<SFML/Audio.hpp>

class		Audio
{
public:
  Audio();
  ~Audio();
  void		makeSound(const std::string &file);
  void		makeMusic(const std::string &file);

  // music
  void		musicPlay();
  void		musicPause();
  void		musicStop();
  void		musicSetVolume(const unsigned int &volume);
  void		musicSetLoop(const bool isloop);

  // song
  void		soundSetVolume(const unsigned int &volume);
  void		soundSetLoop(const bool isloop);

protected:
  sf::SoundBuffer	_buffer;
  sf::Sound		_sound;
  sf::Music		_music;
};

#endif		// __AUDIO_HH__
