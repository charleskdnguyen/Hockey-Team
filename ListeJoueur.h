#ifndef LISTE_JOUEUR_H
#define LISTE_JOUEUR_H

#include "NoeudJoueur.h"

class ListeJoueur {
public:
	//constructeur par défaut
	ListeJoueur();
	ListeJoueur(const ListeJoueur& uneListeJoueur);

	//destructeur
	~ListeJoueur();

	//opérateur égale
	const ListeJoueur& operator=(const ListeJoueur& uneListeJoueur);

	//fonctions de deplacer le curseur au debut de la listejoueur
	void deplacerCurseurDebut() const;

	//fonction de deplacer le curseur au prochain noeud
	void deplacerCurseurSuivant() const;

	//on retire l'element ou le curseur pointe
	void retirerCurseurElement();

	//fonction ou ca retourne "true" tant que le curseur n'est pas nulle
	bool elementCurseurValide() const;

	//fonction pour inserer un noeud avant ou le curseur pointe
	void insererAvantCurseur(const Joueur& unJoueur);

	//fonction qui récupère l'élément ou le curseur pointe
	const Joueur& obtenirCurseurElement() const;

	//fonction qui récupère un élément à l'aide d'un indice
	const Joueur& obtenirElement(int element) const;

	//fonction qui insere un noeud à la fin de la liste
	void insererFin(const Joueur& unJoueur);

	//fonction qui vérifie si la liste est vide
	bool estVide() const;

	//retourne la taille de la liste
	int getTaille() const;


private:
	void viderListe(); //fonction qui vide la liste
	mutable NoeudJoueur* curseur;	//le curseur qui va pointer dépendant des fonctions utilisé
	NoeudJoueur* tete;	//pointe au début de la liste
	NoeudJoueur* fin;   //pointe à la fin de la liste
	int taille;		//la taille de la liste
};

#endif