//
// Created by cstaheli on 9/14/2016.
//

#ifndef TEXTURE_MAPPING_VERTEX_H
#define TEXTURE_MAPPING_VERTEX_H

#include <vector>

struct GeometricVertex
{
    float x, y, z, w;

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

struct TextureVertex
{
    float u, v, w;

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

struct VertexNormal
{
    float i, j, k;

    VertexNormal() : VertexNormal(0, 0, 0)
    {

    }

    VertexNormal(float i, float j, float k) : i(i), j(j), k(k)
    {

    }
};

struct Face
{
    std::vector<int> geometric_vertices, texture_vertices, vertex_normals;

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
