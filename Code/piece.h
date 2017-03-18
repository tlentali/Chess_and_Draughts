/*
 * piece.h
 *
 *
 *      Author: thomas
 */

#ifndef PIECE_H_
#define PIECE_H_

#include <iostream>
#include <string>
#include <sstream>
#include "position.h"
#include "plateau.h"

using namespace std;

class Plateau;
class Echiquier;

class Piece {

public:
	string nom;
	bool est_noir;
	Piece(bool, string);
	virtual bool isValidMove(Position, Position, bool, Plateau*) = 0;
	string toString();
};

class Tour: public virtual Piece {
public:
	Tour(bool);
	bool isValidMove(Position, Position, bool, Plateau*);
};

class Reine: public Piece {
public:
	Reine(bool);
	bool isValidMove(Position, Position, bool, Plateau*);
};

class Roi: public Piece {
public:
	Roi(bool);
	bool isValidMove(Position, Position, bool, Plateau*);
};

class Pion: public Piece {
public:
	Pion(bool);
	bool firstMove;
	bool isValidMove(Position, Position, bool, Plateau*);
};

class Cavalier: public Piece {
public:
	Cavalier(bool);
	bool isValidMove(Position, Position, bool, Plateau*);
};

class Fou: public virtual Piece {
public:
	Fou(bool);
	bool isValidMove(Position, Position, bool, Plateau*);
};

//class Dame sans héritage en diamant:

/*class Dame: public Piece {
public:
	Dame(bool);
	bool isValidMove(Position, Position, bool, Plateau*);
};*/



//class Dame avec héritage en diamant:

class Dame: public Tour, public Fou{
public:
	Dame(bool);
	bool isValidMove(Position, Position, bool, Plateau*);
};

/*
 *
 * Class du jeu de Dames
 *
 */

//class du pion

class Jeton: public virtual Piece {
public:
	Jeton(bool);
	bool isValidMove(Position, Position, bool, Plateau*);
};

//Class du pion-Dame

class SuperJeton: public Jeton {
public:
	SuperJeton(bool);
	bool isValidMove(Position, Position, bool, Plateau*);
};

#endif /* PIECE_H_ */
