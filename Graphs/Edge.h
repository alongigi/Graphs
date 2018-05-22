/*
 * Edge.h
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */

#ifndef EDGE_H_
#define EDGE_H_
#include <string>
#include <iostream>
#include "Vertice.h"
using namespace std;
class Edge{
public:

 Vertice start;
 Vertice end;
 char state;
 friend class Graph;

 double weight;
	Edge(): weight(0) {state='~';};
	Edge(Vertice symbol1, Vertice symbol2, double wei );
	Edge(Vertice symbol1, Vertice symbol2,char st );
	Edge(const Edge& other);
	virtual Edge& operator=(const Edge& edge);
	virtual void print();
	virtual ~Edge(){};
};

#endif /* EDGE_H_ */
