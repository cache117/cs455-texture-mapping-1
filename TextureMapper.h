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
    void read_file(string file_name);
    enum obj_type
    {
        GEOMETRIC_VERTEX,
        TEXTURE_VERTEX,
        VERTEX_NORMAL,
        GROUP_NAME,
        SMOOTHING_GROUP,
        FACE,
        MATERIAL_NAME,
        MATERIAL_LIBRARY
    };
    obj_type get_obj_type(string name);
};

#endif //TEXTURE_MAPPING_TEXTUREMAPPER_H
