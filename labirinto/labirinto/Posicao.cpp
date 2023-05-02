#include "Posicao.hpp"

Posicao::Posicao()
{
	this->l = 0;
	this->c = 0;
	this->letra = ' ';
}

Posicao::Posicao(int l, int c, char letra)
{
	this->l = l;
	this->c = c;
	this->letra = letra;
}

void Posicao::setC(int c) { this->c = c; }
void Posicao::setL(int l) { this->l = l; }
void Posicao::setLetra(char letra) { this->letra = letra; }

int Posicao::getC() const { return this->c; }
int Posicao::getL() const { return this->l; }
char Posicao::getLetra() const { return this->letra; }

ostream& operator<< (ostream& os, Posicao& pos)
{
	os << pos.getL() << "  " << pos.getC() << "  " << pos.getLetra() << endl;
	return os;
}
