#ifndef CAMINHO_HPP
#define CAMINHO_HPP

#include <iostream>
#include <vector>

using namespace std;

class Posicao
{
private:
	int l;
	int c;
	char letra;

public:
	Posicao();

	Posicao(int l, int c, char letra);

	void setL(int l);
	void setC(int c);
	void setLetra(char letra);
	int getL() const;
	int getC() const;
	char getLetra() const;
	friend ostream& operator<< (ostream& os, Posicao& pos);

};

#endif // !CAMINHO_HPP
