//Manipulando os metodos da classe Cubos aqui
#include <GL/glut.h>
#include <string>
#include <iostream>
#include "cubos.h"
#include <stdio.h>
#include <stdlib.h>


Cubos::Cubos(int qtdCubos)
{
    this->setQtdCubos(qtdCubos);
    cuboInicio = NULL;
    cuboAnterior = NULL;
    cuboProximo = NULL;
    cuboFim = NULL;

}


Cubos::Cubos(int data,double posX,double posY,double posZ)
{
    cuboAnterior = NULL;
    cuboProximo = NULL;
    this->setPosX(posX);
    this->setPosY(posY);
    this->setPosZ(posZ);
    this->setData(data);

}

void Cubos::setQtdCubos(int qtdCubos)
{
    this->qtdCubos = qtdCubos;
}

int Cubos::getQtdCubos()
{
    return qtdCubos;
}

void Cubos::setPosX(double posX)
{
    this->posX = posX;
}

void Cubos::setPosY(double posY)
{
    this->posY = posY;
}

void Cubos::setPosZ(double posZ)
{
    this->posZ = posZ;
}

double Cubos::getPosX()
{
    return posX;
}

double Cubos::getPosY()
{
    return posY;
}

double Cubos::getPosZ()
{
    return posZ;
}

bool Cubos::estaVazia()
{
    return (cuboInicio==NULL);
}

void Cubos::inicializarCubos()
{
    int tmpQtdCubos = getQtdCubos();
    for(int i = 0 ; i < tmpQtdCubos ; ++i ){
        organizarCubos();
    }
}

void Cubos::organizarCubos()
{
    if(estaVazia()){
        cuboInicio = cuboFim =  new Cubos(10,0.0,0.0,0.0);
        cuboInicio->cuboProximo = cuboFim;
        cuboFim->cuboAnterior = cuboInicio;

    }else{
        Cubos *cuboNovo = new Cubos(11,cuboFim->getPosX() + 5,cuboFim->getPosY(), cuboFim->getPosZ());
        cuboFim->cuboProximo = cuboNovo;
        cuboNovo->cuboAnterior = cuboFim;
        cuboFim = cuboNovo;
    }

    criarCubos(cuboFim);
}

void Cubos::criarPrimeiroCubo()
{


}

void Cubos::criarCubos(Cubos *tmpCubo)
{


    glPushMatrix();
        glTranslated(tmpCubo->getPosX(),tmpCubo->getPosY(),tmpCubo->getPosZ());
        glutSolidCube(1);
        std::cout << "pos x: " << tmpCubo->getPosX() << std::endl;
        std::cout << "pos y: " << tmpCubo->getPosY() << std::endl;
        std::cout << "pos z: " << tmpCubo->getPosZ() << std::endl;
        tmpCubo->escreverNaTela();
    glPopMatrix();

}

void Cubos::escreverNaTela()
{
    //Metodo para escrever
    std::string s = std::to_string(this->getData());
    char const * pchar = s.c_str();
    glRasterPos3f(-0.5,this->getPosY() + 2,this->getPosZ());
    std::cout << "texto" << std::endl;
    std::cout << "pos x: " << this->getPosX() << std::endl;
    std::cout << "pos y: " << this->getPosY() << std::endl;
    std::cout << "pos z: " << this->getPosZ() << std::endl;
    for(int i = 0 ; i < s.size() ; ++i){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,pchar[i]);
    }

}

void Cubos::setData(int data)
{
    this->data = data;
}

int Cubos::getData()
{
    return data;
}
