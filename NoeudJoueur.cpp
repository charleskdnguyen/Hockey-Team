#include "NoeudJoueur.h"

NoeudJoueur::NoeudJoueur() :
	suivant(0)
{

}

NoeudJoueur::NoeudJoueur(const NoeudJoueur& joueur) :
	leJoueur(),
	suivant(0)
{

}

NoeudJoueur::~NoeudJoueur()
{
	//Destructeur
}

//const NoeudJoueur& NoeudJoueur::operator=(const NoeudJoueur& noeud) {
//
//}

void NoeudJoueur::setJoueur(const Joueur& joueur)
{
	this->leJoueur = joueur;
}

void NoeudJoueur::setSuivant(NoeudJoueur* n)
{
	this->suivant = n;
}

NoeudJoueur* NoeudJoueur::getSuivant() const
{
	return suivant;
}

const Joueur& NoeudJoueur::getJoueur() const {
	return leJoueur;
}

Joueur& NoeudJoueur::getJoueur()
{
	return leJoueur;
}
