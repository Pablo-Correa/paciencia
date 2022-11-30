#include "paciencia.hpp"
using namespace std;
Paciencia::Paciencia(void)
:_deck(52)
,_descarte(52)
{

  //Aqui usamos a classe Deck para criar um deck de paciencia. Usamos as funcoes de popular o deck e de embaralhar para cria-lo aleatorio.
	Deck deck = Deck();
	deck.Embaralha();	
	deck.PopulaVetor(_deck);
		
	for(int i=0; i<TAM_TABLEAU; i++)
	{
		Pilha pilhaCartas = Pilha(20);
		_pilhas.push_back(pilhaCartas);
	}
	
	for(int i=0; i<4; i++)
	{	
		Pilha pilhaFinal = Pilha(13);
		_pilhaFinal.push_back(pilhaFinal);	
	}
	PopulaTableau();
}

Paciencia::~Paciencia(void)
{
}

  //Populamos o tableau com as pilhas de cartas previamente populadas.
void Paciencia::PopulaTableau(void)
{
	for(int i=0; i<TAM_TABLEAU; i++)
	{		
		for(int j=0; j<TAM_TABLEAU -i; j++)
		{	
			if(j == (TAM_TABLEAU - i) - 1)
				_deck.topo().ViraCarta();

			_pilhas[j].Push(_deck.topo());
			_deck.Pop();
		}
	}
}

  //Essa funcao leva 3 cartas para a mao.
void Paciencia::CartasMao(int num)
{
	int tam = _deck.Tamanho();
	for(int i=0; i<tam; i++)
	{
		if(_deck.topo().GetIsVirada())
		{
			_deck.topo().ViraCarta();
			_descarte.Push(_deck.topo());
			_deck.Pop();
		}		
	}

	if(_deck.Vazia())
	{
		for(int i=_descarte.Tamanho()-1; i>=0; i--)
			_deck.Push(_descarte[i]);			
		
		_descarte.Clear();
	}

	int index = 0;
	for(int i=0; i<num; i++)
	{
		index = _deck.Tamanho() -i -1;
		if(index >= 0)
		{
			_deck[index].ViraCarta();
		}
		else
			break;
	}
}
  //Funcoes para printar a tela do jogo e atualizar a cada movimento
void Paciencia::PrintDetalheNaipe()
{
	cout<<"=============================================\n";
	for(int j=0; j<_pilhaFinal.size(); j++)
	{
		switch(j)
		{
		case 0:
			cout<< "♥ :";
			break;
		case 1:
			cout<< "♦ :";
			break;
		case 2:
			cout<< "♠ :";
			break;
		case 3:
			cout<< "♣ :";
			break;
		}
		
		for(int i=0; i<_pilhaFinal[j].Tamanho(); i++)
		{
			if(&_pilhaFinal[j][i] != NULL)
				cout<<_pilhaFinal[j][i] << " ";
			else
				break;
		}
		cout<< endl;
	}
	cout<<"=============================================\n";
	cout<<endl;
}

void Paciencia::PrintDetalheDeck()
{
	cout<<"----------------------------------------------\n";
	cout<<"|7|Sua mao: ";
	for(unsigned int i=0; i<_deck.Tamanho(); i++)
	{		
		if(_deck[i].GetIsVirada())
			cout<<_deck[i] << " ";
		
	}
	cout<<"\n----------------------------------------------\n";
}

