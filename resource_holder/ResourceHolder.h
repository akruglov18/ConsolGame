#pragma once

#include <map>
#include <string>

template<typename ResourceType, typename KeyType>
class ResourceHolder {
    using MapType = std::map<KeyType, std::shared_ptr<ResourceType>>;
private:
    MapType mResources;
public:
    std::shared_ptr<ResourceType> loadFromFile(const std::string& fileName, const KeyType& key) {
        std::shared_ptr<ResourceType>& resourceRef = mResources[key];
        if (resourceRef != nullptr) {
            return resourceRef;
        }
        resourceRef = std::make_shared<ResourceType>(*(new ResourceType()));
        if (!resourceRef->loadFromFile(fileName)) {
            resourceRef = nullptr;
        }
        return resourceRef;
    }

    std::shared_ptr<ResourceType> getResource(const KeyType& key)
    {
        typename MapType::iterator resourcePairIt = mResources.find(key);
        if (resourcePairIt == mResources.end()) {
            return nullptr;
        }
        return resourcePairIt->second;
    }

    ResourceHolder() = default;
    ResourceHolder(const ResourceHolder&) = delete;
    ResourceHolder(ResourceHolder&&) = delete;
    ResourceHolder& operator=(const ResourceHolder&) = delete;
    ResourceHolder& operator=(ResourceHolder&&) = delete;

};

template<typename ResourceType, typename KeyType>
ResourceHolder<ResourceType, KeyType>& getGlobalResourceHolder()
{
    static ResourceHolder<ResourceType, KeyType> holder;
    return holder;
}

