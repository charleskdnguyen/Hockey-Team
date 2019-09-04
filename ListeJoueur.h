#ifndef LISTE_JOUEUR_H
#define LISTE_JOUEUR_H

#include "NoeudJoueur.h"

class ListeJoueur {
public:
	//constructeur par d�faut
	ListeJoueur();
	ListeJoueur(const ListeJoueur& uneListeJoueur);

	//destructeur
	~ListeJoueur();

	//op�rateur �gale
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

	//fonction qui r�cup�re l'�l�ment ou le curseur pointe
	const Joueur& obtenirCurseurElement() const;

	//fonction qui r�cup�re un �l�ment � l'aide d'un indice
	const Joueur& obtenirElement(int element) const;

	//fonction qui insere un noeud � la fin de la liste
	void insererFin(const Joueur& unJoueur);

	//fonction qui v�rifie si la liste est vide
	bool estVide() const;

	//retourne la taille de la liste
	int getTaille() const;


private:
	void viderListe(); //fonction qui vide la liste
	mutable NoeudJoueur* curseur;	//le curseur qui va pointer d�pendant des fonctions utilis�
	NoeudJoueur* tete;	//pointe au d�but de la liste
	NoeudJoueur* fin;   //pointe � la fin de la liste
	int taille;		//la taille de la liste
};

#endif