void Paciencia::PrintDetalheTudo()
{
	
	PrintDetalheDeck();
	PrintDetalheNaipe();


	cout<< "| 6 | \t | 5 | \t | 4 | \t | 3 | \t | 2 | \t | 1 | \t | 0 |\n";
	cout<< "----- \t ----- \t ----- \t ----- \t ----- \t ----- \t -----\n";
	
	//Os numeros devem ser sempre maior ou igual a 0. (unsigned)
	int colMax = _pilhas.size();
	int rowMax = 0;
	for(int i=0; i<colMax; i++)
	{
		if(_pilhas[i].Tamanho() > rowMax)
		{
			rowMax = _pilhas[i].Tamanho();
		}
	}

	for(int i=0; i<rowMax; i++)
	{		
		for(int j=colMax-1; j>=0; j--)
		{	
			if(i >= _pilhas[j].Tamanho())
			{
				cout<< "      \t " ;
				continue;
			}
					
			if(_pilhas[j][i].GetIsVirada())
				cout << "  "  << _pilhas[j][i] << "  \t ";
			else
				cout << "  " <<(char)254 << "   \t ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;


	//Mostra as cartas descartadas na rodada
  
	cout<<"\nCartas descartadas: \n\n";
	for(unsigned int i=0; i<_descarte.Tamanho(); i++)
		cout<<_descarte[i] << " ";
	cout<<endl<<endl;
}

bool Paciencia::isMovimentoValido(int from, int to)
{	

	//Comeca e termina o movimento igualemente
	if(from == to && from != 7)
		return false;

	Carta* toCarta;
	Carta* fromCarta;

	if(from == 7)
	{
		if(!_deck.Vazia())
		{
			if(!_deck.topo().GetIsVirada())
			{
				return false;
			}
			else
			{
				fromCarta = &_deck.topo();
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		//Garante que e invalido fazer um movimento a partir de uma pilha vazia.
		if(!_pilhas[from].Vazia())
			fromCarta = &_pilhas[from].topo();
		else
			return false;
	}

	if(!_pilhas[to].Vazia())
		toCarta = &_pilhas[to].topo();

	//Permite o movimento do rei para a casa vazia.
	if(_pilhas[to].Vazia())
	{		
		if(fromCarta->GetValor() == 'K')
			return true;
		else
			return false;
	}

	else if(fromCarta->GetValorPaciencia() == toCarta->GetValorPaciencia()-1 )
	{
		int toColor = 0, fromColor = 0;
		if(toCarta->GetNaipe() == 'C' || toCarta->GetNaipe() == 'O')
			toColor = 0;
		else
			toColor = 1;
		if(fromCarta->GetNaipe() == 'C' || fromCarta->GetNaipe() == 'O')
			fromColor = 0;
		else
			fromColor = 1;

		if(fromColor == toColor)
			return false;
		else
			return true;
	}	
	return false;
}
// Funcoes que determinam movimentos validos
// Um naipe so pode ser movido para uma casa do naipe oposto.
bool Paciencia::isMovimentoNaipeValido(int from)
{
	Carta* fromCarta;
	if(from == 7)
	{
		if(!_deck.Vazia())
		{
			if(!_deck.topo().GetIsVirada())
			{
				return false;
			}
			else
			{
				fromCarta = &_deck.topo();
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		if(!_pilhas[from].Vazia())
			fromCarta = &_pilhas[from].topo();
		else
			return false;
	}

  //Definimos as restricoes para o movimento de resposta -> mover para a pilha final

	char naipe = fromCarta->GetNaipe();
	int moveIndice = 0;
	switch(naipe)
	{
	case 'C':
		moveIndice = 0;
		break;
	case 'O':
		moveIndice =	1;
		break;
	case 'E':
		moveIndice = 2;
		break;
	case 'P':
		moveIndice = 3;
		break;
	}

	if(fromCarta->GetValorPaciencia() == _pilhaFinal[moveIndice].Tamanho() + 1 )
	{
		if(!_pilhaFinal[moveIndice].Tamanho() == 0)
		{
			if(fromCarta->pai != NULL)
				fromCarta->pai->filho = NULL;
			fromCarta->pai = &_pilhaFinal[moveIndice].topo();
			_pilhaFinal[moveIndice].topo().filho = fromCarta;
			fromCarta->filho = NULL;

		}
		if(from != 7){
			Pilha::Move(_pilhas[from],_pilhaFinal[moveIndice]);
			if(!_pilhas[from].Vazia())
			{
				if(!_pilhas[from].topo().GetIsVirada())
					_pilhas[from].topo().ViraCarta();
			}
		}
		else
		{
			_pilhaFinal[moveIndice].Push(_deck.topo());
			_deck.Pop();
		}
	}
			
	
	return false;	
}
// So pode ser feito se for valido.
void Paciencia::MoveNaipe(int from)
{
	isMovimentoNaipeValido(from)	;
}


//Verifica movimento entre pilhas e vira cartas caso ocorra
void Paciencia::MoveEntrePilha(int from, int to)
{
	if(isMovimentoValido(from,to))
	{
		if(!_pilhas[to].Vazia())
			_pilhas[to].topo().filho = &_pilhas[from].topo();
		
		if(_pilhas[from].topo().GetValor() != 'K')
			_pilhas[from].topo().pai = &_pilhas[to].topo();

		Pilha::Move(_pilhas[from], _pilhas[to]);
				
		if(!_pilhas[from].Vazia())
			if(!_pilhas[from].topo().GetIsVirada())
				_pilhas[from].topo().ViraCarta();
	}
}

//Realiza um movimento do deck (7) para uma pilha do tableau
void Paciencia::MoveDeckParaPilha(int to)
{
	if(isMovimentoValido(7 ,to))
	{
		if(!_pilhas[to].Vazia())
			_pilhas[to].topo().filho = &_deck.topo();	
		if(_deck.topo().GetValor() != 'K')
			_deck.topo().pai = & _pilhas[to].topo();
		
		_pilhas[to].Push(_deck.topo());
		_deck.Pop();
			

	}
}
//Realiza um movimento entre as pilhas do tableau.
void Paciencia::MovePilhaParaPilha(int from, int to)
{
	if(from == 7)
	{	
		MoveDeckParaPilha(to);
		return;
	}
	else if(_pilhas[from].Tamanho() == 0)
		return;

	Carta* fromCarta;
	fromCarta = &_pilhas[from].topo();

	if(fromCarta->pai == NULL)
		MoveEntrePilha(from,to);
	else
	{
		int pos = _pilhas[from].Tamanho()-1;
		bool checkPai = true;
		bool achou = false;
		while(checkPai && !achou)
		{					
			if(isMovimentoPilhaValido(fromCarta,to))
				achou = true;
			else if(fromCarta->pai == NULL)
				checkPai = false;
			else
			{
				fromCarta = fromCarta->pai;
				pos--;
			}
			
		}

		if(achou)
		{
			bool temFilho = true;
			if(fromCarta->pai != NULL)
					fromCarta->pai->filho = NULL;
			
			while(temFilho)
			{	
				
				if(!_pilhas[to].Vazia())
				{
					fromCarta->pai = &_pilhas[to].topo();
					_pilhas[to].topo().filho = fromCarta;
				}
				_pilhas[to].Push(*fromCarta);

				_pilhas[from].Remove(pos);
				fromCarta = fromCarta->filho;
		
									
				pos++;
				if(fromCarta == NULL)
					temFilho = false;
			}

		}

		if(!_pilhas[from].Vazia())
			if(!_pilhas[from].topo().GetIsVirada())
				_pilhas[from].topo().ViraCarta();
	}
}

// Um valor deve ser estristamente 1 a baixo da carta de destino.
bool Paciencia::isMovimentoPilhaValido(Carta* fromCarta, int to)
{
	Carta* toCarta;	

	if(!_pilhas[to].Vazia())
		toCarta = &_pilhas[to].topo();

	//Movimento do rei para a casa vazia.
	if(_pilhas[to].Vazia())
	{
		if(fromCarta->GetValor() == 'K')
			return true;
		else
			return false;
	}
	
	else if(fromCarta->GetValorPaciencia() == toCarta->GetValorPaciencia()-1 )
	{
		int toColor = 0, fromColor = 0;
		if(toCarta->GetNaipe() == 'C' || toCarta->GetNaipe() == 'O')
			toColor = 0;
		else
			toColor = 1;
		if(fromCarta->GetNaipe() == 'C' || fromCarta->GetNaipe() == 'O')
			fromColor = 0;
		else
			fromColor = 1;

		if(fromColor == toColor)
			return false;
		else
			return true;
	}	
	return false;

}
//Finaliza o jogo caso todas as casas da pilha final estejam completas
bool Paciencia::JogoCompleto()
{
	for(int i=0; i<_pilhaFinal.size(); i++)
		if(_pilhaFinal[i].Tamanho() < 13)
			return false;
	return true;
}