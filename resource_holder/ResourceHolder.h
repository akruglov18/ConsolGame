#pragma once

#include <map>
#include <string>

template<typename ResourceType, typename KeyType>
class ResourceHolder
{
    using MapType = std::map<KeyType, ResourceType*>;
private:
    MapType mResources;
public:
    // Don't know what for is there "Args&&... args", but let it be
    template<typename ... Args>
    ResourceType* loadFromFile(const std::string& fileName, const KeyType& key, Args &&... args)
    {
        ResourceType*& resourceRef = mResources[key];
        if (resourceRef != nullptr) {
            return resourceRef;
        }
        resourceRef = new ResourceType();
        if (!resourceRef->loadFromFile(fileName, std::forward<Args>(args)...)) {
            delete resourceRef;
            resourceRef = nullptr;
        }
        return resourceRef;
    }

    ResourceType* getResource(const KeyType& key)
    {
        typename MapType::iterator resourcePairIt = mResources.find(key);
        if (resourcePairIt == mResources.end()) {
            return nullptr;
        }
        return resourcePairIt->second;
    }

    ~ResourceHolder()
    {
        for (auto& e : mResources) {
            delete e.second;
        }
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

