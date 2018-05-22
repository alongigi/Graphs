/*
 * Dijkstra.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: alex
 */

#include "Dijkstra.h"

using namespace std ;

list<Vertice> Dijkstra(absGraph* G, Vertice V1,Vertice V2) {
	bool trecheck=check(G,V1,V2);
		if(!trecheck){
			delete G;
			throw InvalidInput();
		}
	priority_queue<Vertice*, vector<Vertice*>,CompareVertice > Q;
	list<Vertice>* listG=G->getVertList();
	Edge* edgeList=new Edge[G->getEdgeSize()];
	for(int i=0;i<G->getEdgeSize();i++){
		edgeList[i]=*(G->getEdge(i));
	}

	Vertice notu;
	for(int i=0;i<G->getSize();i++){
		listG[i].front().d=std::numeric_limits<double>::max();
		update(&listG,G->getSize(),listG[i].front());
	}
	update(&listG,G->getSize(),V1);
	Vertice check= listG[0].front();
	for(int i=0;i<G->getSize();i++)
		Q.push(&listG[i].front());
	while(!Q.empty())
	{
		Vertice* u=Q.top();
		Q.pop();
		int i=0;
		for(i=0;i<G->getSize();i++)
			if(listG[i].front()==*u)
				break;
		double wei;
		list<Vertice>::iterator it=listG[i].begin();
		for(it++;it!=listG[i].end();++it){
			for(int j=0;j<G->getEdgeSize();j++){
				if(edgeList[j].start==*u&&edgeList[j].end==*it)
					wei=edgeList[j].weight;
			}
			if(it->d>u->d+wei){
				it->d=u->d+wei;
				it->dad=u->symbol;
				update(&listG,G->getSize(),*it);
			}
		}
	}
	delete[] edgeList;
	return path(listG,V1,V2,G->getSize());

}


