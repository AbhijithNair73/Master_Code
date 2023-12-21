#include <iostream>
#include <functional>
#include <queue>


struct FunctionContainer
{
    std::function<void()> function;

    template <typename Func, typename... Args>
    FunctionContainer(Func func, Args... args)
        : function([func, args...]() { func(args...); }) {
            
            // below if condition is dummy code to check how does it
            // works when zero arg function is passed
            
            if constexpr (sizeof...(args) > 0)
            {
                std::cout<<"Ctor"<<std::endl;
               ((std::cout << args << ", "), ...);
                std::cout<<std::endl;
                
            }
        }
/*    
    // Special case for zero-argument functions
    template <typename Func>
    FunctionContainer(Func func)
        : function([func]() { func(); }) {}
*/

    void execute() const
    {
        function();
    }
};

// Example function
void exampleFunction(int a, double b, const char* c)
{
    std::cout << "Arguments: " << a << ", " << b << ", " << c << std::endl;
}

void print(void)
{
    std::cout<<"Hello from zero Arg function"<<std::endl;
}

void Add(int a, int b, int * c)
{
    *c = a+b;
}

int main()
{
    std::queue<FunctionContainer> workqueue;

    // Create an instance of FunctionContainer
    workqueue.push(FunctionContainer(exampleFunction, 42, 3.14, "John"));
    
    int x = 20;
    int y = 30;
    int z =0;
    int * ptr = &z;
    workqueue.push(FunctionContainer(print));
    workqueue.push(FunctionContainer(Add, x, y, ptr));
    // Execute the stored function with its arguments
    while (!workqueue.empty())
    {
        workqueue.front().execute();
        workqueue.pop();
    }
    std::cout<<"Value of z = "<<z<<std::endl;

    return 0;
}
