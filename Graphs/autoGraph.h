/*
 * autoGraph.h
 *
 *  Created on: Jan 21, 2017
 *      Author: ise
 */

#ifndef AUTOGRAPH_H_
#define AUTOGRAPH_H_
#include <list>
#include <vector>
#include "absGraph.h"
#include "Edge.h"

using namespace std;
class autoGraph{
public:
	list<Vertice>* vertList;
	Edge* edgeArr;
	int memory;
	int size;
	int edgeSize;
	autoGraph();
	autoGraph(Vertice* vertexlist, Edge* edgelist , int numofV, int numofE);
	autoGraph(const autoGraph &G);
	virtual ~autoGraph();
	void printG();
	list<Vertice>* getVertList();
	list<Vertice> getList(int i);
	Edge* getEdgeList();
	Edge getEdge(int i);
};

#endif /* AUTOGRAPH_H_ */
