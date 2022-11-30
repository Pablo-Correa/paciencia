#include <iostream>
#include "paciencia.hpp"

using namespace std;

void Jogada(Paciencia& jogo);
void JogadaPilhaFinal(Paciencia& jogo);
void ClearScreen();

int main(int argc, char** argv)
{	
	Paciencia jogo = Paciencia();
	jogo.PrintDetalheTudo();
	
	bool funcionando = true;
	do{
		char option = ' ';
    cout<<endl<<endl;	
    cout<<"Legenda:";	
    cout<<"\nC = COPAS ♥ / O = OUROS ♦ / E = ESPADAS ♠ / P = PAUS ♣";
    cout<<"\nA = 1(AS) / T = 10 / J = VALETE / Q = DAMA / K = REI";
		cout<<endl<<endl;		
		cout<<"\n1. Mover a carta entre pilhas";		
		cout<<"\n2. Mover a carta para pilha final";
		cout<<"\n3. Comprar";
		cout<<"\n0. Sair";
		cout<<"\nEntre uma opcao:";
		cin >> option;
		
		/* As entradas do teclado 0 - 7 tem o codigo ASCII: 48 - 55  */
    // Leitura das entradas do teclado

		if(jogo.JogoCompleto())
		{
			ClearScreen();
			cout<<"\n\n\n\t\t\t VOCE VENCEU!!!\n\n";
			cin.get();
			funcionando = false;
		}

		else
		{
			switch((int)option)
			{
			case 48:
				funcionando = false;
				break;
			case 49:
				Jogada(jogo);
				break;		
			case 50:
				JogadaPilhaFinal(jogo);
				break;		
			case 51:
				jogo.CartasMao(3);
				break;
			default:
				cout<<"\nOpcao invalida";
				cin.ignore(80,'\n');
				break;
			}
			ClearScreen();
			jogo.PrintDetalheTudo();			
		}

	}while(funcionando);
	
	return 0;
}
// Funcoes para funcionamento da gameplay -> invocacao dos numeros de origem e destino do movimento
void Jogada(Paciencia& jogo)
{
	char from = '0' ,to = '0';
	cout<<endl <<endl;
	cout<<"De(7 para deck): ";
	cin >> from;
	cout<< "Para: ";
	cin>> to;

	if( ((int)from >= 48 && (int)from <= 55) &&
		((int)from >= 48 && (int)to <= 54) )

	{
		jogo.MovePilhaParaPilha((int)from - 48,(int)to - 48);
	}

	else
	{
		cout<<"Invalido";
		cin.get();
		cin.get();
	}
	
}

void JogadaPilhaFinal(Paciencia& jogo)
{
	char from = 0;
	cout<<endl <<endl;
	cout<< "De(7 para deck): ";
	cin>> from;
	
	if((int)from >= 48 && (int)from <= 55)
		jogo.MoveNaipe((int)from - 48);
	
	else
	{
		cout<<"Invalido";
		cin.get();
		cin.get();
	}
	
}

void ClearScreen()
{
#ifdef __linux__ 
	system("clear");
#elif _WIN32
	system("cls");
#endif
}
