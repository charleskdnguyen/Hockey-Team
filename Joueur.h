#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
using namespace std;

class Joueur {
public:
	//constructeur par d�faut
	Joueur(const string& nom = "", float salaire = 0.0f);
	Joueur(const Joueur& j);

	//destructeur
	~Joueur();

	//op�rateur �gale
	const Joueur& operator=(const Joueur& unJoueur);

	//retourne le nom du joueur
	const string& getNom() const;

	//retourne le salaire du joueur
	float getSalaire() const;

	//fonction qui va set le nom du joueur
	void setNom(const string& nom);

	//fonction qui va set le salaire du joueur
	void setSalaire(float salaire);

private:
	string nom;
	float salaire;
};


#endif