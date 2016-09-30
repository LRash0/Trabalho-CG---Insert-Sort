#ifndef CUBOS_H
#define CUBOS_H

//Classe cubos
class Cubos
{
    public:
        Cubos();
        Cubos(int,float,float,float);
        double x,y,z,posX,posY,posZ;
        void setTranslate(float,float,float);
        void escrever();
        void drawCube();
        float getX();
        float getY();
        float getZ();
        int data;
        int getData();

};

#endif // CUBOS_H
