//
// Created by cstaheli on 9/14/2016.
//

#ifndef TEXTURE_MAPPING_VERTEX_H
#define TEXTURE_MAPPING_VERTEX_H

#include <vector>

class GeometricVertex
{
    float x, y, z, w;
public:
    GeometricVertex() : GeometricVertex(0, 0, 0, 1)
    {

    }

    GeometricVertex(float x, float y, float z) : GeometricVertex(x, y, z, 1)
    {

    }

    GeometricVertex(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
    {

    }
};

class TextureVertex
{
    float u, v, w;
public:
    TextureVertex() : TextureVertex(0, 0, 0)
    {

    }

    TextureVertex(float u) : TextureVertex(u, 0, 0)
    {

    }

    TextureVertex(float u, float v) : TextureVertex(u, v, 0)
    {

    }

    TextureVertex(float u, float v, float w) : u(u), v(v), w(w)
    {

    }
};

class VertexNormal
{
    float i, j, k;
public:
    VertexNormal() : VertexNormal(0, 0, 0)
    {

    }

    VertexNormal(float i, float j, float k) : i(i), j(j), k(k)
    {

    }
};

class Face
{
    std::vector<int> geometric_vertices, texture_vertices, vertex_normals;
public:
    Face()
    {

    }

    void add(int v, int vt, int vn)
    {
        geometric_vertices.push_back(v);
        texture_vertices.push_back(vt);
        vertex_normals.push_back(vn);
    }
};

#endif //TEXTURE_MAPPING_VERTEX_H
