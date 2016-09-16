//
// Created by cstaheli on 9/14/2016.
//

#ifndef TEXTURE_MAPPING_OBJPARSER_H
#define TEXTURE_MAPPING_OBJPARSER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "Vertex.h"

using std::string;
using std::ifstream;

class ObjParser
{
public:
    void parse_file(string file_name);
    enum obj_type
    {
        GEOMETRIC_VERTEX,
        TEXTURE_VERTEX,
        VERTEX_NORMAL,
        GROUP_NAME,
        SMOOTHING_GROUP,
        FACE,
        MATERIAL_NAME,
        MATERIAL_LIBRARY,
        COMMENT,
        OTHER
    };
    obj_type get_obj_type(string name);
    void handle_obj_type(obj_type type, std::stringstream &ss);
    void handle_geometric_vertex(std::stringstream &ss);
    void handle_texture_vertex(std::stringstream &ss);
    void handle_vertex_normal(std::stringstream &ss);
    void handle_face(std::stringstream &ss);
    void compare_vertex_coords(float x, float y, float z);

    std::vector<GeometricVertex> geometric_vertices;
    std::vector<TextureVertex> texture_vertices;
    std::vector<VertexNormal> vertex_normals;
    std::vector<Face> faces;
    float min_x_coord, max_x_coord, min_y_coord, max_y_coord, min_z_coord, max_z_coord;
};


#endif //TEXTURE_MAPPING_OBJPARSER_H
