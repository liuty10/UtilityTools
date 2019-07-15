//gcc -o test test.c -lGL -lGLU -lglut
//nvcc -o test test.c -lGL -lGLU -lglut
#include <GL/glut.h>

#ifndef GL_ARB_timer_query
#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28
#endif

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5, 5, -5, 5, 5, 15);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);

    return;
}

void display(void)
{
    //-----------------------------
    GLuint m_iTimeQuery;
    GLuint timeElapsed=0;
    glGenQueries(1, &m_iTimeQuery);
    GLint available = 0;
    glGetQueryObjectiv(m_iTimeQuery, GL_QUERY_RESULT_AVAILABLE, &available);
    if(available){
        glGetQueryObjectuiv(m_iTimeQuery, GL_QUERY_RESULT, &timeElapsed);
        glBeginQuery(GL_TIME_ELAPSED, m_iTimeQuery);
    }
    //-----------------------------
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0);
    glutWireTeapot(3);
    glDrawElementsInstancedEXT(GL_QUADS, 150*4, GL_UNSIGNED_INT, 0, 2);

    //-----------------------------
    if(available)
        glEndQuery(GL_TIME_ELAPSED);
    printf("timeEclipsed:%lf\n",timeElapsed);
    glFlush();
    return;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(300, 300);
    glutCreateWindow("OpenGL 3D View");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}


