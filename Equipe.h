#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>
#include "ListeJoueur.h"

using namespace std;

class Equipe {
public:
	//constructeur par défaut
	Equipe(const string& nom = "");

	//destructeur
	~Equipe();

	//opérateur égale
	const Equipe& operator=(const Equipe& equipe);

	//récupère le nom de l'équipe
	const string& getNomEquipe() const;

	//récupère la liste de joueur de l'équipe
	const ListeJoueur& getListeJoueurs() const;

	//set le nom du fichier de l'équipe
	void setNomfichier(const string& nomfichier);

	//récupère le nom du fichier
	const string& getNomfichier() const;

	//fonction qui va ajouter un joueur dans la liste
	void ajouterJoueur(const Joueur& unJoueur);

	//fonction qui va supprimer un joueur dans la liste
	void retirerJoueur(const Joueur& unJoueur);

	//sauvegarde les fichiers avant de quitter le programme
	void sauvegarder();

private:
	string nomFichier;		//le nom de fichier de chaque équipe
	string nomEquipe;		//le nom de l'équipe
	ListeJoueur joueurs;	//la liste de joueur
};

#endif
