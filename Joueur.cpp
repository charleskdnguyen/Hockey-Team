#include "Joueur.h"

using namespace std;

Joueur::Joueur(const string& nom, float salaire) {
	this->nom = nom;
	this->salaire = salaire;
}
Joueur::Joueur(const Joueur& j) {
	nom = j.nom;
	salaire = j.salaire;
}
Joueur::~Joueur() {

}

const Joueur& Joueur::operator=(const Joueur& unJoueur) {
	this->nom = unJoueur.nom;
	this->salaire = unJoueur.salaire;
	return *this;
}

const string& Joueur::getNom() const {
	return nom;
}
float Joueur::getSalaire() const {
	return salaire;
}
void Joueur::setNom(const string& nom) {
	this->nom = nom;
}
void Joueur::setSalaire(float salaire) {
	this->salaire = salaire;
}