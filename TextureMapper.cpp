//
// Created by cstaheli on 9/11/2016.
//

#include "TextureMapper.h"

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
    draw();
}

void TextureMapper::draw()
{

}

void TextureMapper::read_file(string file_name)
{
    ObjParser parser;
    parser.parse_file(file_name);
    geometric_vertices = parser.geometric_vertices;
    texture_vertices = parser.texture_vertices;
    vertex_normals = parser.vertex_normals;
    faces = parser.faces;
}