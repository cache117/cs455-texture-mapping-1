//
// Created by cstaheli on 9/11/2016.
//
#include <GL/glut.h>
#include <string>
#include <fstream>
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

class TextureMapper;

static TextureMapper *currentInstance;

class TextureMapper
{
public:
    TextureMapper(int argc, char **argv);
    void draw();
    void run();
private:
    void init();
    void read_file(string file_name);
    void setupCallback();
    static void drawCallback();

    std::vector<GeometricVertex> geometric_vertices;
    std::vector<TextureVertex> texture_vertices;
    std::vector<VertexNormal> vertex_normals;
    std::vector<Face> faces;
};

#endif //TEXTURE_MAPPING_TEXTUREMAPPER_H
