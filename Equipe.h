#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>
#include "ListeJoueur.h"

using namespace std;

class Equipe {
public:
	//constructeur par d�faut
	Equipe(const string& nom = "");

	//destructeur
	~Equipe();

	//op�rateur �gale
	const Equipe& operator=(const Equipe& equipe);

	//r�cup�re le nom de l'�quipe
	const string& getNomEquipe() const;

	//r�cup�re la liste de joueur de l'�quipe
	const ListeJoueur& getListeJoueurs() const;

	//set le nom du fichier de l'�quipe
	void setNomfichier(const string& nomfichier);

	//r�cup�re le nom du fichier
	const string& getNomfichier() const;

	//fonction qui va ajouter un joueur dans la liste
	void ajouterJoueur(const Joueur& unJoueur);

	//fonction qui va supprimer un joueur dans la liste
	void retirerJoueur(const Joueur& unJoueur);

	//sauvegarde les fichiers avant de quitter le programme
	void sauvegarder();

private:
	string nomFichier;		//le nom de fichier de chaque �quipe
	string nomEquipe;		//le nom de l'�quipe
	ListeJoueur joueurs;	//la liste de joueur
};

#endif
