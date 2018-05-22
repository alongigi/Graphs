/*
 * Vertice.h
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */

#ifndef VERTICE_H_
#define VERTICE_H_

#include <string>
#include <iostream>
using namespace std;
class Vertice{
public:

	string symbol;
	string dad;
	string state;
	bool visited;
	double d;
	friend class Graph;
	Vertice();
	Vertice(string symbol);
	Vertice(string symbol,string state);

	Vertice(const Vertice& other);
	Vertice& operator=(const Vertice& ver);
	bool operator==(const Vertice& other);
	bool operator!=(const Vertice& other);
	bool operator<(const Vertice &other)const;
	void printV();
	string getState();
	 ~Vertice();
	 friend ostream& operator<<(ostream& out, const Vertice &s);
	 ostream& Show(ostream& out)const;
};
#endif /* VERTICE_H_ */
