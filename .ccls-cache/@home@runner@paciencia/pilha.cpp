#include "pilha.hpp"

Pilha::Pilha(int tamMax) : _tam(0), _tamMax(tamMax) { _cartas.resize(tamMax); }

Pilha::~Pilha(void) {}

bool Pilha::Push(Carta &carta) {
  if (_tam < _tamMax) {
    _cartas[_tam] = &carta;
    _tam++;
    return true;
  }
  return false;
}

bool Pilha::Push_Copia_do_Valor(Carta carta) {
  if (_tam < _tamMax) {
    _cartas[_tam] = new Carta(carta);
    _tam++;
    return true;
  }
  return false;
}

void Pilha::Clear() {
  for (int i = 0; i < _tam; i++)
    _cartas[i] = NULL;

  _tam = 0;
}

bool Pilha::Vazia() {
  if (_tam == 0)
    return true;
  return false;
}

Carta& Pilha::topo(void) {
  if (_tam > 0)
    return *_cartas[_tam - 1];
}

bool Pilha::Remove(int indice) {
  if (indice >= 0 && indice < _tamMax) {
    _cartas[indice] = NULL;
    _tam--;
    return true;
  }
  return false;
}

int Pilha::Tamanho() { return _tam; }

bool Pilha::Pop() {
  if (_tam > 0) {
    _cartas[_tam - 1] = NULL;
    _tam--;
    return true;
  }
  return false;
}

Carta& Pilha::operador[](int indice) {
  if (indice >= 0 && indice <= _tam) {
    return (*_cartas[indice]);
  }
}

void Pilha::Move(Pilha &from, Pilha &to) {
  to.Push(from.topo());
  from.Pop();
}
