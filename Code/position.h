/*
 * position.h
 *
 *  Created on: 9 avr. 2015
 *      Author: thomas
 */

#ifndef POSITION_H_
#define POSITION_H_

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Position
{
	public:
		Position(int, int);
		Position(Position, int, int);
		Position(string);
		string toString();
		void afficher();
		int get_x();
		int get_y();
	    int x;
		int y;
};




#endif /* POSITION_H_ */
