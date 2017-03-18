/*
 * plateau.h
 *
 *  Created on: 9 avr. 2015
 *      Author: thomas
 */

#ifndef PLATEAU_H_
#define PLATEAU_H_

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "piece.h"

using namespace std;

class Piece;

class Plateau {
protected:
	vector<vector<Piece*> > plateau;
	void deplace(Position, Position);
	void ajoute(Piece*, Position);

public:

	Plateau(int, int);
	int getHeight();
	int getWidth();
	virtual void conditionsInitiales()=0;
	bool estDedans(Position);
	Piece* getPiece(Position);
	void joue(Position, Position, bool);
	virtual void remove(Position)=0;
	virtual bool rejoue(Position, Position, bool)=0;
	virtual void Promo(int, string, bool)=0;
};

class Echiquier: public Plateau {
public:
	Echiquier();
	void conditionsInitiales();
	void toString();
	void PetitRoque(bool);
	void GrandRoque(bool);
	void remove(Position);
	bool rejoue(Position, Position, bool); //crée mais non utilisé
	void Promo(int, string, bool);

};

class Damier: public Plateau {
public:
	Damier();
	void conditionsInitiales();
	void toString();
	void remove(Position);
	bool rejoue(Position, Position, bool);
	void Promo(int, string, bool);

};

#endif /* PLATEAU_H_ */
