#include <GL/glut.h>
#include "cubos.h"
#define LARGURA 600
#define ALTURA 600


int last_press_x = 0;
int last_press_y = 0;

double rotationX = 20.0;
double rotationY = 20.0;


using namespace std;

void Desenha(void)
{
    //Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0.0,0.0,30.0,
              0.0,0.0,0.0,
              0.0,0.1,0.0);

    glRotatef(rotationY, 1.0, 0.0, 0.0);
    glRotatef(rotationX, 0.0, 1.0, 0.0);
    Cubos *cube = new Cubos(6);
    cube->inicializarCubos();

    //    glutSolidCube(1)
    glFlush();


}

void Mouse_Motion(int x,int y)
{
    rotationX += (double)(x - last_press_x);
    rotationY += (double)(y - last_press_y);

    last_press_x = x;
    last_press_y = y;

    glutPostRedisplay();


}

void Mouse_Press(int button, int state, int x,int y)
{
    if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        last_press_x = x;
        last_press_y = y;
    }
}

void Janela(int opcao)
{
    switch(opcao){
        case 0:

            glShadeModel(GL_FLAT); //Modelo Flat
            break;

        case 1:
            glShadeModel(GL_SMOOTH); //Modelo Gouraud
    }

    glutPostRedisplay();
}

void CriarMenu()
{
    //Cria um menu cujas as opções serão gerenciadas pela funcao "Janela"
    glutCreateMenu(Janela);

    //Cria entradas nesse menu
    glutAddMenuEntry("Modelo FLAT",0);
    glutAddMenuEntry("Modelo Gouraud",1);

    //Indica qual o botao iniciara o menu
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void Inicializa(void)
{
    //Define a cor de fundo da janela como branca
    glClearColor(1.0f,1.0f,1.0f,1.0f);

    //Modo de projecao ortogonal
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0f,((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 600.0f);

    /* Habilita o uso de iluminação */
    glEnable(GL_LIGHTING);
    /* Habilita a luz de número 0 */
    glEnable(GL_LIGHT0);
    /* Habilita o depth-buffering para remoção de faces escondidas */
    glEnable(GL_DEPTH_TEST);

    /* Modelos de Iluminação Defaut */
    glShadeModel(GL_SMOOTH); 		/* Gouraud */

}

int main(int argc, char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(LARGURA,ALTURA);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Insert sort");
    glutDisplayFunc(Desenha);
    glutMouseFunc(Mouse_Press);
    glutMotionFunc(Mouse_Motion);
    Inicializa();
    CriarMenu();
    glutMainLoop();


}
