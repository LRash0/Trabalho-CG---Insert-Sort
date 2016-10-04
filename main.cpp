#include <GL/glut.h>
#include <iostream>
#include "cubos.h"
#define LARGURA 600
#define ALTURA 600

//Criar vetor parelelo para ordenar e depois desenhar
//Tentar fazer tudo na função Desenha()

const int tamanho = 4;
int original[tamanho] = {4,3,2,1};
int pInicial[tamanho][tamanho];
int pFinal[tamanho][tamanho];
//int original[tamanho] = {6,5,3,1,8,7,2,4};
int last_press_x = 0;
int last_press_y = 0;
int i = 1;
int j = 0;
int mi = 1;
int bj = tamanho - 1;
int pi;
int pj;

float tmpI;
float tmpJ;

bool swapping = true;
bool trocarValores = false;
bool teveTroca = false;
bool trocarPosicoes = false;
bool terminouTroca = true;
bool resetouZ = false;
bool passo1 = false;
bool passo2 = false;

double rotationX = 20.0;
double rotationY = 20.0;

Cubos teste[tamanho];


using namespace std;


void parametrosIluminacao()
{
    /* Parâmetros para a Luz GL_LIGHT0 sendo uma fonte de Luz Pontual */
    GLfloat luzAmbiente[4]={0.0, 0.0, 1.0, 1.0};	/* cor azul */
    GLfloat luzDifusa[4]={1.0, 1.0, 1.0, 1.0};	  	/* cor branca */
    GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0}; 	/* cor branca - brilho */
    GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};	/* Fonte de Luz Pontual */

    /* Define os parâmetros da luz de número 0 (Luz Pontual) */
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    /* Ativa o uso de uma fonte de luz ambiente */
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    /* Características do material */
    GLfloat ka[4]={0.11, 0.06, 0.11, 1.0};		/* Reflete porcentagens da cor ambiente */
    GLfloat kd[4]={0.4, 0.4, 0.7, 1.0};		/* Reflete porcentagens da cor difusa */
    GLfloat ks[4]={1.0, 1.0, 1.0, 1.0};		/* Reflete porcentagens da cor especular */
    GLfloat shininess = 60.0;

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ka);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, kd);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, ks); /* Refletância do material */
    glMaterialf(GL_FRONT, GL_SHININESS, shininess);   /* Concentração do brilho */
}



void Anima(int value)
{
    if(!terminouTroca) {

        if(teste[pi].setZFrente(5) && !passo1){

        }else{
            passo1 = true;
            teste[pi].setXEsquerda(tmpJ);

        }

        if(teste[pj].setZTras(-5) && !passo2){
        }else{
            passo2 = true;
            teste[pj].setXDireita(tmpI);

        }

        if( passo1 && passo2 &&  (teste[pi]).setXEsquerda(tmpJ) && teste[pj].setXDireita(tmpI) ){
            terminouTroca = true;
            resetouZ = true;
        }
    }


    if(resetouZ){
        teste[pj].resetZFrente();
        teste[pi].resetZTras();

        if(teste[pi].getZ() ==0 && teste[pj].getZ() == 0){
            resetouZ = false;
            trocarValores = true;
        }
    }


    glutPostRedisplay();
    glutTimerFunc(100,Anima,1);

}


void ordenacao()
{
    for (i = 1; i < tamanho; i++)
    {
        int atual = original[i];
        j = i - 1;

        while ((j >= 0) && (atual < original[j]))
        {

            pInicial[i][j] = j + 1;
            pFinal[i][j] =  j;



            original[j + 1] = original[j];
            j = j - 1;
        }

        original[j + 1] = atual;
    }

    if(i==tamanho){

        swapping = false;

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


    parametrosIluminacao();

    glRotatef(rotationY, 1.0, 0.0, 0.0);
    glRotatef(rotationX, 0.0, 1.0, 0.0);

    for(int y = 0 ; y < tamanho ; y++){
        teste[y].drawCube();
    }

    //Enquanto não tiver swap,faça;
    if(swapping){
        ordenacao();
        trocarPosicoes = true;
    }

    //Guardar as posicoes para trocar

    if(trocarPosicoes) {

        if(mi < tamanho){

            if(bj>-1) {

                if(pInicial[mi][bj]!=-1 && pFinal[mi][bj]!=-1){

                    pi = pInicial[mi][bj];
                    pj = pFinal[mi][bj];
                    tmpI = teste[pi].getX();
                    tmpJ = teste[pj].getX();

                    trocarPosicoes = false;
                    terminouTroca = false;

                }
            }

            if(bj!=-1){

                bj--;

            }

            if(bj==-1){

                mi++;

                bj = tamanho - 1;
            }
       }

    } else{

    }

    if(terminouTroca && trocarValores) {

        float tmpX = teste[pj].getX();
        float tmpY = teste[pj].getY();
        float tmpZ = teste[pj].getZ();

        teste[pj].setX(teste[pi].getX());
        teste[pj].setY(teste[pi].getY());
        teste[pj].setZ(teste[pi].getZ());

        teste[pi].setX(tmpX);
        teste[pi].setY(tmpY);
        teste[pi].setZ(tmpZ);

        int tmp = teste[pj].getData();
        teste[pj].setData(teste[pi].getData());
        teste[pi].setData(tmp);



        teveTroca = false;
        trocarPosicoes = true;
        trocarValores = false;
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
    gluPerspective(100.0f,((GLfloat)LARGURA/(GLfloat)ALTURA), 1, 600.0f);

    /* Habilita o uso de iluminação */
    glEnable(GL_LIGHTING);
    /* Habilita a luz de número 0 */
    glEnable(GL_LIGHT0);
    /* Habilita o depth-buffering para remoção de faces escondidas */
    glEnable(GL_DEPTH_TEST);

    /* Modelos de Iluminação Defaut */
    glShadeModel(GL_SMOOTH); 		/* Gouraud */

}

void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
        case 'R':
        case 'r':/* Exibi os números na tela */
        for(int l = 0 ; l < tamanho ; l++){
            teste[l].escreve = true;
        }
            break;

        case 'P':
        case 'p':/*Pausa o programa*/
            cout << "Aperter enter para continuar" << endl;
            getchar();
            break;

        case 'B':
        case 'b':/*Esconde os números da tela*/
            for(int l = 0 ; l < tamanho ; l++){
                teste[l].escreve = false;
            }
            break;

        case 'q': /*Sai do programa*/
            exit(1);
            break;
    }

    /* Necessário chamar toda vez que se faz uma alteração ou evento na janela
     * Indica a funcao glutMainLoop a chamar glutDisplayFunc com as alterações */
    glutPostRedisplay();
}



int main(int argc, char *argv[])
{

    teste[0] = Cubos(original[0],tamanho * -5 ,0,0);
    for(int k = 1 ; k < tamanho ; ++k){
        teste[k] = Cubos(original[k],teste[k-1].getX() + 5 ,teste[k-1].getY(),teste[k-1].getZ());
    }

    //Inicializando vetor auxiliar

    for(int i = 0 ; i < tamanho ; i++){
        for(int j = 0 ; j < tamanho ; j++){
            pInicial[i][j] = -1;
            pFinal[i][j] = -1;
        }
    }

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(LARGURA,ALTURA);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Insert sort");
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(GerenciaTeclado);
    glutTimerFunc(100, Anima, 1);
    glutMouseFunc(Mouse_Press);
    glutMotionFunc(Mouse_Motion);
    Inicializa();
    CriarMenu();
    glutMainLoop();


}
