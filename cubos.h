#ifndef CUBOS_H
#define CUBOS_H

//Classe cubos
class Cubos
{
    public:
        friend void insertSort(Cubos v[],int tamanho);
        Cubos();
        Cubos(int,float,float,float);
        float x,y,z,posX,posY,posZ;
        void setTranslateFrente(float,float,float);
        void setTranslateTras(float,float,float);
        void setData(int);
        void insertSort();
        void escrever();
        void drawCube();
        float getX();
        float getY();
        float getZ();
        int data;
        int getData();
        float NovaPosicao;
        void setNovaPosicao(float);
        float getNovaPosicao;



};

#endif // CUBOS_H
