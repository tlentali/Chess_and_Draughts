/*
 * piece.cpp
 *
 *  Created on: 9 avr. 2015
 *      Author: thomas
 */

#include <cmath>
#include "piece.h"

using namespace std;

Piece::Piece(bool a, string b) {
	nom = b;
	est_noir = a;
}

string Piece::toString() {
	string lettre1, lettre2, nomfinal;
	lettre1 = nom[0];
	lettre2 = nom[1];
	if (est_noir == 1) {
		lettre1 = toupper(nom[0]);
	}
	nomfinal = lettre1 + lettre2;
	return nomfinal;
}

Pion::Pion(bool a) :
		Piece(a, "pion") {
	est_noir = a;
	firstMove = true;
}

bool Pion::isValidMove(Position prec, Position actu, bool cap, Plateau *board) {
	//valide le mouvement si c'est la premiere fois que l'on utilise un pion blanc
	if (firstMove == true && ((prec.x == actu.x) && (actu.y == prec.y + 2))
			&& (board->getPiece(actu)==0)
			&& (board->getPiece(Position(prec.x, prec.y+1))==0)
			&& (est_noir == 0)
					) {
		firstMove = false;
		return 1;
	} else if (((prec.x == actu.x) && (actu.y == prec.y + 1))
			&& (board->getPiece(actu)==0)
			&& (est_noir == 0)
			) {
		firstMove = false;
		return 1;

	} else if((prec.x +1== actu.x)
			&&(prec.y+1 == actu.y)
			&& (est_noir == 0)
			&&(board->getPiece(actu)!=0)
			&&(board->getPiece(actu)->est_noir==1)){
		return 1;
	}
	else if((prec.x-1 == actu.x)
				&&(prec.y +1== actu.y)
				&& (est_noir == 0)
				&&(board->getPiece(actu)!=0)
				&&(board->getPiece(actu)->est_noir == 1)){
			return 1;
		}

	//valide le mouvement si c'est la premiere fois que l'on utilise un pion noir
	else if (firstMove == true
			&& ((prec.x == actu.x) && (actu.y == prec.y - 2))
			&& (board->getPiece(actu)==0)
			&& (board->getPiece(Position(prec.x, prec.y-1))==0)
			&& (est_noir == 1)
			) {
		firstMove = false;
		return 1;
	} else if (((prec.x == actu.x) && (actu.y == prec.y - 1))
			&& (board->getPiece(actu)==0)
			&& (est_noir == 1)
			) {
		firstMove = false;
		return 1;
	}else if((prec.x -1== actu.x)
			&&(prec.y-1 == actu.y)
			&& (est_noir == 1)
			&&(board->getPiece(actu)!=0)
			&&(board->getPiece(actu)->est_noir==0)){
		return 1;
	}
	else if((prec.x+1 == actu.x)
				&&(prec.y -1== actu.y)
				&&(est_noir == 1)
				&&(board->getPiece(actu)!=0)
				&&(board->getPiece(actu)->est_noir == 0)
				){
			return 1;
		}
	else {
		return 0;
	}
}

Fou::Fou(bool a) :
		Piece(a, "fou") {
	est_noir = a;
}

bool Fou::isValidMove(Position prec, Position actu, bool cap, Plateau *board) {
	int diff1 = 0, diff2 = 0, compteur = 0;
	diff1 = actu.x - prec.x;
	diff2 = actu.y - prec.y;
	if (diff1 == diff2 || diff1 == -diff2) {
		if ((actu.x == prec.x + fabs(diff1)) && (actu.y == prec.y + fabs(diff1))) {
			for (int i = 1; i < fabs(diff1); i++) {
				if (board->getPiece(Position(prec.x + i, prec.y + i)) != 0) {
					compteur++;
				}
			}
			if (compteur == 0) {
				return 1;
			} else {
				return 0;
			}
		} else if ((actu.x == prec.x - fabs(diff1)) && (actu.y == prec.y + fabs(diff1))) {
			for (int i = 1; i < fabs(diff1); i++) {
				if (board->getPiece(Position(prec.x - i, prec.y + i)) != 0) {
					compteur++;
				}
			}
			if (compteur == 0) {
				return 1;
			} else {
				return 0;
			}
		} else if ((actu.x == prec.x + fabs(diff1)) && (actu.y == prec.y - fabs(diff1))) {
			for (int i = 1; i < fabs(diff1); i++) {
				if (board->getPiece(Position(prec.x + i, prec.y - i)) != 0) {
					compteur++;
				}
			}
			if (compteur == 0) {
				return 1;
			} else {
				return 0;
			}
		} else if ((actu.x == prec.x - fabs(diff1)) && (actu.y == prec.y - fabs(diff1))) {
			for (int i = 1; i < fabs(diff1); i++) {
				if (board->getPiece(Position(prec.x - i, prec.y - i)) != 0) {
					compteur++;
				}
			}
			if (compteur == 0) {
				return 1;
			} else {
				return 0;
			}
		} else {
			return 0;
		}
	} else
		return 0;
}

