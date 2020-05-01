// modificando primitivas gráficas

#include <iostream>
#include <stdio.h>
#include <string.h>
#include<GLFW/glut.h>
#include<Windows.h>

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex2f ((x1),(y1)); glVertex2f ((x2),(y2)); glEnd();

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT);
    /* seta as linhas para branco  */
    glColor3f(1.0, 1.0, 1.0);

    /* na 1ª fila, 3 linhas, cada uma com um pontilhado diferente  */
    glEnable(GL_LINE_STIPPLE);

    glLineStipple(1, 0x0101);  /*  pontilhada  */
    drawOneLine(50.0, 125.0, 150.0, 125.0);
    glLineStipple(1, 0x00FF);  /*  tracejada  */
    drawOneLine(150.0, 125.0, 250.0, 125.0);
    glLineStipple(1, 0x1C47);  /*  traço / ponto / traço  */
    drawOneLine(250.0, 125.0, 350.0, 125.0);
    /* na 2ª fila, 3 linhas largas, cada uma com pontos diferentes */
    glLineWidth(5.0);
    glLineStipple(1, 0x0101);  /*  pontilhada  */
    drawOneLine(50.0, 100.0, 150.0, 100.0);
    glLineStipple(1, 0x00FF);  /*  dashed  */
    drawOneLine(150.0, 100.0, 250.0, 100.0);
    glLineStipple(1, 0x1C47);  /*  traço / ponto / traço  */
    drawOneLine(250.0, 100.0, 350.0, 100.0);
    glLineWidth(1.0);

    /* na terceira linha, 6 linhas, com traço / ponto / traço pontilhada  */
    /* como parte de uma única tira de linha conectada */
    glLineStipple(1, 0x1C47);  /* traço / ponto / traço  */
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < 7; i++)
        glVertex2f(50.0 + ((GLfloat)i * 50.0), 75.0);
    glEnd();

    /* na 4ª linha, 6 linhas independentes com o mesmo pontilhado  */
    for (i = 0; i < 6; i++) {
        drawOneLine(50.0 + ((GLfloat)i * 50.0), 50.0,
        50.0 + ((GLfloat)(i + 1) * 50.0), 50.0);
    }

    /* na 5ª linha, 1 linha, com pontilhado traço / ponto / traço */
    /* e um fator de repetição pontilhado de 5                */
    glLineStipple(5, 0x1C47);  /*  traço / ponto / traço  */
    drawOneLine(50.0, 25.0, 350.0, 25.0);

    glDisable(GL_LINE_STIPPLE);
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 150);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGl");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}