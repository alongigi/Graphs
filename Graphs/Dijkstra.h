/*
 * Dijkstra.h
 *
 *  Created on: Jan 19, 2017
 *      Author: alex
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_
#include "absGraph.h"
#include "Graph.h"
#include "cityGraph.h"
#include <queue>
#include <list>
#include <iterator>
#include <limits>
#include "helpFunc.h"
using namespace std;
struct CompareVertice:public std::binary_function<Vertice*,Vertice*,bool>
{
	bool operator()(Vertice* x, Vertice* y) const{
		return (x->d>y->d);
	}
};
list<Vertice> Dijkstra(absGraph* G, Vertice V1,Vertice V2);
#endif /* DIJKSTRA_H_ */
