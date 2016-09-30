//Manipulando os metodos da classe Cubos aqui
#include <GL/glut.h>
#include <string>
#include <iostream>
#include "cubos.h"
#include <stdio.h>
#include <stdlib.h>

double rot = 0;
Cubos::Cubos()
{

}

Cubos::Cubos(int data,float x,float y,float z)
{
    this->data = data;
    this->x = x;
    this->y = y;
    this->z = z;
    this->posX = this->posY = this->posZ = 0;


}

void Cubos::drawCube()
{
    this->posX += posX;
    this->posZ += posZ;
    glPushMatrix();
        glTranslatef(x ,y,z);
        glutSolidCube(2);
        escrever();
    glPopMatrix();
}

void Cubos::escrever()
{
    std::string s = std::to_string(this->getData());
    char const * pchar = s.c_str();
    glRasterPos3f(0.0,this->getY() + 2,this->getZ());
    for(unsigned  int i = 0 ; i < s.size() ; ++i){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,pchar[i]);
    }

}



void Cubos::setData(int data)
{
    this->data = data;
}

float Cubos::getX()
{
    return x;
}

float Cubos::getY()
{
    return y;
}

float Cubos::getZ()
{
    return z;
}
int Cubos::getData()
{
    return data;
}

bool Cubos::setXDireita(float novaPosicao)
{
    if(this->x!=novaPosicao){
        this->x++;
        return false;
    }
    if(this->x==novaPosicao){
        return true;
    }
}

bool Cubos::setXEsquerda(float novaPosicao)
{
    if(this->x!=novaPosicao){
        this->x--;
        return false;
    }

    if(this->x==novaPosicao){
        return true;
    }
}

bool Cubos::setZFrente(float novaPosicao)
{
    if(this->z!=novaPosicao){
        this->z++;
        return true;
    }
    if(this->z==novaPosicao){
        return false;
    }
}

bool Cubos::setZTras(float novaPosicao)
{
    if(this->z!=novaPosicao){
        this->z--;
        return true;
    }
    if(this->z==novaPosicao){
        return false;
    }
}

bool Cubos::resetZTras()
{
    if(this->z!=0){
        this->z--;
    }
}

bool Cubos::resetZFrente()
{
    if(this->z!=0){
        this->z++;
    }
}
