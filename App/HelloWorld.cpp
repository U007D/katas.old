//
// Created by bRad on 7/9/16.
//

#include <iostream>
#include "HelloWorld.h"

HelloWorld::HelloWorld()
{
    std::cout << "Hello, " << sizeof(size_t) * CHAR_BIT << "-bit world!" << std::endl;
}
