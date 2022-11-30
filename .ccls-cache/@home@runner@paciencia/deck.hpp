#include "pilha.hpp"
#include <ctime>
#include <iostream>


const static int TAM_VALOR = 13;    //Numero de valores de cartas = 13
const static int TAM_NIPE = 4;      //Numero de nipes = 4 ( 3,4,5,6)
const static char VALORES[] = {'A','2','3','4','5','6','7','8','9','T','J','Q','K'}; //Define os valores
const static char NAIPES[] = {'C','O','E','P'};                                       //Define os naipes

class Deck{
  public:
	  Deck(void);
	  ~Deck(void);

    void Popula(void);               //Popula cria as cartas no deck
	  void Embaralha(void);            //Embaralha dispoe as cartas aleatoriamente no deck
	  void PrintaDeck(void);           //PrintaDeck printa o deck

	  void PopulaVetor(Pilha& aDeck);  //Cria 
	
  private:
	  Carta _deck[52];
	  int indiceAtual;
};