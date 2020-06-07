#include <map>
#include <scenes/IScene.h>
#include <string.h>
#include <functional>

typedef std::function<IScene *(void)> SceneFunc;

template <typename Func>
class SceneLibrary
{
public:
    std::map<std::string, Func> map;

    IScene *get(std::string key)
    {
        auto it = map.find(key);

        if (it != map.end())
        {
            return it->second();
        }

        return nullptr;
    }

    void put(std::string key, Func func)
    {
        map.insert({key, func});
    }
};