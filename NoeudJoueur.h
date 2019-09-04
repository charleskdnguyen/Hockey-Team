#ifndef NOEUDJOUEUR_H
#define NOEUDJOUEUR_H

#include "Joueur.h"

class NoeudJoueur {
public:
	//constructeur par défaut
	NoeudJoueur();
	NoeudJoueur(const NoeudJoueur& ne);

	//destructeur
	~NoeudJoueur();

	//opérateur égale
	const NoeudJoueur& operator=(const NoeudJoueur& noeud);

	//pour set un joueur
	void setJoueur(const Joueur& joueur);

	//pour set le prochain noeud
	void setSuivant(NoeudJoueur* n);

	//pour recuperer le noeud suivant
	NoeudJoueur* getSuivant() const;

	//pour recuperer le joueur dans le noeud
	const Joueur& getJoueur() const;

	//pour recuperer le joueur dans le noeud
	Joueur& getJoueur();

private:
	NoeudJoueur* suivant;	//le noeud suivant
	Joueur leJoueur;	//le joueur
};

#endif