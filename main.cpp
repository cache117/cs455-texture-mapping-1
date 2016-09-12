#include <iostream>
#include "TextureMapper.h"

using std::cout;
using std::endl;

int main(int argc, char** argv)
{
    TextureMapper mapper(argc, argv);
    mapper.draw();
    cout << "Hello, World!" << endl;
    return 0;
}