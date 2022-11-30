#include <iostream>
#ifdef _WIN32
#include<windows.h>         //Isso vai servir para colorir tanto as cartas quanto a interface... -> Para usar no windows eh diferente do linux.
const static int BLACK = 0;
const static int BLUE = 9;
const static int RED = 12;
const static int WHITE = 15;
#elif __linux__
#include "stdlib.h"
#endif

class Carta
{
  public:
    Carta(char Valor, char Naipe);       
    Carta(void);                        //Construtor
    virtual ~Carta();                   //Destrutor
    
    void ViraCarta();                  // Virar uma carta que nao esta virada para cima
    bool GetIsVirada();

    int GetValorPaciencia();
    char GetValor();                //Gets 
    char GetNaipe();   

    friend std::ostream & operator<< (std::ostream & os, Carta& c); // friend concede acesso a conteudo private da classe para retornar a funcao

    // Esses ponteiros serao utilizados para navegar no tableau.
    Carta* pai;
    Carta* filho;

  private:
    char Valor;
    char Naipe;
    bool isVirada; // Define se a carta esta virada para cima ou nao.

  
};