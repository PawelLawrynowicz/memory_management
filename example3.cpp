#include <iostream>
#include <stdexcept>
#include <memory>

void validateArguments(int argc)
{
    if(argc != 2)
    {
        std::cerr << "You need to pass 1 argument" << std::endl;
        exit(-1);
    }
}

class CustomError: public std::logic_error {
public:
    CustomError(const char *what) : std::logic_error(what) {}
};

class Resource
{
public:
    void use(const char* arg)
    {
        std::cout << "Using resource. Passed " << *arg << std::endl;
        if (*arg == 'd')
        {
            throw CustomError("d does not belong here!");
        }
    }
};

int main(int argc, char* argv[])
{
    validateArguments(argc);

    const char* argument = argv[1];
    std::unique_ptr<Resource> rsc = nullptr;
    try
    {
        rsc = std::make_unique<Resource>();
        rsc->use(argument);
    }
    catch (CustomError& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

