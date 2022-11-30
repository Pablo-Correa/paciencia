#include "carta.hpp"
#include <vector>

class Pilha {
public:
  Pilha (int tamMax);
  ~Pilha (void);

  Carta& topo(void);
  Carta& operator[](int indice);
  bool Push(Carta& carta);
  bool Push_Copia_do_Valor(Carta carta);
  bool Vazia();
  int Tamanho();

  bool Remove(int indice);
  bool Pop();
  void Clear();

  static void Move(Pilha& from, Pilha& to);

private:
  int _tamMax;
	int _tam;
	std::vector<Carta*> _cartas;
};