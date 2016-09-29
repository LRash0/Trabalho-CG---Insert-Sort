#ifndef CUBOS_H
#define CUBOS_H

//Classe cubos
class Cubos
{
    public:
        Cubos(int);
        Cubos(int,double,double,double);
        void criarCubos(Cubos *);
        void criarPrimeiroCubo();
        void inicializarCubos();
        void setQtdCubos(int);
        void escreverNaTela();
        int getQtdCubos();
        void setPosX(double);
        void setPosY(double);
        void setPosZ(double);
        void setData(int);
        void organizarCubos();
        double getPosX();
        double getPosY();
        double getPosZ();
        int getData();
        bool estaVazia();

    private:
        int data;
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
