/*
 * plateau.cpp
 *
 *  Created on: 9 avr. 2015
 *      Author: thomas
 */

#include "plateau.h"
#include <cmath>


using namespace std;

Plateau::Plateau(int h, int l) {
	plateau.resize(l);
	for (int i = 0; i < l; i++) {
		plateau[i].resize(h);
	}
}

void Plateau::ajoute(Piece *p, Position la) {
	int x = la.get_x();
	int y = la.get_y();
	plateau[x][y] = p;
}

void Plateau::deplace(Position la, Position puisla) {
	int x = la.get_x();
	int y = la.get_y();
	int xbis = puisla.get_x();
	int ybis = puisla.get_y();
	plateau[xbis][ybis] = plateau[x][y];
	plateau[x][y] = NULL;
}

int Plateau::getHeight() {
	return plateau.size();
}

int Plateau::getWidth() {
	return plateau[0].size();
}

bool Plateau::estDedans(Position p) {
	if ((((p.x < 0) || (p.x > plateau.size())))
			|| (((p.y < 0) || (p.y > plateau[0].size())))) {
		return 0;
	} else {
		return 1;
	}
}

Piece* Plateau::getPiece(Position p) {
	Piece* piece = plateau[p.get_x()][p.get_y()];
	return (piece);
}

void Plateau::joue(Position la, Position puisla, bool cad) {

	if (estDedans(la) == 0) {
		throw string("ERREUR : Hors du jeu !");
	} else if (estDedans(puisla) == 0) {
		throw string("ERREUR : Hors du jeu !");
	} else if (getPiece(la) == 0) {
		throw string("ERREUR : Pas de piece dans la case de départ!");
	} else if (getPiece(la)->est_noir != cad) {
		throw string("ERREUR : Mauvais choix de couleur !");
	} else if (getPiece(la)->isValidMove(la, puisla, cad, this) == 0) {
		throw string("ERREUR : Mouvement non valide !");
	} else if ((getPiece(puisla) != 0)
				&& (getPiece(puisla)->est_noir == getPiece(la)->est_noir)) {
		throw string("ERREUR : Tentative de cannibalisme !");
	}
	deplace(la, puisla);
}

/*
 *
 *
 * Méthodes du jeu d'Echec
 *
 *
 */

void Echiquier::conditionsInitiales() {
	ajoute(new Pion(false), Position("A2"));
	ajoute(new Pion(false), Position("B2"));
	ajoute(new Pion(false), Position("D2"));
	ajoute(new Pion(false), Position("C2"));
	ajoute(new Pion(false), Position("E2"));
	ajoute(new Pion(false), Position("F2"));
	ajoute(new Pion(false), Position("G2"));
	ajoute(new Pion(false), Position("H2"));
	ajoute(new Tour(false), Position("A1"));
	ajoute(new Tour(false), Position("H1"));
	ajoute(new Cavalier(false), Position("B1"));
	ajoute(new Cavalier(false), Position("G1"));
	ajoute(new Fou(false), Position("C1"));
	ajoute(new Fou(false), Position("F1"));
	ajoute(new Roi(false), Position("E1"));
	ajoute(new Dame(false), Position("D1"));

	ajoute(new Pion(true), Position("A7"));
	ajoute(new Pion(true), Position("B7"));
	ajoute(new Pion(true), Position("D7"));
	ajoute(new Pion(true), Position("C7"));
	ajoute(new Pion(true), Position("E7"));
	ajoute(new Pion(true), Position("F7"));
	ajoute(new Pion(true), Position("G7"));
	ajoute(new Pion(true), Position("H7"));
	ajoute(new Tour(true), Position("A8"));
	ajoute(new Tour(true), Position("H8"));
	ajoute(new Cavalier(true), Position("B8"));
	ajoute(new Cavalier(true), Position("G8"));
	ajoute(new Fou(true), Position("C8"));
	ajoute(new Fou(true), Position("F8"));
	ajoute(new Roi(true), Position("E8"));
	ajoute(new Dame(true), Position("D8"));
}

Echiquier::Echiquier() :
		Plateau(8, 8) {
	conditionsInitiales();
}


