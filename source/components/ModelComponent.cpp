//
// ModelComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 11:19:20 2016 Barthelemy Gouby
// Last update Fri Jun 10 20:16:48 2016 Thomas Bogard
//

#include "ModelComponent.hh"

ModelComponent::ModelComponent()
  : Component(Component::MODEL_COMPONENT),
    _models(ModelComponent::NUMBER_OF_TYPES),
    _selectedModel(ModelComponent::DEFAULT),
    _duration(10)
{}

ModelComponent::ModelComponent(const std::string &defaultModel,
			       const std::string &texture,
			       const unsigned int &scale)
  : Component(Component::MODEL_COMPONENT),
    _models(ModelComponent::NUMBER_OF_TYPES),
    _texture(texture),
    _scale(scale),
    _selectedModel(ModelComponent::DEFAULT),
    _duration(10)
{
  this->_models[ModelComponent::DEFAULT] = defaultModel;
}

ModelComponent::ModelComponent(const std::string &defaultModel,
			       const unsigned int &scale)
  : Component(Component::MODEL_COMPONENT),
    _models(ModelComponent::NUMBER_OF_TYPES),
    _scale(scale),
    _selectedModel(ModelComponent::DEFAULT),
    _duration(10)
{
  this->_models[ModelComponent::DEFAULT] = defaultModel;
}

ModelComponent::~ModelComponent()
{}

void					ModelComponent::setModel(const std::string &model,
								 ModelComponent::ModelType type)
{
  this->_models[type] = model;
}

const std::string			&ModelComponent::getModel(ModelComponent::ModelType type) const
{
  return (this->_models[type]);
}

void					ModelComponent::setTexture(const std::string &texture)
{
  this->_texture = texture;
}

const std::string			&ModelComponent::getTexture() const
{
  return (this->_texture);
}

void					ModelComponent::setScale(const unsigned int &scale)
{
  this->_scale = scale;
}

const unsigned int			&ModelComponent::getScale() const
{
  return (this->_scale);
}

const ModelComponent::ModelType		&ModelComponent::getSelectedModel() const
{
  return (this->_selectedModel);
}

void					ModelComponent::setSelectedModel(ModelComponent::ModelType type)
{
  this->_selectedModel = type;
}

const std::vector<std::string>		&ModelComponent::getModels() const
{
  return (this->_models);
}

void					ModelComponent::setModels(const std::vector<std::string> &models)
{
  this->_models = models;
}

void					ModelComponent::setDurationDrop(const unsigned int &duration)
{
  this->_duration = duration;
}

const unsigned int			&ModelComponent::getDurationDrop() const
{
  return (this->_duration);
}
