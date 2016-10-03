#include <GL/glut.h>
#include <iostream>
#include "cubos.h"
#define LARGURA 600
#define ALTURA 600

//Criar vetor parelelo para ordenar e depois desenhar
//Tentar fazer tudo na função Desenha()

const int tamanho = 8;
//int original[tamanho] = {4,3,2,1};
int pInicial[tamanho][tamanho];
int pFinal[tamanho][tamanho];
int original[tamanho] = {6,5,3,1,8,7,2,4};
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


void Anima(int value)
{
    if(!terminouTroca) {

//        cout << "Entrou" << endl;
//        cout << "TMPI:" << tmpI << endl;
//        cout << "TPMJ"  << tmpJ << endl;


        if(teste[pi].setZFrente(5) && !passo1){
//            cout << "Flag 1" << endl;
            cout << teste[pi].getZ() << endl;
//            getchar();
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
            cout << teste[pi].getZ() << endl;


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
/* for (;i < tamanho; i++)
    while(i<tamanho)
    {

        int atual = teste[i].getData();
        j = i - 1;

        while ((j >= 0) && (atual < teste[j].getData()))
        {
            //Se tiver troca,saia;
            swapping = false;
            //Guarda as posições
            trocarPosicoes = true;
            if(!swapping && trocarPosicoes){
                cout << "Entrou aqui com valor de i = " << i << endl;
                teveTroca = true;
                break;
            }
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
        ++i;
    }*/

    for (i = 1; i < tamanho; i++)
        {
            int atual = original[i];
            j = i - 1;

            while ((j >= 0) && (atual < original[j]))
            {
//                cout << "Valor de i: " << i << endl;
//                cout << "indice[j]: " << j << endl << "trocou valor com indice[j+1]: " << j+1 << endl;
//                cout << "Valor de indice [j] " << original[j] << endl << "Valor de indice[j+1] " << original[j+1] << endl;
                pInicial[i][j] = j + 1;
                pFinal[i][j] =  j;
//                cout << "pInicial[" << i << "][" << j << "]: " <<   pInicial[i][j] << endl;
//                cout << "pFinal["   << i << "][" << j << "]: " <<  pFinal[i][j] << endl;


                original[j + 1] = original[j];
                j = j - 1;
            }

            original[j + 1] = atual;
        }

    if(i==tamanho){
        cout << "Flag 10000" << endl;
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

//        cout << "Flag 100" << endl;
//        cout << "bj:" << bj << endl;
//        getchar();

        if(mi < tamanho){
//            cout << "Flag 101" << endl;
//            getchar();
        if(bj>-1) {
//            cout << "Flag 102"  << endl;
//            getchar();

            if(pInicial[mi][bj]!=-1 && pFinal[mi][bj]!=-1){
                cout << "Flag 104" << endl;
                cout << "p[" << mi << "][" << bj << "]" << endl;
                cout << "pi: " << pInicial[mi][bj] << endl;
                cout << "pj: " << pFinal[mi][bj] << endl;
                pi = pInicial[mi][bj];
                pj = pFinal[mi][bj];
                tmpI = teste[pi].getX();
                tmpJ = teste[pj].getX();
                cout << "tmpI: " << tmpI << endl;
                cout << "tmpJ: " << tmpJ << endl;
                trocarPosicoes = false;
                terminouTroca = false;
                getchar();
            }
        }
//            bi++;
//            j = tamanho - 1;
        if(bj!=-1){
//            cout << "pi:" << pInicial[mi][bj] << endl;
//            cout << "pj:" << pFinal[mi][bj] << endl;
            bj--;
//            cout << "Flag 103" << endl;
        }

        if(bj==-1){
//            cout << "mi:" << mi << endl;
//            cout << "Flag 105" << endl;
            mi++;
//            getchar();
            bj = tamanho - 1;
        }

//        tmpI = teste[i].getX();
//        tmpJ = teste[j].getX();



    }

    } else{
//        cout << "Entrou aqui. Nao sai mais " << endl;
    }

    if(terminouTroca && trocarValores) {
        cout << "Flag 106" << endl;
        cout << "Antes" << endl;
        cout << "teste[" << pj << "]: " << teste[pj].getData() << endl;
        cout << "x: " << teste[pj].getX() << endl;
        cout << "y: " << teste[pj].getY() << endl;
        cout << "z: " << teste[pj].getZ() << endl;

        cout << "teste[" << pi << "]: " << teste[pi].getData() << endl;
        cout << "x: " << teste[pi].getX() << endl;
        cout << "y: " << teste[pi].getY() << endl;
        cout << "z: " << teste[pi].getZ() << endl;


        float tmpX = teste[pj].getX();
        float tmpY = teste[pj].getY();
        float tmpZ = teste[pj].getZ();

        teste[pj].setX(teste[pi].getX());
        teste[pj].setY(teste[pi].getY());
        teste[pj].setZ(teste[pi].getZ());

        teste[pi].setX(tmpX);
        teste[pi].setY(tmpY);
        teste[pi].setZ(tmpZ);
        cout << "Depois" << endl;
        cout << "teste[" << pj << "]: " << teste[pj].getData() << endl;
        cout << "x: " << teste[pj].getX() << endl;
        cout << "y: " << teste[pj].getY() << endl;
        cout << "z: " << teste[pj].getZ() << endl;

        cout << "teste[" << pi << "]: " << teste[pi].getData() << endl;
        cout << "teste[" << pi << "]: " << teste[pi].getData() << endl;
        cout << "x: " << teste[pi].getX() << endl;
        cout << "y: " << teste[pi].getY() << endl;
        cout << "z: " << teste[pi].getZ() << endl;

        int tmp = teste[pj].getData();
        teste[pj].setData(teste[pi].getData());
        teste[pi].setData(tmp);

        getchar();


//            int tmp = teste[i].getData();
//            int tmp2 = teste[j+1].getData();
//            int tmp3 = teste[j].getData();
//            cout << "tmp: " << tmp << endl;
//            cout << "teste[j+1]: " << tmp2 << endl;
//            cout << "teste[j]: " << tmp3 << endl;
//            teste[j+1].setData(teste[j].getData());
//            teste[j].setData(tmp);
//            cout << "j: " << j <<  endl;
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
    glutTimerFunc(100, Anima, 1);
    glutMouseFunc(Mouse_Press);
    glutMotionFunc(Mouse_Motion);
    Inicializa();
    CriarMenu();
    glutMainLoop();


}
