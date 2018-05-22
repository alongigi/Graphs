/*
 * cityGraph.h
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */

#ifndef CITYGRAPH_H_
#define CITYGRAPH_H_
#include "roadE.h"
#include "absGraph.h"
#include <list>

using namespace std;

class cityGraph: public absGraph{
public:
	list<Vertice>*  cityList;
	roadE* edgeArr;
	int memory;
	int size;
	int sizeEdge;
	cityGraph();
	cityGraph(Vertice* vertexlist, roadE* edgelist , int numofV, int numofE);
	cityGraph(const cityGraph &G);
	 ~cityGraph();
	list<Vertice>* getVertList();
	roadE* getEdge(int i);
	void printG();
	int getSize();
	int getEdgeSize();
	void setEdgeSize(double wei);
	list<Vertice> getVertice(int i);

};


#endif /* CITYGRAPH_H_ */
