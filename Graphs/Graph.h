/*
 * Graph.h
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include "Edge.h"
//#include "Vertice.h"
#include <list>
#include "absGraph.h"
using namespace std;
class Graph: public absGraph{
public:

	list<Vertice>*  verticeList;
	Edge* edgeArr;
	int memory;
	int size;
	int edgeSize;
	Graph();
	Graph(Vertice* vertexlist, Edge* edgelist , int numofV, int numofE);
	Graph(const Graph &G);
	list<Vertice>* getVertList();
	Edge* getEdge(int i);
	virtual ~Graph();
	void printG();
	int getSize();
	int getEdgeSize();
	void setEdgeSize(double wei);
	list<Vertice> getVertice(int i);
};

#endif /* GRAPH_H_ */
