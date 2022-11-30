#include <iostream>
#include <vector>

#include "deck.hpp"
const static int TAM_TABLEAU = 7;

class Paciencia 
{
  public:
  Paciencia(void);
  ~Paciencia(void);

	void PopulaTableau(void);
	void CartasMao(int num=1);

 // Funcoes de movimentacao das cartas deck para tableau e entre tableaus para resultado final
	void MoveNaipe(int from);
	void MoveEntrePilha(int from, int to);
	void MoveDeckParaPilha(int to);
	void MovePilhaParaPilha(int from, int to);
	bool isMovimentoValido(int from, int to);	
	bool isMovimentoPilhaValido(Carta* fromCarta, int to);
	bool isMovimentoNaipeValido(int from);

  //Funcao para ver se as pilhas com os resultados estao completos
  bool JogoCompleto();

  //Funcoes que retornam detalhamento das cartas
  void PrintDetalheTudo(void);
	void PrintDetalheNaipe(void);
	void PrintDetalheDeck(void);



  private:

  std::vector<Pilha> _pilhas;      //pilhas (serao 7 no tableau)
  std::vector<Pilha> _pilhaFinal; // Pilha final que deve ser preenchida para ganhar o jogo
  Pilha _descarte;
  Pilha _deck;


};