#include "carta.hpp"
Carta :: Carta(void)
{

}
Carta::Carta(char r, char s)
:Valor(r)
,Naipe(s)
,isVirada(false)
,filho(NULL)
,pai(NULL)
{

  // Nao precisa de nada aqui
}
Carta :: ~Carta()
{
  // Nao precisa de nada aqui
}                   

void Carta::ViraCarta()
{
	isVirada = !isVirada; // Muda o lado da carta.
}

bool Carta::GetIsVirada()
{
	return isVirada;
}

char Carta :: GetValor()
{
    return Valor;
}          
char Carta :: GetNaipe()
{
    return Naipe;
}      
int Carta::GetValorPaciencia() // Essa funcao vai definir inteiros para as cartas A,T,J,Q,K.
{
	if(Valor == 'A')
		return 1;
	else if(Valor == 'T')
		return 10;
	else if(Valor == 'J')
		return 11;
	else if(Valor == 'Q')
		return 12;
	else if(Valor == 'K')
		return 13;
	else
	{
		char c[] = {Valor, '\0'};
		return atoi(c);
	}
}

// Isso aqui tudo vai definir (no windows e no linux) que as cartas de copas e ouros sao vermelhas e as cartas de espada e paus sao pretas(azuis no caso, pois preto some no terminal)
std::ostream & operator<< (std::ostream & os, Carta& c)
{

#ifdef _WIN32
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if(c.Naipe == 'P' || c.Naipe == 'E')
		SetConsoleTextAttribute(handle, BLUE);
	else
		SetConsoleTextAttribute(handle,RED);

	os<< c.Naipe << c.Valor;
	SetConsoleTextAttribute(handle,WHITE);

#elif __linux__

	if(c.Naipe == 'P' || c.Naipe == 'E')
		os<<"\033[22;34m";	
	else
		os<<"\033[22;31m";
	os<< c.Naipe << c.Valor;
	os<<"\033[22;30m";
  
#endif

	return os;
}