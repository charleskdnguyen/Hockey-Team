#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
using namespace std;

class Joueur {
public:
	Joueur(const string& nom = "", float salaire = 0.0f);
	Joueur(const Joueur& j);
	~Joueur();
	
	const Joueur& operator=(const Joueur& unJoueur);

	const string& getNom() const;
	float getSalaire() const;
	void setNom(const string& nom);
	void setSalaire(float salaire);

private:
	string nom;
	float salaire;
};


#endif