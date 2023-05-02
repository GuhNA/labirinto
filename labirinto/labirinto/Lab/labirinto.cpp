#include "Caminho.hpp"
#include <fstream>


vector<vector<char>> lab(10, vector < char>(15));

void printLab(vector<vector<char>> mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
}

Posicao Inicio(vector<vector<char>> lab)
{
	for (int i = 0; i < lab.size(); i++)
	{
		for (int j = 0; j < lab.at(i).size(); j++)
		{
			if (lab[i][j] == 'E')
			{
				Posicao caminho(i, j, lab[i][j]);
				return(caminho);
			}
		}
	}
}


/*
	SUBIR:
			lab.at(caminho.getL()).at(caminho.getC()) = 'X';
			caminho.setL(caminho.getL() - 1);

	DESCER:
			lab.at(caminho.getL()).at(caminho.getC()) = 'X';
			caminho.setL(caminho.getL() + 1);

	ESQUERDA:
			lab.at(caminho.getL()).at(caminho.getC()) = 'X';
			caminho.setC(caminho.getC() - 1);

	DIRETA:
			lab.at(caminho.getL()).at(caminho.getC()) = 'X';
			caminho.setC(caminho.getC() + 1);

*/

char direcao(Posicao caminho, vector<char>& letra)
{
	int cont = 0;
	char temp = ' ';
	//sobe
	if (lab.at(caminho.getL()).at(caminho.getC()) != 'X' && caminho.getL() != 0 && lab.at(caminho.getL() - 1).at(caminho.getC()) == '.')
	{
		temp = 's';
		cont++;
		letra.push_back(temp);
	}
	//desce
	if (lab.at(caminho.getL()).at(caminho.getC()) != 'X' && caminho.getL() != 9 && lab.at(caminho.getL() + 1).at(caminho.getC()) == '.')
	{
		temp = 'd';
		cont++;
		letra.push_back(temp);
	}
	//esquerda
	if (lab.at(caminho.getL()).at(caminho.getC()) != 'X' && caminho.getC() != 0 && lab.at(caminho.getL()).at(caminho.getC() - 1) == '.')
	{
		temp = 'e';
		cont++;
		letra.push_back(temp);
	}
	//Direita
	if (lab.at(caminho.getL()).at(caminho.getC()) != 'X' && caminho.getC() != 14 && lab.at(caminho.getL()).at(caminho.getC() + 1) == '.')
	{
		temp = 'D';
		cont++;
		letra.push_back(temp);
	}
	//direita
	if (caminho.getC() < 14 && lab.at(caminho.getL()).at(caminho.getC() + 1) == 'S')
	{
		return 'h';
	}
	//esquerda
	if (caminho.getC() > 0 && lab.at(caminho.getL()).at(caminho.getC() - 1) == 'S')
	{
		return 'j';
	}
	//desce
	if (caminho.getL() < 9 && lab.at(caminho.getL() + 1).at(caminho.getC()) == 'S')
	{
		return 'k';
	}

	//sobe
	if (caminho.getL() > 0 && lab.at(caminho.getL() - 1).at(caminho.getC()) == 'S')
	{
		return 'l';
	}


	if (cont < 2)
	{
		letra.pop_back();
		return temp;
	}
	else
	{
		return 'B';
	}
}


void seguir(char letra, vector<Posicao>& solucao, Posicao& caminho, vector<vector<char>>& lab)
{
		caminho.setLetra(lab.at(caminho.getL()).at(caminho.getC()));
		solucao.push_back(caminho);

		if (caminho.getLetra() != 'B')
		{
			lab.at(caminho.getL()).at(caminho.getC()) = 'X';
		}

		switch (letra)
		{
		case('s'):
			caminho.setL(caminho.getL() - 1);
			break;

		case('d'):
			caminho.setL(caminho.getL() + 1);
			break;

		case('e'):
			caminho.setC(caminho.getC() - 1);
			break;

		case('D'):
			caminho.setC(caminho.getC() + 1);
			break;

		case('l'):
			caminho.setL(caminho.getL() - 1);
			lab.at(caminho.getL()).at(caminho.getC()) = 'F';
			break;

		case('k'):
			caminho.setL(caminho.getL() + 1);
			lab.at(caminho.getL()).at(caminho.getC()) = 'F';
			break;

		case('j'):
			caminho.setC(caminho.getC() - 1);
			lab.at(caminho.getL()).at(caminho.getC()) = 'F';
			break;

		case('h'):
			caminho.setC(caminho.getC() + 1);
			lab.at(caminho.getL()).at(caminho.getC()) = 'F';
			break;

		}
}

void movimentacao(Posicao caminho, vector<vector<char>>& lab)
{
	vector<Posicao> solucao;
	vector<char> letra;
	//caminho.getLetra() != 'S'
	int i = 0;

	while (lab.at(caminho.getL()).at(caminho.getC()) != 'F')
	{
		char dir = direcao(caminho, letra);
		if (dir != ' ' && dir != 'B')
		{
			seguir(dir, solucao, caminho, lab);
		}
		else if(dir == 'B')
		{
			lab.at(caminho.getL()).at(caminho.getC()) = 'B';
		}
		else
		{
			while (lab.at(caminho.getL()).at(caminho.getC()) != 'B')
			{
				lab.at(caminho.getL()).at(caminho.getC()) = '*';
				solucao.pop_back();
				caminho = solucao.back();
			}
			letra.pop_back();
		}

		if (lab.at(caminho.getL()).at(caminho.getC()) == 'B')
		{
			seguir(letra.back(), solucao, caminho, lab);
		}
		i++;

	}
	cout << "X  Y  Letra" << endl;
	for (int i = 0; i < solucao.size(); i++)
	{
		cout << solucao[i];
	}
}

int main()
{

	fstream f;
	f.open("labirinto.txt");

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			f >> lab[i][j];
		}
	}

	cout << "inicio do lab: " << endl;
	printLab(lab);

	Posicao inicio = Inicio(lab);

	movimentacao(inicio, lab);

	cout << "Fim do lab: " << endl;
	printLab(lab);

	return 0;
}