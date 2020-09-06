//gcc -o test test.c -lGL -lGLU -lglut
//nvcc -o test test.c -lGL -lGLU -lglut
#include <GL/glut.h>
#include <stdio.h>

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
    GLint available = 0;
    GLuint64 timeElapsed = 0;
    glGenQueries(1, &m_iTimeQuery);
    glBeginQuery(GL_TIME_ELAPSED, m_iTimeQuery);
    //-----------------------------
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0);
    glutWireTeapot(3);

    glFlush();
    //-----------------------------
    glEndQuery(GL_TIME_ELAPSED);
    while(!available){
         glGetQueryObjectiv(m_iTimeQuery, GL_QUERY_RESULT_AVAILABLE, &available);
    }
    glGetQueryObjectui64v(m_iTimeQuery, GL_QUERY_RESULT, &timeElapsed);
    printf("timeEclipsed:%ld\n",timeElapsed);
    //-----------------------------
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


