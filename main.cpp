#include <GL/glut.h>
#include <iostream>
#include "cubos.h"
#define LARGURA 600
#define ALTURA 600

const int tamanho = 4;
int last_press_x = 0;
int last_press_y = 0;
int i = 1;
int j = 0;
float tmpI;
float tmpJ;
bool swapping = true;
bool trocarPosicoes = false;
bool terminouTroca = false;

double rotationX = 20.0;
double rotationY = 20.0;
Cubos teste[tamanho];

using namespace std;


void Anima(int value)
{
    if(!swapping){
       static bool passo1 = false;
       static bool passo2 = false;
        cout << "Entrou" << endl;
        cout << "TMPI:" << tmpI << endl;
        cout << "TPMJ"  << tmpJ << endl;
        if(teste[i].setZFrente(5) && !passo1){
            cout << teste[i].getZ() << endl;

        }else{
            passo1 = true;
            teste[i].setXEsquerda(tmpJ);

        }

        if(teste[j].setZTras(-5) && !passo2){
        }else{
            passo2 = true;
            teste[j].setXDireita(tmpI);

        }

        if( passo1 && passo2 &&  (teste[i]).setXEsquerda(tmpJ) && teste[j].setXDireita(tmpI) ){
            teste[j].resetZFrente();

        }


        glutPostRedisplay();
        glutTimerFunc(100,Anima,1);
    }

}


void ordenacao()
{
    for (;i < tamanho; i++)
    {
        int atual = teste[i].getData();
        j = i - 1;

        while ((j >= 0) && (atual < teste[j].getData()))
        {
            //Se tiver troca,saia;
            swapping = false;
            //Guarda as posições
            trocarPosicoes = true;
            break;

            //                original[j + 1] = original[j];
            teste[j+1].setData(teste[j].getData());

            j = j - 1;
        }
        //Se tiver troca,saia;
        if(!swapping){

            break;
        }

        //            original[j + 1] = atual;
        teste[j+1].setData(atual);
    }

}



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

    for(int i = 0 ; i < tamanho ; i++){
        teste[i].drawCube();
    }

    //Enquanto não tiver swap,faça;
    if(swapping){
        ordenacao();
    }

    //Guardar as posicoes para trocar
    if(trocarPosicoes){
        tmpI = teste[i].getX();
        tmpJ = teste[j].getX();

        trocarPosicoes = false;
    }


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
    gluPerspective(100.0f,((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 300.0f);

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
    int original[tamanho] = {4,3,2,1};
    teste[0] = Cubos(original[0],tamanho * -5 ,0,0);
    for(int i = 1 ; i < tamanho ; ++i){
        teste[i] = Cubos(original[i],teste[i-1].getX() + 5 ,teste[i-1].getY(),teste[i-1].getZ());
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(LARGURA,ALTURA);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Insert sort");
    glutDisplayFunc(Desenha);
    glutTimerFunc(100, Anima, 1);
    glutMouseFunc(Mouse_Press);
    glutMotionFunc(Mouse_Motion);
    Inicializa();
    CriarMenu();
    glutMainLoop();


}
