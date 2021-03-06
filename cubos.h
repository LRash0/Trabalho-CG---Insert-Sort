#ifndef CUBOS_H
#define CUBOS_H

//Classe cubos
class Cubos
{
    public:
        friend void insertSort(Cubos v[],int tamanho);
        Cubos();
        Cubos(int,float,float,float);
        void mostrasDatas();
        float x,y,z,posX,posY,posZ;
        void setTranslateFrente(float,float,float);
        void setTranslateTras(float,float,float);
        void setData(int);
        void setX(float);
        void setY(float);
        void setZ(float);
        void insertSort();
        void escrever();
        void drawCube();
        bool setXDireita(float);
        bool setXEsquerda(float);
        bool setZFrente(float);
        bool setZTras(float);
        bool resetZTras();
        bool resetZFrente();
        bool escreve;
        float getX();
        float getY();
        float getZ();
        int data;
        int getData();




};

#endif // CUBOS_H
