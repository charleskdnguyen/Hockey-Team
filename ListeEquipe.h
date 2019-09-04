#ifndef LISTEEQUIPE_H
#define LISTEEQUIPE_H

#include "Equipe.h"

class ListeEquipe {
public:
	//constructeur par d�faut
	ListeEquipe();

	//destructeur
	~ListeEquipe();

	//op�rateur �gale
	const ListeEquipe& operator=(const ListeEquipe& lj);

	//on ins�re l'�quipe au prochain indice du tableau
	void insererFin(const Equipe& equipe);

	//r�cup�rer l'�quipe
	const Equipe& obtenirEquipe(int indice) const;

	//r�cup�rer l'�quipe
	Equipe& obtenirEquipe(int indice);

	//retourne la taille du tableau
	int getTaille() const;

private:
	void doublerMaximum();		//double la taille du tableau si la liste est plus grand que la taille maximale
	int maximum;		//capacit� maximale du tableau
	int taille;		//la taille du tableau
	Equipe *lesEquipes;		//chaque equipes
};

#endif