void Echiquier::toString() {
	cout << "    A   B   C   D   E   F   G   H  " << endl;
	cout << "   -------------------------------" << endl;
	for (int i = 0; i < plateau.size(); i++) {
		cout << i + 1 << " ";
		for (int j = 0; j < plateau.size(); j++) {
			if (plateau[j][i] != 0) {
				cout << "|" << plateau[j][i]->toString() << " ";
			} else {
				cout << "|   ";
			}

		}
		cout << "| " << i + 1 << endl;
		cout << "   -------------------------------" << endl;
	}
	cout << "    A   B   C   D   E   F   G   H  " << endl << endl << endl;
}

void Echiquier::remove(Position la){
	plateau[la.x][la.y]=0;
}
bool Echiquier::rejoue(Position la, Position puisla, bool a_qui_le_tour) {
	return 0;
}

void Echiquier::Promo(int promu, string demande2, bool a_qui_le_tour) {
	if (promu == 1) {
		this->ajoute(new Dame(a_qui_le_tour), Position(demande2));
	} else if (promu == 2) {
		this->ajoute(new Tour(a_qui_le_tour), Position(demande2));
	} else if (promu == 3) {
		this->ajoute(new Fou(a_qui_le_tour), Position(demande2));
	} else if (promu == 4) {
		this->ajoute(new Cavalier(a_qui_le_tour), Position(demande2));
	}
}

void Echiquier::PetitRoque(bool a_qui_le_tour) {
	if (a_qui_le_tour == 0) {

				this->ajoute(new Tour(false), Position("F1"));
				this->ajoute(new Roi(false), Position("G1"));
				this->remove(Position("E1"));
				this->remove(Position("H1"));
				this->toString();

	}


	if (a_qui_le_tour == 1) {

				this->ajoute(new Tour(false), Position("F8"));
				this->ajoute(new Roi(false), Position("G8"));
				this->remove(Position("E8"));
				this->remove(Position("H8"));
				this->toString();




}
	}

void Echiquier::GrandRoque(bool a_qui_le_tour) {
	if (a_qui_le_tour == 0) {

				this->ajoute(new Tour(false), Position("D1"));
				this->ajoute(new Roi(false), Position("C1"));
				this->remove(Position("E1"));
				this->remove(Position("A1"));
				this->toString();

	}
	if (a_qui_le_tour == 1) {

				this->ajoute(new Tour(false), Position("D8"));
				this->ajoute(new Roi(false), Position("C8"));
				this->remove(Position("E8"));
				this->remove(Position("A8"));
				this->toString();


	}
}



/*
 *
 *
 *   Méthodes du jeu de Dames
 *
 *
 */




Damier::Damier() :
			Plateau(10, 10) {
	conditionsInitiales();
}

void Damier::conditionsInitiales() {

	 ajoute(new Jeton(true), Position("A10"));
	 ajoute(new Jeton(true), Position("C10"));
	 ajoute(new Jeton(true), Position("E10"));
	 ajoute(new Jeton(true), Position("G10"));
	 ajoute(new Jeton(true), Position("I10"));
	 ajoute(new Jeton(true), Position("B9"));
	 ajoute(new Jeton(true), Position("D9"));
	 ajoute(new Jeton(true), Position("F9"));
	 ajoute(new Jeton(true), Position("H9"));
	 ajoute(new Jeton(true), Position("J9"));
	 ajoute(new Jeton(true), Position("A8"));
	 ajoute(new Jeton(true), Position("C8"));
	 ajoute(new Jeton(true), Position("E8"));
	 ajoute(new Jeton(true), Position("G8"));
	 ajoute(new Jeton(true), Position("I8"));
	 ajoute(new Jeton(true), Position("B7"));
	 ajoute(new Jeton(true), Position("D7"));
	 ajoute(new Jeton(true), Position("F7"));
	 ajoute(new Jeton(true), Position("H7"));
	 ajoute(new Jeton(true), Position("J7"));

	 ajoute(new Jeton(false), Position("B1"));
	 ajoute(new Jeton(false), Position("D1"));
	 ajoute(new Jeton(false), Position("F1"));
	 ajoute(new Jeton(false), Position("H1"));
	 ajoute(new Jeton(false), Position("J1"));
	 ajoute(new Jeton(false), Position("A2"));
	 ajoute(new Jeton(false), Position("C2"));
	 ajoute(new Jeton(false), Position("E2"));
	 ajoute(new Jeton(false), Position("G2"));
	 ajoute(new Jeton(false), Position("I2"));
	 ajoute(new Jeton(false), Position("B3"));
	 ajoute(new Jeton(false), Position("D3"));
	 ajoute(new Jeton(false), Position("F3"));
	 ajoute(new Jeton(false), Position("H3"));
	 ajoute(new Jeton(false), Position("J3"));
	 ajoute(new Jeton(false), Position("A4"));
	 ajoute(new Jeton(false), Position("C4"));
	 ajoute(new Jeton(false), Position("E4"));
	 ajoute(new Jeton(false), Position("G4"));
	 ajoute(new Jeton(false), Position("I4"));


}

