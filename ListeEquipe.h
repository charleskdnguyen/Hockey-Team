#ifndef LISTEEQUIPE_H
#define LISTEEQUIPE_H

#include "Equipe.h"

class ListeEquipe {
public:
	//constructeur par défaut
	ListeEquipe();

	//destructeur
	~ListeEquipe();

	//opérateur égale
	const ListeEquipe& operator=(const ListeEquipe& lj);

	//on insère l'équipe au prochain indice du tableau
	void insererFin(const Equipe& equipe);

	//récupérer l'équipe
	const Equipe& obtenirEquipe(int indice) const;

	//récupérer l'équipe
	Equipe& obtenirEquipe(int indice);

	//retourne la taille du tableau
	int getTaille() const;

private:
	void doublerMaximum();		//double la taille du tableau si la liste est plus grand que la taille maximale
	int maximum;		//capacité maximale du tableau
	int taille;		//la taille du tableau
	Equipe *lesEquipes;		//chaque equipes
};

#endif