Tour::Tour(bool a) :
		Piece(a, "tour") {
	est_noir = a;
}

bool Tour::isValidMove(Position prec, Position actu, bool cap, Plateau *board) {
	int diff1 = 0, diff2 = 0, compteur=0;
	diff1 = actu.x - prec.x;
	diff2 = actu.y - prec.y;
	if (diff1 >= 1 && diff2 == 0){
		for(int i=1; i<diff1; i++){
			if(board->getPiece(Position(prec.x+i, prec.y))!=0){
				compteur++;
			}
		}
		if(compteur==0){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if (diff1 == 0 && diff2 >= 1){
		for(int i=1; i<diff2; i++){
			if(board->getPiece(Position(prec.x, prec.y+i))!=0){
				compteur++;
			}
		}
		if(compteur==0){
			return 1;
		}
		else{
			return 0;
		}

	}
	else if (diff1 <= -1 && diff2 == 0){
		for(int i=1; i<(-diff1); i++){
			if(board->getPiece(Position(prec.x-i, prec.y))!=0){
				compteur++;
			}
		}
		if(compteur==0){
			return 1;
		}
		else{
			return 0;
		}

	}
	else if (diff1 == 0 && diff2 <= -1){
		for(int i=1; i<(-diff2); i++){
			if(board->getPiece(Position(prec.x, prec.y-i))!=0){
				compteur++;
			}
		}
		if(compteur==0){
			return 1;
		}
		else{
			return 0;
		}
	} else {
		return 0;
	}
}

Dame::Dame(bool a) : Piece(a, "dame"), Tour(a), Fou(a){
	est_noir = a;
}

//Methode isValideMove de la class Dame sans heritage en diamant:

/*bool Dame::isValidMove(Position prec, Position actu, bool cap, Plateau *board) {
	int diff1 = 0, diff2 = 0;
	diff1 = actu.x - prec.x;
	diff2 = actu.y - prec.y;
	if ((((actu.x == prec.x + diff1) && (actu.y == prec.y + diff1))
			|| ((actu.x == prec.x - diff1) && (actu.y == prec.y + diff1))
			|| ((actu.x == prec.x + diff1) && (actu.y == prec.y - diff1))
			|| ((actu.x == prec.x - diff1) && (actu.y == prec.y - diff1))
			|| ((diff1 > 1 && diff2 == 0) || (diff1 == 0 && diff2 > 1))
			|| ((diff1 < 1 && diff2 == 0) || (diff1 == 0 && diff2 < 1)))
				) {
		return 1;
	} else {
		return 0;
	}
}*/

//Methode isValideMove de la class Dame avec heritage en diamant:

bool Dame::isValidMove(Position prec, Position actu, bool cap, Plateau *board) {
	return(Fou::isValidMove( prec,  actu,  cap,  board)||Tour::isValidMove( prec,  actu,  cap,  board));
}


Roi::Roi(bool a) :
		Piece(a, "roi") {
	est_noir = a;
}

bool Roi::isValidMove(Position prec, Position actu, bool cap, Plateau *board) {
	if ((((actu.x == prec.x + 1) && (actu.y == prec.y + 1))
			|| ((actu.x == prec.x - 1) && (actu.y == prec.y + 1))
			|| ((actu.x == prec.x + 1) && (actu.y == prec.y - 1))
			|| ((actu.x == prec.x - 1) && (actu.y == prec.y - 1))
			|| (actu.x == prec.x + 1 && actu.y == prec.y)
			|| (actu.x == prec.x && actu.y == prec.y + 1)
			|| (actu.x == prec.x - 1 && actu.y == prec.y)
			|| (actu.x == prec.x && actu.y == prec.y - 1))
					) {
		return 1;
	} else {
		return 0;
	}
}

Cavalier::Cavalier(bool a) :
		Piece(a, "cavalier") {
	est_noir = a;
}

bool Cavalier::isValidMove(Position prec, Position actu, bool cap,
		Plateau *board) {
	if ((((actu.x == prec.x + 1) && (actu.y == prec.y + 2))
			|| ((actu.x == prec.x - 1) && (actu.y == prec.y + 2))
			|| ((actu.x == prec.x + 1) && (actu.y == prec.y - 2))
			|| ((actu.x == prec.x - 1) && (actu.y == prec.y - 2))
			|| (actu.x == prec.x + 2 && actu.y == prec.y + 1)
			|| (actu.x == prec.x + 2 && actu.y == prec.y - 1)
			|| (actu.x == prec.x - 2 && actu.y == prec.y + 1)
			|| (actu.x == prec.x - 2 && actu.y == prec.y - 1))
			) {
		return 1;
	} else {
		return 0;
	}
}


/*
 *
 * Methodes du jeu de Dames
 *
 */

Jeton::Jeton(bool a) :
		Piece(a, "pion") {
	est_noir = a;
}

bool Jeton::isValidMove(Position prec, Position actu, bool cap,
		Plateau *board) {
	int diff=fabs(prec.x-actu.x);
	int diffx=prec.x-actu.x;
	int diffy=prec.y-actu.y;

	if ((diff==1)&&(board->getPiece(actu)==0)&&(((actu.x == prec.x - 1) && (actu.y == prec.y + 1))
			||((actu.x == prec.x + 1) && (actu.y == prec.y + 1)))&&(cap==0)
			){
		return 1;
	}
	else if((diff==1)&&(board->getPiece(actu)==0)&&(((actu.x == prec.x - 1) && (actu.y == prec.y - 1))
			||((actu.x == prec.x + 1) && (actu.y == prec.y - 1)))&&(cap==1)){
		return 1;
	} else if ((diffx == 2) && (diffy == 2) && (board->getPiece(actu) == 0)
			&& (board->getPiece(Position(prec.x - 1, prec.y - 1)) != 0)
			&& (board->getPiece(Position(prec.x - 1, prec.y - 1))->est_noir
					!= cap)) {
		board->remove(
				Position(prec.x - (prec.x - actu.x) / 2,
						prec.y - (prec.y - actu.y) / 2));
		return 1;
	}
	else if ((diffx == -2) && (diffy == 2) && (board->getPiece(actu) == 0)
			&&(board->getPiece(Position(prec.x+1,prec.y-1))!=0)
			&& (board->getPiece(Position(prec.x + 1, prec.y - 1))->est_noir
					!= cap)) {
		board->remove(
						Position(prec.x - (prec.x - actu.x) / 2,
								prec.y - (prec.y - actu.y) / 2));
		return 1;
	}
	else if ((diffx == 2) && (diffy == -2) && (board->getPiece(actu) == 0)
			&&(board->getPiece(Position(prec.x-1,prec.y+1))!=0)
			&& (board->getPiece(Position(prec.x - 1, prec.y + 1))->est_noir
					!= cap)) {
		board->remove(
						Position(prec.x - (prec.x - actu.x) / 2,
								prec.y - (prec.y - actu.y) / 2));
		return 1;
	}
	else if ((diffx == -2) && (diffy == -2) && (board->getPiece(actu) == 0)
			&&(board->getPiece(Position(prec.x+1,prec.y+1))!=0)
			&& (board->getPiece(Position(prec.x + 1, prec.y + 1))->est_noir
					!= cap)) {
		board->remove(
						Position(prec.x - (prec.x - actu.x) / 2,
								prec.y - (prec.y - actu.y) / 2));
		return 1;
	}
	else {
		return 0;
	}
}

SuperJeton::SuperJeton(bool a) :
		Piece(a, "dame"), Jeton(a) {
	est_noir = a;
}

bool SuperJeton::isValidMove(Position prec, Position actu, bool cap,
		Plateau *board) {
	int diff1 = 0, diff2 = 0, compteur = 0;
	diff1 = actu.x - prec.x;
	diff2 = actu.y - prec.y;
	if(Jeton::isValidMove(prec,  actu,  cap, board)==1){
		return 1;
	}
	else if ((diff1 == diff2 || diff1 == -diff2) && (board->getPiece(actu)==0)) {
		if ((actu.x == prec.x + fabs(diff1))
				&& (actu.y == prec.y + fabs(diff1))) {
			for (int i = 1; i < fabs(diff1)-1; i++) {
				if (board->getPiece(Position(prec.x + i, prec.y + i)) != 0) {
					compteur++;
				}
			}
			if (compteur == 0 && board->getPiece(Position(prec.x + fabs(diff1)-1, prec.y + fabs(diff1)-1)) == 0){
				return 1;
			}
			else if (compteur == 0 && board->getPiece(Position(prec.x + fabs(diff1)-1, prec.y + fabs(diff1)-1)) != 0
					&& (board->getPiece(Position(prec.x + fabs(diff1)-1, prec.y + fabs(diff1)-1))->est_noir != cap))
			{
				board->remove(Position(prec.x + fabs(diff1)-1, prec.y + fabs(diff1)-1));
				return 1;
			} else {
				return 0;
			}
		} else if ((actu.x == prec.x - fabs(diff1))
				&& (actu.y == prec.y + fabs(diff1))) {
			for (int i = 1; i < fabs(diff1)-1; i++) {
				if (board->getPiece(Position(prec.x - i, prec.y + i)) != 0) {
					compteur++;
				}
			}
			if (compteur == 0 && (board->getPiece(Position(prec.x - (fabs(diff1)-1), prec.y + fabs(diff1)-1)) == 0)){
				return 1;
			}
			else if (compteur==0 && (board->getPiece(Position(prec.x - (fabs(diff1)-1), prec.y + fabs(diff1)-1)) != 0)
					&& (board->getPiece(Position(prec.x - (fabs(diff1)-1), prec.y + fabs(diff1)-1))->est_noir != cap)){
				board->remove(Position(prec.x - (fabs(diff1)-1), prec.y + fabs(diff1)-1));
				return 1;
			} else {
				return 0;
			}
		} else if ((actu.x == prec.x + fabs(diff1))
				&& (actu.y == prec.y - fabs(diff1))) {
			for (int i = 1; i < fabs(diff1)-1; i++) {
				if (board->getPiece(Position(prec.x + i, prec.y - i)) != 0) {
					compteur++;
				}
			}
			if (compteur == 0 && ((board->getPiece(Position(prec.x + fabs(diff1)-1, prec.y - (fabs(diff1)-1))) == 0))){
				return 1;
			}
			else if(board->getPiece(Position(prec.x + fabs(diff1)-1, prec.y - (fabs(diff1)-1))) != 0
					&& (board->getPiece(Position(prec.x + fabs(diff1)-1, prec.y - (fabs(diff1)-1)))->est_noir != cap)) {
				board->remove(Position(prec.x + fabs(diff1)-1, prec.y - (fabs(diff1)-1)));
				return 1;
			} else {
				return 0;
			}
		} else if ((actu.x == prec.x - fabs(diff1))
				&& (actu.y == prec.y - fabs(diff1))) {
			for (int i = 1; i < fabs(diff1)-1; i++) {
				if (board->getPiece(Position(prec.x - i, prec.y - i)) != 0) {
					compteur++;
				}
			}
			if (compteur == 0 && (board->getPiece(Position(prec.x - (fabs(diff1)-1), prec.y - (fabs(diff1)-1))) == 0)){
				return 1;
			}
			else if ((board->getPiece(Position(prec.x - (fabs(diff1)-1), prec.y - (fabs(diff1)-1))) != 0)
					&& (board->getPiece(Position(prec.x - (fabs(diff1)-1), prec.y - (fabs(diff1)-1)))->est_noir != cap)) {
				board->remove(Position(prec.x - (fabs(diff1)-1), prec.y - (fabs(diff1)-1)));
				return 1;
			} else {
				return 0;
			}
		} else {
			return 0;
		}
	} else
		return 0;
}

