//
// Bomberman
//

#ifndef _MODEL_COMPONENT_HH_
# define _MODEL_COMPONENT_HH_

# include <string>
# include <vector>
# include "Component.hh"
# include "irrlicht.h"

class				ModelComponent : public Component
{
public:
  enum ModelType : unsigned int
  {
    DEFAULT = 0,
      RUN = 1,
      DROP = 2,
      NUMBER_OF_TYPES = 3
      };

  ModelComponent();
  ModelComponent(const std::string &defaultModel,
		 const std::string &texture,
		 const unsigned int &scale);
  ModelComponent(const std::string &defaultModel,
		 const unsigned int &scale);
  ~ModelComponent();
  void					setModel(const std::string &model, ModelComponent::ModelType);
  const std::string			&getModel(ModelComponent::ModelType type) const;
  void					setTexture(const std::string &texture);
  const std::string			&getTexture() const;
  void					setScale(const unsigned int &scale);
  const unsigned int			&getScale() const;
  const ModelComponent::ModelType	&getSelectedModel() const;
  void					setSelectedModel(ModelComponent::ModelType type);
  const std::vector<std::string>	&getModels() const;
  void					setModels(const std::vector<std::string> &models);
  const unsigned int			&getDurationDrop() const;
  void					setDurationDrop(const unsigned int &duration);
private:
  std::vector<std::string>		_models;
  std::string				_texture;
  unsigned int				_scale;
  ModelComponent::ModelType		_selectedModel;
  unsigned int				_duration;
};

#endif /* !MODEL_COMPONENT */
