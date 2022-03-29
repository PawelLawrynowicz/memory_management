#include <cstdio>
#include <memory>
#include <string>

using ShoppingList = std::shared_ptr<std::FILE>;

ShoppingList makeFile(const char* filename, const char* flags)
{
    std::FILE *const file = std::fopen(filename, flags);
    return file ? std::shared_ptr<std::FILE>(file, std::fclose) : std::shared_ptr<std::FILE>();
}

class Partner
{
public:
    void addToFile(std::string element)
    {
        fprintf(shoppingList.get(), "%s\n", element.c_str());
    }
    ShoppingList shoppingList;
};

int main()
{
    Partner boy{};
    boy.shoppingList = makeFile("ShoppingList.txt", "wb");

    Partner girl{};
    girl.shoppingList = boy.shoppingList;
    girl.addToFile("Butter");
    girl.addToFile("Milk");
}
