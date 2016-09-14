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
}

void TextureMapper::draw()
{

}

void TextureMapper::read_file(string file_name)
{
    ifstream file;
    file.open(file_name);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            std::stringstream ss(line);
            string token;
            ss >> token;
            handle_obj_type(get_obj_type(token), ss);
        }
        file.close();
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
    else if (name == "#")
        return COMMENT;
    else
        return OTHER;
}

void TextureMapper::handle_obj_type(obj_type type, std::stringstream &ss)
{
    switch (type)
    {
        case GEOMETRIC_VERTEX:
            handle_geometric_vertex(ss);
            break;
        case TEXTURE_VERTEX:
            handle_texture_vertex(ss);
            break;
        case VERTEX_NORMAL:
            handle_vertex_normal(ss);
            break;
        case FACE:
            handle_face(ss);
            break;
        default:
            break;
    }
}

void TextureMapper::handle_geometric_vertex(std::stringstream &ss)
{
    //v x y z w
    float x = 0, y = 0, z = 0;
    ss >> x >> y >> z;
    geometric_vertices.push_back(GeometricVertex(x, y, z));
}

void TextureMapper::handle_texture_vertex(std::stringstream &ss)
{
    //vt u v w
    float u = 0, v = 0;
    ss >> u >> v;
    texture_vertices.push_back(TextureVertex(u, v));
}

void TextureMapper::handle_vertex_normal(std::stringstream &ss)
{
    //vn i j k
    float i = 0, j = 0, k = 0;
    ss >> i >> j >> k;
    vertex_normals.push_back(VertexNormal(i, j, k));
}

void TextureMapper::handle_face(std::stringstream &ss)
{
    //f  v1/vt1/vn1   v2/vt2/vn2   v3/vt3/vn3 . . .
    string face_str;
    ss >> face_str;
    Face face;
    while (!ss.eof())
    {
        int v, vt, vn;
        sscanf(face_str.c_str(), "%d/%d/%d", &v, &vt, &vn);
        face.add(v, vt, vn);
        ss >> face_str;
    }
    faces.push_back(face);
}
