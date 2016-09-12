//
// Created by cstaheli on 9/11/2016.
//

#include "TextureMapper.h"
#include <GL/glut.h>

void TextureMapper::init(int argc, char** argv)
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

TextureMapper::TextureMapper(int argc, char** argv)
{
    init(argc, argv);
}

void TextureMapper::draw()
{

}
