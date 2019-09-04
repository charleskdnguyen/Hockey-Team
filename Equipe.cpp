#include "Equipe.h"
#include "ListeJoueur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
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
	bool trouver = false;

	if (joueurs.getTaille() == 0) {
		joueurs.insererFin(unJoueur); //classe listejoueur
		trouver = true;
	}

	joueurs.deplacerCurseurDebut();

	while (!trouver) {
		if (joueurs.elementCurseurValide()) {
			if (unJoueur.getSalaire() > joueurs.obtenirCurseurElement().getSalaire()) {
				joueurs.insererAvantCurseur(unJoueur);
				trouver = true;
			}
			else {
				joueurs.deplacerCurseurSuivant();
			}
			
		}
		else {
			joueurs.insererFin(unJoueur);
			trouver = true;
			break;
		}
	}
}
void Equipe::retirerJoueur(const Joueur& unJoueur) {
	joueurs.deplacerCurseurDebut();
	while (joueurs.elementCurseurValide()) {
		if (unJoueur.getNom() == joueurs.obtenirCurseurElement().getNom()) {
			break;
		}
		joueurs.deplacerCurseurSuivant();
	}
	joueurs.retirerCurseurElement();
}

void Equipe::sauvegarder() {
	ofstream fichier;
	fichier.open(nomFichier);

	int taille = joueurs.getTaille();
	for (int i = 0; i < taille; i++)
	{
		if (i == 0) {
			//Affiche le nom de l'equipe
			fichier << nomEquipe << endl;
		}
		else {
			fichier << joueurs.obtenirElement(i).getNom() << setw(15) << ";" << setprecision(15) << joueurs.obtenirElement(i).getSalaire() << endl;
		} 
	}
	fichier.close();
}