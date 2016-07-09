#include <iostream>

using namespace std;

int main()
{
    std::cout << sizeof(size_t) * CHAR_BIT << "-bit app is running." << std::endl;
    return EXIT_SUCCESS;
}