/*
 * main.cpp
 *
 *  Created on: 9 avr. 2015
 *      Author: thomas
 */
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include "plateau.h"
#include "piece.h"
#include "position.h"

using namespace std;

int main() {

	int choix = 0;
	/*
	 *
	 * 						Ecran d'acceuil
	 *
	 */

	cout << "A quel jeux voulez-vous jouer?" << endl;
	cout << "Jeu d'Echec, taper 1" << endl;
	cout << "Jeu de Dames, taper 2" << endl;
	cin >> choix;

	/*
	 *
	 *               	      JEU D'ECHEC
	 *
	 */
	if (choix == 1) {
		Echiquier ech;
		ech.toString();

		string demande1 = "ok";
		string demande2 = "ok";
		bool a_qui_le_tour = 0;
		bool ptiroque = 0, grdroque = 0;

		while (demande1 != "quit") {

			if (a_qui_le_tour == 0) {

				if (ech.getPiece(Position("E1")) != 0//detection du petit roque
				&& ech.getPiece(Position("E1"))->toString() == "ro"
						&& ech.getPiece(Position("F1")) == 0
						&& ech.getPiece(Position("G1")) == 0
						&& ech.getPiece(Position("H1")) != 0
						&& ech.getPiece(Position("H1"))->toString() == "to") {
					cout << "Voulez vous effectuer le petit roque?" << endl;//Propose au joueur de valider le petit roque
					cout << "Si oui, tapez 1" << endl;
					cout << "Si non, tapez 0" << endl;
					cin >> ptiroque;
					if (ptiroque == 1) {
						ech.PetitRoque(a_qui_le_tour);
						a_qui_le_tour = 1;

					} else {
						a_qui_le_tour = 0;
					}
				}
				if (a_qui_le_tour == 0 && ech.getPiece(Position("E1")) != 0
						&& ech.getPiece(Position("E1"))->toString() == "ro" //detection du grand roque
						&& ech.getPiece(Position("D1")) == 0
						&& ech.getPiece(Position("C1")) == 0
						&& ech.getPiece(Position("B1")) == 0
						&& ech.getPiece(Position("A1")) != 0
						&& ech.getPiece(Position("A1"))->toString() == "to") {
					cout << "Voulez vous effectuer le grand roque?" << endl; //Propose au joueur de valider le grand roque
					cout << "Si oui, tapez 1" << endl;
					cout << "Si non, tapez 0" << endl;
					cin >> grdroque;
					if (grdroque == 1) {
						ech.GrandRoque(a_qui_le_tour);
						a_qui_le_tour = 1;

					} else {
						a_qui_le_tour = 0;
					}
				}

				if (a_qui_le_tour == 0) {
					cout << "              White" << endl;
					cout << "          Quelle piece?" << endl;
					cin >> demande1;
					if (demande1 == "quit") {
						break;
					}
					cout << "          Quel mouvement?" << endl;
					cin >> demande2;
					cout << endl;

					try {
						ech.joue(Position(demande1), Position(demande2),
								a_qui_le_tour);
						if ((demande2 == "A8" || demande2 == "B8" //Détection de promotion du pion
						|| demande2 == "C8" || demande2 == "D8"
								|| demande2 == "E8" || demande2 == "F8"
								|| demande2 == "G8" || demande2 == "H8")
								&& ech.getPiece(Position(demande2))->toString()
										== "pi") {
							int promu = 0;
							int verif = 0;
							do {
								cout << "Votre Pion est promu" << endl;	//demande au joueur quelle est son choix de promotion
								cout
										<< "Tapez le chiffre correspondant à votre choix de promotion :"
										<< endl;
								cout << "1: Dame" << endl;
								cout << "2: Tour" << endl;
								cout << "3: Fou" << endl;
								cout << "4: Cavalier" << endl;
								cin >> promu;

								if (promu == 1 || promu == 2 || promu == 3
										|| promu == 4) {
									verif = 1;

								} else {
									cout << "Je n'ai pas compris votre choix"
											<< endl;
								}

							} while (verif != 1);

							ech.Promo(promu, demande2, a_qui_le_tour);
						}
						ech.toString();
						a_qui_le_tour = 1;
					} catch (string const& chaine) {
						cerr << chaine << endl;
					}
				}

			} else if (a_qui_le_tour == 1) {

				if (ech.getPiece(Position("E8")) != 0
						&& ech.getPiece(Position("E8"))->toString() == "Ro" //detéction du petit roque
						&& ech.getPiece(Position("F8")) == 0
						&& ech.getPiece(Position("G8")) == 0
						&& ech.getPiece(Position("H8")) != 0
						&& ech.getPiece(Position("H8"))->toString() == "To") {
					cout << "Voulez vous effectuer le petit roque?" << endl;//Propose au joueur de valider le petit roque
					cout << "Si oui, tapez 1" << endl;
					cout << "Si non, tapez 0" << endl;
					cin >> ptiroque;
					if (ptiroque == 1) {
						ech.PetitRoque(a_qui_le_tour);
						a_qui_le_tour = 0;
					} else {
						a_qui_le_tour = 1;
					}
				}
				if (a_qui_le_tour == 1 && ech.getPiece(Position("E8")) != 0
						&& ech.getPiece(Position("E8"))->toString() == "Ro" //detection du grand roque
						&& ech.getPiece(Position("D8")) == 0
						&& ech.getPiece(Position("C8")) == 0
						&& ech.getPiece(Position("B8")) == 0
						&& ech.getPiece(Position("A8")) != 0
						&& ech.getPiece(Position("A8"))->toString() == "To") {
					cout << "Voulez vous effectuer le grand roque?" << endl; //Propose au joueur de valider le grand roque
					cout << "Si oui, tapez 1" << endl;
					cout << "Si non, tapez 0" << endl;
					cin >> grdroque;
					if (grdroque == 1) {
						ech.GrandRoque(a_qui_le_tour);
						a_qui_le_tour = 0;
					} else {
						a_qui_le_tour = 1;
					}

				}

				if (a_qui_le_tour == 1) {
					cout << "              Black" << endl;
					cout << "          Quelle piece?" << endl;
					cin >> demande1;
					if (demande1 == "quit") {
						break;
					}
					cout << "          Quel mouvement?" << endl;
					cin >> demande2;
					cout << endl;

					try {
						ech.joue(Position(demande1), Position(demande2),
								a_qui_le_tour);
						if ((demande2 == "A1" || demande2 == "B1" //Promotion du pion
						|| demande2 == "C1" || demande2 == "D1"
								|| demande2 == "E1" || demande2 == "F1"
								|| demande2 == "G1" || demande2 == "H1")
								&& ech.getPiece(Position(demande2))->toString()
										== "Pi") {
							int promu = 0;
							int verif = 0;
							do {
								cout << "Votre Pion est promu" << endl;	//demande au joueur quelle est son choix de promotion
								cout
										<< "Tapez le chiffre correspondant à votre choix de promotion :"
										<< endl;
								cout << "1: Dame" << endl;
								cout << "2: Tour" << endl;
								cout << "3: Fou" << endl;
								cout << "4: Cavalier" << endl;
								cin >> promu;

								if (promu == 1 || promu == 2 || promu == 3
										|| promu == 4) {
									verif = 1;

								} else {
									cout << "Je n'ai pas compris votre choix"
											<< endl;
								}

							} while (verif == 0);

							ech.Promo(promu, demande2, a_qui_le_tour);
						}
						ech.toString();
						a_qui_le_tour = 0;
					} catch (string const& chaine) {
						cerr << chaine << endl;
					}
				}
			}
		}

	} else if (choix == 2) {

		/*
		 *
		 *                      JEU DE DAME
		 *
		 */

		Damier dam;
		Position la(0, 0);
		Position puisla(0, 0);
		bool rejou = 0;
		string demande1 = "ok";
		string demande2 = "ok";
		bool a_qui_le_tour = 0;

		dam.toString();

		while (demande1 != "quit") {

			if (a_qui_le_tour == 0) {
				do {
					cout << "              Blanc" << endl;
					if (rejou == 1) {//Si le joueur vient de "manger" un pion adverse et qu'il y a une possibilité de "manger" un autre pion adverse, alors il est obligé de le manger
						cout << "   Vous devez continuer à jouer" << endl;
						demande1 = demande2;
						cout
								<< "         Quel mouvement?(entrez juste la destination)" //On force le joueur a continuer à utiliser son mpeme pion pour manger le pion adverse non protégé
								<< endl;
						cin >> demande2;
						cout << endl;
					} else {                                        //Jeu normal
						cout << "          Quelle piece?" << endl;
						cin >> demande1;
						if (demande1 == "quit") {
							break;
						}

						cout << "         Quel mouvement?" << endl;
						cin >> demande2;
						cout << endl;
					}
					la = Position(demande1);
					puisla = Position(demande2);

					try {
						dam.joue(Position(demande1), Position(demande2),
								a_qui_le_tour);

						if (dam.rejoue(la, puisla, a_qui_le_tour) == 1) { //detection d'un pion adverse non protégé aprés avoir joué et deja mangé un pion adverse
							rejou = 1;
						} else {
							rejou = 0;
						}
						/*if (demande2 == "A10" || demande2 == "B10"     //detection du changement du pion en dame
						 || demande2 == "C10" || demande2 == "D10"
						 || demande2 == "E10" || demande2 == "F10"
						 || demande2 == "G10" || demande2 == "H10"
						 || demande2 == "I10" || demande2 == "J10") {
						 dam.ajoute(new SuperJeton(a_qui_le_tour),     //Changement du pion en dame
						 Position(demande2));
						 }*/
						dam.Promo(1, demande2, a_qui_le_tour);

						dam.toString();
						if (rejou == 0) {
							a_qui_le_tour = 1;
						}
					} catch (string const& chaine) {
						cerr << chaine << endl;
					}
				} while (rejou == 1);
			} else {
				do {
					cout << "              Noir" << endl;
					if (rejou == 1) {//Si le joueur vient de "manger" un pion adverse et qu'il y a une possibilité de "manger" un autre pion adverse, alors il est obligé de le manger
						cout << "   Vous devez continuer à jouer" << endl;
						demande1 = demande2;
						cout
								<< "         Quel mouvement?(entrez juste la destination)" //On force le joueur a continuer à utiliser son même pion pour manger le pion adverse non protégé
								<< endl;
						cin >> demande2;
						cout << endl;
					} else {
						cout << "          Quelle piece?" << endl;
						cin >> demande1;
						if (demande1 == "quit") {
							break;
						}
						cout << "         Quel mouvement?" << endl;
						cin >> demande2;
						cout << endl;
					}
					la = Position(demande1);
					puisla = Position(demande2);
					try {
						dam.joue(Position(demande1), Position(demande2),
								a_qui_le_tour);
						if (dam.rejoue(la, puisla, a_qui_le_tour) == 1) { //detection d'un pion adverse non protégé aprés avoir joué et deja mangé un pion adverse
							rejou = 1;
						} else {
							rejou = 0;
						}
						/*if (demande2 == "A1" || demande2 == "B1"      //detection du changement du pion en dame
						 || demande2 == "C1" || demande2 == "D1"
						 || demande2 == "E1" || demande2 == "F1"
						 || demande2 == "G1" || demande2 == "H1"
						 || demande2 == "I1" || demande2 == "J1") {
						 dam.ajoute(new SuperJeton(a_qui_le_tour),    //Changement du pion en dame
						 Position(demande2));
						 }*/

						dam.Promo(1, demande2, a_qui_le_tour);

						dam.toString();
						if (rejou == 0) {
							a_qui_le_tour = 0;
						}
					} catch (string const& chaine) {
						cerr << chaine << endl;
					}
				} while (rejou == 1);
			}
		}
	}
	return 0;
}

