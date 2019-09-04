#include <iostream>
#include <iomanip>
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
void salaireTotal(const ListeEquipe& lesEquipes);
void affichageEquipe(const ListeEquipe& lesEquipes);
void ajouterJoueur(ListeEquipe& listeEquipe);
void retirerJoueur(ListeEquipe& listeEquipe);

void main() {
	int choix;		//le choix de l'utilisateur
	ListeEquipe lesEquipes;		//la liste d'equipes
	Equipe uneEquipe;		//chaques equipes
	Joueur unJoueur;		//le joueur qui sera inserer dans une equipe
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
		int i = 0;
		getline(ficListeEquipe, lectureEquipe);
		string nomEquipe = lectureEquipe;
		//uneEquipe.setNomfichier(nomEquipe);

		//LECTURE DE CHAQUE LIGNE DE JOUEURS DANS UNE EQUIPE
		if (lectureEquipe != "") { //BOSTON ET LASVEGAS TXT
			ifstream joueur(lectureEquipe); //FICHIER AVEC LA LISTE DE JOUEUR

			getline(joueur, chaineLigne);
			uneEquipe = chaineLigne;

			//boucle qui insere un joueur dans l'equipe
			while (!joueur.eof()) {
				getline(joueur, chaineLigne, ';'); //LIT LE NOM DU JOUEUR JUSQU'AU ;
				unJoueur.setNom(chaineLigne);

				getline(joueur, chaineLigne); //LIT LE SALAIRE DU JOUEUR JUSQU'A LA FIN DE LIGNE
				float salaireFloat = stof(chaineLigne);
				unJoueur.setSalaire(salaireFloat);
				uneEquipe.ajouterJoueur(unJoueur);
			}

			uneEquipe.setNomfichier(nomEquipe);
			lesEquipes.insererFin(uneEquipe);
			joueur.close();
		}
		i++;
	}
	ficListeEquipe.close();

	//fonctions de chaque option
	while (!quitter)
	{
		afficherMenu();
		choix = determinerChoix();
		switch (choix)
		{
		case 1:
			salaireTotal(lesEquipes);
			break;
		case 2:
			affichageEquipe(lesEquipes);
			break;
		case 3:
			ajouterJoueur(lesEquipes);
			break;
		case 4:
			retirerJoueur(lesEquipes);
			break;
		case 5:
			quitter = true;

			//la fonction sauvegarde les donnees dans les fichiers respectifs mais ne re-ouvre pas
			/*for (int i = 0; i < lesEquipes.getTaille(); i++)
			{
				lesEquipes.obtenirEquipe(0).sauvegarder();
			}*/
			
			break;
		}
	}
	//sauvegarder et ecraser les données sur les equipes
	system("pause");
}

//affichage du menu
void afficherMenu() {
	cout << "Veuillez choisir parmis les options suivantes:\n"
		<< "1) Afficher la masse salariale des équipes\n"
		<< "2) Afficher une équipe\n"
		<< "3) Ajouter un joueur\n"
		<< "4) Retirer un joueur\n"
		<< "5) Quitter\n"
		<< endl;
}

//lecture de l'entré de l'utilisateur
int determinerChoix() {
	int choix = lireEntier("Entrez votre choix (entre 1 et 5)", 1, 5);
	return choix;
}

//affichage des joueurs de chaques équipes
void affichageEquipe(const ListeEquipe& listeEquipe) {

	//affichage de la liste d'équipe
	int taille = listeEquipe.getTaille();
	for (int i = 0; i < taille; i++)
	{
		cout << i + 1 << ") " << listeEquipe.obtenirEquipe(i).getNomEquipe() << endl;
	}

	int choix = lireEntier("Choisissez votre équipe", 1, taille);
	choix = choix - 1;


	ListeJoueur l = listeEquipe.obtenirEquipe(choix).getListeJoueurs();
	l.deplacerCurseurDebut();
	int tailleEquipe = listeEquipe.obtenirEquipe(choix).getListeJoueurs().getTaille();

	for (int i = 0; i < tailleEquipe; i++)
	{
		cout << left << setw(25) << l.obtenirCurseurElement().getNom() << setw(5) << setprecision(15) << right << std::setw(20) << l.obtenirCurseurElement().getSalaire() << endl;
		l.deplacerCurseurSuivant();
	}
	cout << endl;
}

//fonction qui ajoute un joueur
void ajouterJoueur(ListeEquipe& listeEquipe) {
	int taille = listeEquipe.getTaille();
	for (int i = 0; i < taille; i++)
	{
		cout << i + 1 << ") " << listeEquipe.obtenirEquipe(i).getNomEquipe() << endl;
	}

	int choix = lireEntier("Choisissez le nom de l'équipe du joueur", 1, taille);
	choix = choix - 1;

	Joueur nouveauJoueur;
	string nom;
	float salaire;

	cout << "Entrez le nom du joueur: " << endl;
	cin >> nom;
	nouveauJoueur.setNom(nom);
	cout << "Entrez le salaire du joueur: " << endl;
	cin >> salaire;
	nouveauJoueur.setSalaire(salaire);
	listeEquipe.obtenirEquipe(choix).ajouterJoueur(nouveauJoueur);
}

//fonction qui retire un joueur
void retirerJoueur(ListeEquipe& listeEquipe) {
	int taille = listeEquipe.getTaille();
	for (int i = 0; i < taille; i++)
	{
		cout << i + 1 << ") " << listeEquipe.obtenirEquipe(i).getNomEquipe() << endl;
	}

	int choix = lireEntier("Entrez l'équipe d'origine du joueur", 1, taille);
	choix = choix - 1;

	ListeJoueur l = listeEquipe.obtenirEquipe(choix).getListeJoueurs();
	l.deplacerCurseurDebut();
	int tailleEquipe = listeEquipe.obtenirEquipe(choix).getListeJoueurs().getTaille();

	for (int i = 0; i < tailleEquipe; i++)
	{
		cout << i + 1 << ") " << l.obtenirCurseurElement().getNom() << endl;
		l.deplacerCurseurSuivant();
	}

	cout << "Quel joueur voulez-vous retirer?: " << endl;
	int choixJoueur = lireEntier("Choisissez votre équipe", 1, tailleEquipe);
	choixJoueur = choixJoueur - 1;

	l.deplacerCurseurDebut();
	Joueur j = listeEquipe.obtenirEquipe(choix).getListeJoueurs().obtenirElement(choixJoueur);
	listeEquipe.obtenirEquipe(choix).retirerJoueur(j);
}

//fonction qui calcule la masse salariale des equipes
void salaireTotal(const ListeEquipe& listeEquipe) {
	int taille = listeEquipe.getTaille();
	for (int i = 0; i < taille; i++)
	{
		ListeJoueur l = listeEquipe.obtenirEquipe(i).getListeJoueurs();
		l.deplacerCurseurDebut();
		int tailleEquipe = listeEquipe.obtenirEquipe(i).getListeJoueurs().getTaille();
		float total = 0;
		string nom = listeEquipe.obtenirEquipe(i).getNomEquipe();

		for (int i = 0; i < tailleEquipe; i++)
		{
			total += l.obtenirCurseurElement().getSalaire();
			l.deplacerCurseurSuivant();
		}

		cout << left << "La masse salariale de " << setw(10) << nom << setw(10) << setprecision(15) << right << std::setw(20) << total << endl;
		total = 0;
	}
	cout << endl;
}