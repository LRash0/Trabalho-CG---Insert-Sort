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
        glTranslatef(x,y,z);
        glutSolidCube(2);
        escrever();
    glPopMatrix();
}

void Cubos::escrever()
{
    std::string s = std::to_string(this->getData());
    char const * pchar = s.c_str();
    glRasterPos3f(0.0,this->getY() + 2,this->getZ());
    for(int i = 0 ; i < s.size() ; ++i){
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,pchar[i]);
    }

}

void Cubos::setTranslate(float posX,float posY,float posZ)
{
    this->posX = posX;
    this->posY = posY;
    this->posZ = posZ;
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

