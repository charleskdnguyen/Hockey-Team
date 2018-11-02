#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <ostream>
#include <Windows.h>
#include <clocale>
#include <iomanip>
#include "ListeJoueur.h"
#include "ListeEquipe.h"
#include "Joueur.h"
#include "Equipe.h"
#include "NoeudJoueur.h"
#include "UtilitairesES.h"


using namespace std;

void afficherMenu();
int determinerChoix();
float salaireTotal(float total, float salaireFloat);
void affichageEquipe(ListeEquipe& lesEquipes); //ajouter const

void main() {
	int choix;
	ListeEquipe lesEquipes;
	Equipe uneEquipe;
	Joueur unJoueur;
	bool quitter = false;

	setlocale(LC_ALL, "");

	ifstream ficListeEquipe("equipes.txt");
	string lectureEquipe; //NOMS DES EQUIPES
	string chaineLigne; //LECTURE LIGNE PAR LIGNE DANS LA LISTE DE JOUEUR

	//SI L'OUVERTURE DU FICHIER NE FONCTIONNE PAS
	if (ficListeEquipe.fail()) {
		cout << "L'ouverture n'a pas reussi." << endl;
	}

	//LECTURE DE CHAQUES LIGNES DANS LE FICHIER EQUIPES.TXT
	while (!ficListeEquipe.eof()) { //EQUIPES.txt
		getline(ficListeEquipe, lectureEquipe);

		uneEquipe.setNomfichier(lectureEquipe);

		//if (ficListeEquipe.good()) {
		//LECTURE DE CHAQUE LIGNE DE JOUEURS DANS UNE EQUIPE
		if (lectureEquipe != "") { //BOSTON ET LASVEGAS TXT
			ifstream joueur(lectureEquipe); //FICHIER AVEC LA LISTE DE JOUEUR

			getline(joueur, chaineLigne);
			uneEquipe = chaineLigne;

			while (!joueur.eof()) {
				getline(joueur, chaineLigne, ';'); //LIT LE NOM DU JOUEUR JUSQU'AU ;
				unJoueur.setNom(chaineLigne);

				getline(joueur, chaineLigne); //LIT LE SALAIRE DU JOUEUR JUSQU'A LA FIN DE LIGNE
				float salaireFloat = stof(chaineLigne);
				unJoueur.setSalaire(salaireFloat);
				uneEquipe.ajouterJoueur(unJoueur);

				//float total = 0;
				//cout << "Salaire: " << setprecision(10) << salaireFloat << endl;
				//total += salaireFloat;
				//cout << setprecision(10) << total << endl;
			}

			lesEquipes.insererFin(uneEquipe);
			joueur.close();
		}
	}

	while (!quitter)
	{
		afficherMenu();
		choix = determinerChoix();
		switch (choix)
		{
		case 1:
			break;
		case 2:
			affichageEquipe(lesEquipes);
			break;
		case 3:

			break;
		case 4:

			break;
		case 5:
			quitter = true;
			break;
		}
		ficListeEquipe.close();


	}
	//sauvegarder et ecraser les données sur les equipes
	system("pause");
}

void afficherMenu() {
	cout << "Veuillez choisir parmis les options suivantes:\n"
		<< "1) Afficher la masse salariale des équipes\n"
		<< "2) Afficher une équipe\n"
		<< "3) Ajouter un joueur\n"
		<< "4) Retirer un joueur\n"
		<< "5) Quitter\n"
		<< endl;
}

int determinerChoix() {
	int choix = lireEntier("Entrez votre choix (entre 1 et 5)", 1, 5);
	return choix;
}

void affichageEquipe(ListeEquipe& listeEquipe) {
	int taille = listeEquipe.getTaille();
	for (int i = 0; i < taille; i++)
	{
		cout << i + 1 << ") " << listeEquipe.obtenirEquipe(i).getNomEquipe() << endl;
	}

	int choix = lireEntier("Choisissez votre équipe", 1, taille);
	choix = choix - 1;

	ListeJoueur l = listeEquipe.obtenirEquipe(0).getListeJoueurs();
	l.deplacerCurseurDebut();

	int tailleBoston = listeEquipe.obtenirEquipe(0).getListeJoueurs().getTaille();
	int tailleLv = listeEquipe.obtenirEquipe(1).getListeJoueurs().getTaille();

	if (choix == 0) {
		for (int i = 0; i < 5; i++)
		{
			l.obtenirCurseurElement().getNom();
			l.deplacerCurseurSuivant();
		}
	} /*else if (choix == 1) {
		for (int i = 0; i < 20; i++)
		{
			cout << listeEquipe.obtenirEquipe(choix).getListeJoueurs().obtenirCurseurElement().getNom() << endl;
			listeEquipe.obtenirEquipe(choix).getListeJoueurs().deplacerCurseurSuivant();
		}*/
	

	/*for (int i = 0; i < l.getTaille(); i++)
	{
		cout << l.obtenirCurseurElement().getNom() << setw(15) << setprecision(10) << l.obtenirCurseurElement().getSalaire() << endl;
		l.deplacerCurseurSuivant();
	}*/
}

float salaireTotal(float total, float salaireFloat) {
	total += salaireFloat;

	return total;
}
