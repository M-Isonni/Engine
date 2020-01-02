#pragma once
#include <vector>
#include <memory>

template <class T>
class Event
{
private:
    std::vector<T> functions;

public:
    Event(){};
    ~Event(){};

    void AddListener(T func)
    {
        functions.push_back(func);
    }

    void RemoveListener(T func)
    {
        int len = functions.size();
        for (int i = 0; i < len; i++)
        {
            if (functions[i] == func)
            {
                functions.erase(functions.begin() + i);
                break;
            }
        }
    }

    void ClearListeners()
    {
        functions.clear();
    }

    int GetListenersNum()
    {
        return functions.size();
    }

    void operator--()
    {
        functions.pop_back();
    }

    void operator+=(T func)
    {
        functions.push_back(func);
    }

    void operator-=(T func)
    {
        int len = functions.size();
        for (int i = 0; i < len; i++)
        {
            if (functions[i] == func)
            {
                functions.erase(functions.begin() + i);
                break;
            }
        }
    }

    template <typename... Args>
    void Call(Args... args)
    {
        for (auto f : functions)
        {
            f(args...);
        }
    }
};