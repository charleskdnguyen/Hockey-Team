#ifndef NOEUDJOUEUR_H
#define NOEUDJOUEUR_H

#include "Joueur.h"

class NoeudJoueur {
public:
	NoeudJoueur();
	NoeudJoueur(const NoeudJoueur& ne);
	~NoeudJoueur();

	const NoeudJoueur& operator=(const NoeudJoueur& noeud);

	void setJoueur(const Joueur& joueur);
	void setSuivant(NoeudJoueur* n);
	NoeudJoueur* getSuivant() const;
	const Joueur& getJoueur() const;
	Joueur& getJoueur();

private:
	NoeudJoueur* suivant;
	Joueur leJoueur;
};

#endif