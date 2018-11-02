#ifndef LISTEEQUIPE_H
#define LISTEEQUIPE_H

#include "Equipe.h"

class ListeEquipe {
public:
	ListeEquipe();
	~ListeEquipe();

	const ListeEquipe& operator=(const ListeEquipe& lj);

	void insererFin(const Equipe& equipe);
	//const Equipe& obtenirEquipe(int indice) const;
	Equipe& obtenirEquipe(int indice);
	int getTaille() const;

private:
	void doublerMaximum();
	int maximum;
	int taille;
	Equipe *lesEquipes;
};

#endif
