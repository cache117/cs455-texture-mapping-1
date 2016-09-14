//
// Created by cstaheli on 9/11/2016.
//
#include <string>
#include <fstream>
#include <GL/glut.h>
#include <sstream>
#include <iostream>
#include <vector>
#include "Vertex.h"
#include "ObjParser.h"

#ifndef TEXTURE_MAPPING_TEXTUREMAPPER_H
#define TEXTURE_MAPPING_TEXTUREMAPPER_H

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

class TextureMapper
{
public:
    void draw();
    TextureMapper(int argc, char **argv);
private:
    void draw_line();
    void init(int argc, char **argv);
    void read_file(string file_name);

    std::vector<GeometricVertex> geometric_vertices;
    std::vector<TextureVertex> texture_vertices;
    std::vector<VertexNormal> vertex_normals;
    std::vector<Face> faces;
};

#endif //TEXTURE_MAPPING_TEXTUREMAPPER_H
