//
// Created by cstaheli on 9/11/2016.
//

#include "TextureMapper.h"
#include <GL/glut.h>
#include <sstream>
#include <iostream>

using std::ifstream;
using std::string;

void TextureMapper::init(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 500);
    glutCreateWindow("Texture Mapper");
}

void TextureMapper::draw_line()
{

}

TextureMapper::TextureMapper(int argc, char **argv)
{
    init(argc, argv);
    read_file(argv[1]);
}

void TextureMapper::draw()
{

}

void TextureMapper::read_file(string file_name)
{
    ifstream file(file_name);
    string line;
    if (file)
    {
        while (file >> line)
        {
            std::stringstream ss(line);
            string token;
            ss >> token;
            switch (get_obj_type(token))
            {
                case GEOMETRIC_VERTEX:
                    break;
                case TEXTURE_VERTEX:
                    break;
                case VERTEX_NORMAL:
                    break;
                case GROUP_NAME:
                    break;
                case SMOOTHING_GROUP:
                    break;
                case FACE:
                    break;
                case MATERIAL_NAME:
                    break;
                case MATERIAL_LIBRARY:
                    break;
            }
        }
    }
    else
        std::cerr << "Couldn't open " << file_name << " for reading\n";
}

TextureMapper::obj_type TextureMapper::get_obj_type(string name)
{
    if (name == "v")
        return GEOMETRIC_VERTEX;
    else if (name == "vt")
        return TEXTURE_VERTEX;
    else if (name == "vn")
        return VERTEX_NORMAL;
    else if (name == "g")
        return GROUP_NAME;
    else if (name == "s")
        return SMOOTHING_GROUP;
    else if (name == "f")
        return FACE;
    else if (name == "usemtl")
        return MATERIAL_NAME;
    else if (name == "mtllib")
        return MATERIAL_LIBRARY;
    else
        throw "Not a valid obj type";
}
