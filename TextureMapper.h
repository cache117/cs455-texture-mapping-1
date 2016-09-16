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
    void run();
private:
    void init();
    void read_file(string file_name);
    void set_image(string file_name);
    void draw();
    void render_movement();
    void draw_face(Face face);
    void setup_callback();
    static void draw_callback();
    static void process_key_press(unsigned char key, int x, int y);
    static void init_texturing();

    GeometricVertex get_geometric_vertex(int index)
    {
        return geometric_vertices[index];
    }

    TextureVertex get_texture_vertex(int index)
    {
        return texture_vertices[index];
    }

    VertexNormal get_vertex_normal(int index)
    {
        return vertex_normals[index];
    }

    std::vector<GeometricVertex> geometric_vertices;
    std::vector<TextureVertex> texture_vertices;
    std::vector<VertexNormal> vertex_normals;
    std::vector<Face> faces;
    float min_x_coord, max_x_coord, min_y_coord, max_y_coord, min_z_coord, max_z_coord;
    float rotation;

    const int DISPLAY_WIDTH = 300;
    const int DISPLAY_HEIGHT = 300;
    const float ASPECT = (DISPLAY_WIDTH / DISPLAY_HEIGHT);
    const float UNIT = 1.0f;
    const float FOVY = 60;
    const float CLIPPING = FOVY / (float) 2.0;
    const float Z_NEAR = 1, Z_FAR = 50;

};

#endif //TEXTURE_MAPPING_TEXTUREMAPPER_H
