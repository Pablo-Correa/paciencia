#include "deck.hpp"

Deck::Deck(void):indiceAtual(0)
{
	srand((unsigned)time(0));
	Popula();
}


Deck::~Deck(void)
{
}

void Deck::Popula()                      //Popula um deck com as 52 combinacoes de cartas existentes entre 13 numeros e 4 nipes.
{
	int indice = 0;
	for(int i=0 ; i<TAM_NIPE;i++)
	{
		for(int j=0; j<TAM_VALOR;j++)
		{
			_deck[indice] = Carta(VALORES[j],NAIPES[i]);
			indice++;
		}
	}
}

void Deck::Embaralha()
{
	int max = TAM_NIPE * TAM_VALOR;
	for(int i=0; i<max-1; i++)
	{
		int randNum = rand() % 52;             //randNum gera um numero aleatorio ate 52 (numero de cartas no deck).
		std::swap(_deck[i],_deck[randNum]);		 //A funcao swap faz a troca de lugar da carta no lugar i com a carta no lugar sorteado, no fim o       
                                           //baralho estara misturado.
	}
	
}

void Deck::PrintaDeck(void)
{
	int max = TAM_NIPE * TAM_VALOR;           //Passamos pelas 52 cartas e printamos.
	for(int i=0; i<max; i++)
	{
		if(i %13 == 0)
			std::cout<< '\n' <<'\n';
    std::cout<< _deck[i] << " " << _deck[i] << "  ";
	}
}

void Deck::PopulaVetor(Pilha& aDeck)
{
	int max = TAM_NIPE * TAM_VALOR;          //A funcao de popular com cartas do deck uma pilha. Sera usado para popular o tableau.
	aDeck.Clear();
	for(int i=0; i<max; i++)
		aDeck.Push_Copia_do_Valor(_deck[i]);
}