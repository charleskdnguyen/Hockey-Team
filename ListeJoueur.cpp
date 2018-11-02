#include "ListeJoueur.h"
#include "Joueur.h"
#include "NoeudJoueur.h"

ListeJoueur::ListeJoueur() {
	tete = nullptr;
	fin = nullptr;
	taille = 0;
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
void ListeJoueur::retirerCurseurElement(const Joueur& unJoueur) {
	NoeudJoueur* precedent = tete;
	curseur = precedent;
	while (curseur != nullptr && (!(curseur->getJoueur().getNom().compare(unJoueur.getNom()))))
	{
		if (curseur->getJoueur().getNom().compare(unJoueur.getNom())) {
			break;
		}
		precedent = curseur->getSuivant();
		deplacerCurseurSuivant();
	}

	NoeudJoueur *liaison = precedent->getSuivant()->getSuivant();

	/* Supprime l'élément de la liste */
	precedent->setSuivant(liaison);
	/* Détruit l'élément supprimé */
	free(curseur);
}
bool ListeJoueur::elementCurseurValide() const {
	return curseur != nullptr;
}
void ListeJoueur::insererAvantCurseur(const Joueur& unJoueur) {

}

const Joueur& ListeJoueur::obtenirCurseurElement() const {
	return curseur->getJoueur();
}

void ListeJoueur::insererFin(const Joueur& unJoueur) {
	NoeudJoueur *nouveau = new NoeudJoueur; //new NoeudJoueur(unJoueur)???
	nouveau->setJoueur(unJoueur);

	if (tete == nullptr) {
		tete = nouveau;
	} else {
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