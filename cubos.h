#ifndef CUBOS_H
#define CUBOS_H

//Classe cubos
class Cubos
{
    public:
        Cubos(int);
        Cubos(double,double,double);
        void criarCubos(Cubos *);
        void criarPrimeiroCubo();
        void inicializarCubos();
        void setQtdCubos(int);
        int getQtdCubos();
        void setPosX(double);
        void setPosY(double);
        void setPosZ(double);
        void organizarCubos();
        double getPosX();
        double getPosY();
        double getPosZ();
        bool estaVazia();

    private:
        Cubos *cuboInicio;
        Cubos *cuboAnterior;
        Cubos *cuboProximo;
        Cubos *cuboFim;
        int qtdCubos;
        double posX;
        double posY;
        double posZ;

};

#endif // CUBOS_H
