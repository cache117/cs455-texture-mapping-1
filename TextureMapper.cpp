//
// Created by cstaheli on 9/11/2016.
//

#include "TextureMapper.h"

void TextureMapper::read_file(string file_name)
{
    ObjParser parser;
    parser.parse_file(file_name);
    geometric_vertices = parser.geometric_vertices;
    texture_vertices = parser.texture_vertices;
    vertex_normals = parser.vertex_normals;
    faces = parser.faces;
}

void TextureMapper::init()
{
    /*  select clearing (background) color       */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

TextureMapper::TextureMapper(int argc, char **argv)
{
    /* Build the data */
    read_file(argv[1]);

    /* Setup GL */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Texture Mapper");
    init();
}

void TextureMapper::draw()
{
    /* Clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);

    /* loop through faces, and build the vertices */
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    /*for (Face face : faces)
    {*/
    glVertex3f (0.25, 0.25, 0.0);
    glVertex3f (0.75, 0.25, 0.0);
    glVertex3f (0.75, 0.75, 0.0);
    glVertex3f (0.25, 0.75, 0.0);

    /*}*/
    glEnd();

    /* Execute all commands */
    glFlush();
}

void TextureMapper::run()
{
    setupCallback();
}

void TextureMapper::setupCallback()
{
    currentInstance = this;
    ::glutDisplayFunc(TextureMapper::drawCallback);
    glutMainLoop();
}

void TextureMapper::drawCallback()
{
    currentInstance->draw();
}