void Damier::toString() {
	cout << "     A   B   C   D   E   F   G   H   I   J" << endl;
	cout << "    ---------------------------------------" << endl;
	for (int i = 0; i < plateau.size(); i++) {
		if (i >= 9) {
			cout << i + 1 << " ";
		} else {
			cout << i + 1 << "  ";
		}
		for (int j = 0; j < plateau.size(); j++) {
			if (plateau[j][i] != 0) {
				cout << "|" << plateau[j][i]->toString() << " ";
			} else {
				cout << "|   ";
			}

		}
		cout << "| " << i + 1 << endl;
		cout << "    ---------------------------------------" << endl;
	}
	cout << "     A   B   C   D   E   F   G   H   I   J" << endl << endl
			<< endl;
}

void Damier::remove(Position la) {
	plateau[la.x][la.y] = 0;
}

bool Damier::rejoue(Position la, Position puisla, bool a_qui_le_tour) {
	if ((fabs(la.x - puisla.x) == 2)
			&& (((puisla.x + 2) < 10) && ((puisla.y + 2) < 10)
					&& (this->getPiece(Position(puisla.x + 2, puisla.y + 2)) == 0
							&& (this->getPiece(
									Position(puisla.x + 1, puisla.y + 1)) != 0)
							&& this->getPiece(
									Position(puisla.x + 1, puisla.y + 1))->est_noir
									!= a_qui_le_tour)
					|| (((puisla.x - 2) >= 0) && ((puisla.y + 2) < 10)
							&& (this->getPiece(
									Position(puisla.x - 2, puisla.y + 2)) == 0
									&& (this->getPiece(
											Position(puisla.x - 1,
													puisla.y + 1)) != 0)
									&& this->getPiece(
											Position(puisla.x - 1,
													puisla.y + 1))->est_noir
											!= a_qui_le_tour))
					|| (((puisla.x + 2) < 10) && ((puisla.y - 2) >= 0)
							&& (this->getPiece(
									Position(puisla.x + 2, puisla.y - 2)) == 0
									&& (this->getPiece(
											Position(puisla.x + 1,
													puisla.y - 1)) != 0)
									&& this->getPiece(
											Position(puisla.x + 1,
													puisla.y - 1))->est_noir
											!= a_qui_le_tour))
					|| (((puisla.x - 2) >= 0) && ((puisla.y - 2) >= 0)
							&& (this->getPiece(
									Position(puisla.x - 2, puisla.y - 2)) == 0
									&& (this->getPiece(
											Position(puisla.x - 1,
													puisla.y - 1)) != 0)
									&& this->getPiece(
											Position(puisla.x - 1,
													puisla.y - 1))->est_noir
											!= a_qui_le_tour)))) {
		return 1;
	}
	else{
		return 0;
	}
}

void Damier::Promo(int promu, string demande2, bool a_qui_le_tour) {
	if (a_qui_le_tour == 1) {
		if (demande2 == "A1" || demande2 == "B1" //detection du changement du pion en dame
		|| demande2 == "C1" || demande2 == "D1" || demande2 == "E1"
				|| demande2 == "F1" || demande2 == "G1" || demande2 == "H1"
				|| demande2 == "I1" || demande2 == "J1") {
			this->ajoute(new SuperJeton(a_qui_le_tour), //Changement du pion en dame
			Position(demande2));
		}
	}
	else if( a_qui_le_tour == 0)
		if (demande2 == "A10" || demande2 == "B10"     //detection du changement du pion en dame
			|| demande2 == "C10" || demande2 == "D10"
			|| demande2 == "E10" || demande2 == "F10"
			|| demande2 == "G10" || demande2 == "H10"
			|| demande2 == "I10" || demande2 == "J10") {
		this->ajoute(new SuperJeton(a_qui_le_tour),     //Changement du pion en dame
				Position(demande2));
	}
}
