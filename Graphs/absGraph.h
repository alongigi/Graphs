/*
 * absGraph.h
 *
 *  Created on: Jan 14, 2017
 *      Author: ise
 */

#ifndef ABSGRAPH_H_
#define ABSGRAPH_H_
#include "Vertice.h"
#include "Edge.h"

#include <list>
using namespace std;

class absGraph {
public:
	int memory;
	int size;
	int edgeSize;
	absGraph();
	virtual ~absGraph();
	virtual list<Vertice>* getVertList()=0;
	virtual Edge* getEdge(int i)=0;
	virtual list<Vertice> getVertice(int i)=0;
	virtual void printG()=0;
	virtual int getSize()=0;
	virtual int getEdgeSize()=0;
	virtual void setEdgeSize(double wei)=0;
	//Edge* autoGraph::getEdgeList();

};


#endif /* ABSGRAPH_H_ */
