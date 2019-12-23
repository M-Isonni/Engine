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

    void AddListener(T listener)
    {
        functions.push_back(listener);
    }
    template<typename... Args>
    void Call(Args... args)
    {
        for(auto f : functions)
        {
            f(args...);
        }
    }  
};