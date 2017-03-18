/*
 * position.cpp
 *
 *  Created on: 9 avr. 2015
 *      Author: thomas
 */

#include "position.h"

using namespace std;


Position::Position(int a, int b)
{
	x = a;
	y = b;
}

Position::Position(Position prec, int a, int b)
{
	x = prec.x + a;
	y = prec.y + b;
}

Position::Position(string s) {
	if (s.size() == 2) {
		x = s[0] - 'A';
		y = s[1] - '0' - 1;
	} else if (s.size() == 3) {
		x = s[0] - 'A';
		y =  10*(s[1]- '0')+(s[2] - '0')- 1;
	}
}

string Position::toString()
{
	string coordx, coordy;
	string coordf;
	coordx = 'A' + x ;
	coordy = y + '0' + 1;
	coordf = coordx + coordy;
	cout<<coordf<<endl;
	return coordf;
}

void Position::afficher()
{
	cout<<x<<" , "<<y<<endl;
}

int Position::get_x()
{
	return x;
}

int Position::get_y()
{
	return y;
}

