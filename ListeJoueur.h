#ifndef LISTE_JOUEUR_H
#define LISTE_JOUEUR_H

#include "NoeudJoueur.h"

class ListeJoueur {
public:
	ListeJoueur();
	ListeJoueur(const ListeJoueur& uneListeJoueur);
	~ListeJoueur();

	const ListeJoueur& operator=(const ListeJoueur& uneListeJoueur);

	// Fonctions d'utilisation du curseur
	void deplacerCurseurDebut() const;
	void deplacerCurseurSuivant() const;
	void retirerCurseurElement(const Joueur& unJoueur); //tough
	bool elementCurseurValide() const;
	void insererAvantCurseur(const Joueur& unJoueur); //tough
	const Joueur& obtenirCurseurElement() const; //tough

	void insererFin(const Joueur& unJoueur);

	bool estVide() const;
	int getTaille() const;

private:
	void viderListe();
	mutable NoeudJoueur* curseur;
	NoeudJoueur* tete;
	NoeudJoueur* fin;
	int taille;
};

#endif