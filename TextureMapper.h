//
// Created by cstaheli on 9/11/2016.
//
#include <string>
#include <fstream>

#ifndef TEXTURE_MAPPING_TEXTUREMAPPER_H
#define TEXTURE_MAPPING_TEXTUREMAPPER_H

using std::string;

class TextureMapper
{
public:
    void draw();
    TextureMapper(int argc, char **argv);
private:
    void draw_line();
    void init(int argc, char **argv);
    string file_name;
};


#endif //TEXTURE_MAPPING_TEXTUREMAPPER_H
