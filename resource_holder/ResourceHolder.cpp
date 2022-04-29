#include "ResourceHolder.h"

template<>
Resources::ResourceHolder<std::string, sf::Texture>::MapType Resources::ResourceHolder<std::string, sf::Texture>::mResources{};

template<>
Resources::ResourceHolder<std::string, sf::Font>::MapType Resources::ResourceHolder<std::string, sf::Font>::mResources{};
