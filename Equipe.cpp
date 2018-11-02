#include "Equipe.h"
#include "ListeJoueur.h"

using namespace std;

Equipe::Equipe(const string& nom) {
	this->nomEquipe = nom;
}

Equipe::~Equipe() {
	
}

const Equipe& Equipe::operator=(const Equipe& equipe) {
	//copie de la listejoueur
	this->joueurs = equipe.getListeJoueurs();
	this->nomEquipe = equipe.nomEquipe;
	this->nomFichier = equipe.nomFichier;
	return *this;
}

const string& Equipe::getNomEquipe() const {
	return nomEquipe;
}
const ListeJoueur& Equipe::getListeJoueurs() const {
	return joueurs;
}

void Equipe::setNomfichier(const string& fichier) {
	this->nomFichier = fichier;
}

const string& Equipe::getNomfichier() const {
	return nomFichier;
}

void Equipe::ajouterJoueur(const Joueur& unJoueur) {
	joueurs.insererFin(unJoueur); //classe listejoueur
}
void Equipe::retirerJoueur(const Joueur& unJoueur) {
	joueurs.retirerCurseurElement(unJoueur);
}
void Equipe::sauvegarder() {

}