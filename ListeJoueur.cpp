#include "ListeJoueur.h"
#include "Joueur.h"
#include "NoeudJoueur.h"

ListeJoueur::ListeJoueur() {
	tete = nullptr;
	fin = nullptr;
	taille = 0;
	viderListe();
}
ListeJoueur::ListeJoueur(const ListeJoueur& uneListeJoueur) {
	tete = nullptr;
	fin = nullptr;
	viderListe();

	//copierListe
	NoeudJoueur* tmp = uneListeJoueur.tete;
	while (tmp != nullptr)
	{
		insererFin(tmp->getJoueur());
		tmp = tmp->getSuivant();
	}
	taille = uneListeJoueur.taille;
}
ListeJoueur::~ListeJoueur() {
	viderListe();
}

const ListeJoueur& ListeJoueur::operator=(const ListeJoueur& uneListeJoueur) {
	viderListe();
	NoeudJoueur* tmp = uneListeJoueur.tete;
	while (tmp != nullptr)
	{
		insererFin(tmp->getJoueur());
		tmp = tmp->getSuivant();
	}

	return *this;
}

// Fonctions d'utilisation du curseur
void ListeJoueur::deplacerCurseurDebut() const {
	curseur = tete;

}
void ListeJoueur::deplacerCurseurSuivant() const {
	curseur = curseur->getSuivant();
}
void ListeJoueur::retirerCurseurElement() {
	if (tete->getJoueur().getNom().compare(curseur->getJoueur().getNom()) == 0) {
		tete = curseur->getSuivant();
		free(curseur);
	}
	else {
		NoeudJoueur *previous = tete;
		while (previous != nullptr) {

			if (previous->getSuivant()->getJoueur().getNom().compare(curseur->getJoueur().getNom()) == 0) {
				break;
			}
			previous = previous->getSuivant();
		}


		//previous->setSuivant(previous->getSuivant()->getSuivant()); 
		previous->setSuivant(curseur->getSuivant());
		free(curseur);
	}
	taille--;
}
bool ListeJoueur::elementCurseurValide() const {
	return curseur != nullptr;
}
void ListeJoueur::insererAvantCurseur(const Joueur& unJoueur) {

	if (tete == curseur) {
		NoeudJoueur *nouveauTete = new NoeudJoueur();
		nouveauTete->setJoueur(unJoueur);
		nouveauTete->setSuivant(tete);
		tete = nouveauTete;
	}

	else if (fin == curseur) {
		insererFin(unJoueur);
	}

	else {

		NoeudJoueur *nouveau = new NoeudJoueur();
		nouveau->setJoueur(unJoueur);

		nouveau->setSuivant(curseur->getSuivant());

		Joueur tmp = curseur->getJoueur();

		curseur->setJoueur(nouveau->getJoueur());
		curseur->setSuivant(nouveau);
		nouveau->setJoueur(tmp);
	}

	taille++;

}

const Joueur& ListeJoueur::obtenirCurseurElement() const {
	return curseur->getJoueur();
}

const Joueur& ListeJoueur::obtenirElement(int element) const {
	deplacerCurseurDebut();
	NoeudJoueur *tmp = new NoeudJoueur();
	Joueur j;
	for (int i = 0; i < element; i++)
	{
		deplacerCurseurSuivant();
	}
	return curseur->getJoueur();
}

void ListeJoueur::insererFin(const Joueur& unJoueur) {
	NoeudJoueur *nouveau = new NoeudJoueur;
	nouveau->setJoueur(unJoueur);

	if (tete == nullptr) {
		tete = nouveau;
	}
	else {
		fin->setSuivant(nouveau);
	}

	fin = nouveau;
	taille++;
}

bool ListeJoueur::estVide() const {
	if (tete == nullptr) {
		return false;
	}
	else {
		return true;
	}

}
int ListeJoueur::getTaille() const {
	return taille;
}

void ListeJoueur::viderListe() {
	while (tete != nullptr)
	{
		NoeudJoueur* tmp = tete;
		tete = tete->getSuivant();
		delete tmp;
	}
	fin = nullptr;
	tete = 0;
}