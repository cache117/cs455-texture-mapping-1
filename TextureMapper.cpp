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
    min_x_coord = parser.min_x_coord;
    max_x_coord = parser.max_x_coord;
    min_y_coord = parser.min_y_coord;
    max_y_coord = parser.max_y_coord;
    min_z_coord = parser.min_z_coord;
    max_z_coord = parser.max_z_coord;
}

void TextureMapper::init()
{
    /*  select clearing (background) color */
    glClearColor(0.0, 0.0, 0.0, 0.0);

    /*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glViewport(0,0, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    //glFrustum(-2, 2, -2, 3, -2, 2);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

TextureMapper::TextureMapper(int argc, char **argv)
{
    /* Build the data */
    read_file(argv[1]);

    /* Setup GL */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Texture Mapper");
    init();
}

void TextureMapper::draw()
{
    glEnable(GL_TEXTURE_2D);
    /* Clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);

    /* loop through faces, and build the vertices */
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);

    /*glVertex3f(0.25, 0.25, 0.0);
    glVertex3f(0.75, 0.25, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glVertex3f(0.25, 0.75, 0.0);*/
    for (Face face : faces)
    {
        draw_face(face);
    }
    glEnd();

    /* Execute all commands */
    glFlush();
    glDisable(GL_TEXTURE_2D);
}

void TextureMapper::init_texturing()
{
    glBindTexture(GL_TEXTURE_2D, 1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_BLEND);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1024, 1024, 0, GL_RGB, GL_FLOAT, nullptr); //TODO nullptr is a bad idea here
}

void TextureMapper::draw_face(Face face)
{
    for (Vertex vertex: face.get_vertices())
    {
        GeometricVertex geometricVertex = get_geometric_vertex(vertex.v);
        TextureVertex texture = get_texture_vertex(vertex.vt);
        glTexCoord2f(texture.getU(), texture.getV());
        glVertex3f(geometricVertex.getX(), geometricVertex.getY(), geometricVertex.getZ());
    }
}

void TextureMapper::run()
{
    setup_callback();
    glutMainLoop();
}

void TextureMapper::setup_callback()
{
    currentInstance = this;
    ::glutDisplayFunc(TextureMapper::draw_callback);
    ::glutKeyboardFunc(TextureMapper::process_key_press);
}

/* Static gl callback method */
void TextureMapper::draw_callback()
{
    currentInstance->draw();
}

void TextureMapper::process_key_press(unsigned char key, int x, int y)
{
    if (key == 'q')
    {
        glRotatef(15, 0, 1, 0);
    }
    currentInstance->render_movement();
}

void TextureMapper::render_movement()
{

}

void TextureMapper::set_image(string file_name)
{

}
