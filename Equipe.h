#ifndef EQUIPE_H
#define EQUIPE_H

#include <string>
#include "ListeJoueur.h"

using namespace std;

class Equipe {
public:
	Equipe(const string& nom = "");
	~Equipe();

	const Equipe& operator=(const Equipe& equipe);

	const string& getNomEquipe() const;
	const ListeJoueur& getListeJoueurs() const;
	void setNomfichier(const string& nomfichier);
	const string& getNomfichier() const;

	void ajouterJoueur(const Joueur& unJoueur);
	void retirerJoueur(const Joueur& unJoueur);
	void sauvegarder();

private:
	string nomFichier;
	string nomEquipe;
	ListeJoueur joueurs;
};

#endif
