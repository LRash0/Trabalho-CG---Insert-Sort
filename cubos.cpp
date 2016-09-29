//Manipulando os metodos da classe Cubos aqui
#include <GL/glut.h>
#include "cubos.h"


Cubos::Cubos(int qtdCubos)
{
    this->setQtdCubos(qtdCubos);
    cuboInicio = NULL;
    cuboAnterior = NULL;
    cuboProximo = NULL;
    cuboFim = NULL;

}


Cubos::Cubos(double posX,double posY,double posZ)
{
    cuboAnterior = NULL;
    cuboProximo = NULL;
    this->setPosX(posX);
    this->setPosY(posY);
    this->setPosZ(posZ);

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
        cuboInicio = cuboFim =  new Cubos(0.0,0.0,0.0);
        cuboInicio->cuboProximo = cuboFim;
        cuboFim->cuboAnterior = cuboInicio;

    }else{
        Cubos *cuboNovo = new Cubos(cuboFim->getPosX() + 5,cuboFim->getPosY() + 0, cuboFim->getPosZ() + 0);
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
    glPopMatrix();

}
