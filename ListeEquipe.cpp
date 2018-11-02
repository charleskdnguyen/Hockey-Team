#include "ListeEquipe.h"
#include "Equipe.h"
#include <string>
#include <iostream>

using namespace std;

ListeEquipe::ListeEquipe() : taille(0), maximum(2) {
	 lesEquipes = new Equipe[maximum];
}

ListeEquipe::~ListeEquipe() {
	delete[] lesEquipes;
}

const ListeEquipe& ListeEquipe::operator=(const ListeEquipe& lj) {
	//this->lesEquipes = lj;
	return *this;
}

void ListeEquipe::insererFin(const Equipe& equipe) {
	if (taille == maximum) {
		doublerMaximum();
	}

	lesEquipes[taille++] = equipe;
}

//const Equipe& ListeEquipe::obtenirEquipe(int indice) const {
//	return lesEquipes[indice];
//}

Equipe& ListeEquipe::obtenirEquipe(int indice) {
	return lesEquipes[indice];
}

//DONE
int ListeEquipe::getTaille() const {
	return taille;
}

//DONE
void ListeEquipe::doublerMaximum() {
	maximum = maximum * 2;
	Equipe *tmp = new Equipe[maximum];
	for (int i = 0; i < taille; i++)
	{
		tmp[i] = lesEquipes[i];
	}
	delete[] lesEquipes;
	lesEquipes = tmp;
}