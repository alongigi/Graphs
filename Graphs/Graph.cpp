/*
 * Graph.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */

#include "Graph.h"
#include <list>

using namespace std;
Graph::Graph():memory(0),size(0),edgeSize(0){
	verticeList=NULL;
	edgeArr=NULL;

}
Graph::Graph(Vertice* vertexlist, Edge* edgelist , int numofV, int numofE){
	memory=0;
	size=numofV;
	edgeSize=numofE;
	verticeList=new list<Vertice>[numofV];
	edgeArr=new Edge [numofE];
	for(int i=0;i<numofE;i++){
		edgeArr[i]=edgelist[i];
	}
	for(int i=0;i<numofV;i++){
		verticeList[i].push_back(vertexlist[i]);
	}
	for(int i=0;i<numofV;i++){
		for(int j=0;j<numofE;j++){
			if(verticeList[i].front()==edgeArr[j].start)
				verticeList[i].push_back(edgeArr[j].end);
		}
	}
	for(int i=0;i<numofV;i++){
		memory=memory+4+verticeList[i].front().symbol.length();
	}
	for(int i=0;i<numofE;i++){
			memory=memory+2;
		}
}
Graph::Graph(const Graph& G){

	memory=G.memory;
	size=G.size;
	edgeSize=G.edgeSize;
	verticeList=new list<Vertice>[size];
		edgeArr=new Edge [edgeSize];
	for(int i=0;i<edgeSize;i++){
		edgeArr[i]=G.edgeArr[i];
	}
	for(int i=0;i<size;i++){
		list<Vertice>::iterator it;
		for(it=G.verticeList[i].begin();it!=G.verticeList[i].end();++it){
			verticeList[i].push_back(*it);
		}
	}
}
Graph::~Graph(){
	delete[] verticeList;
	delete[] edgeArr;
}
void Graph::printG(){
	for(int i=0;i<size;i++){
		cout<<verticeList[i].front();
		if(i<size-1)
			cout<<",";
	}
}
list<Vertice>* Graph::getVertList(){
	return this->verticeList;
}
Edge* Graph::getEdge(int i){

	return &edgeArr[i];
}
int Graph::getSize(){
	return size;
}
int Graph::getEdgeSize(){
	return edgeSize;
}
void Graph::setEdgeSize(double wei){
	for(int i=0;i<edgeSize;i++)
		edgeArr[i].weight=wei;
}
list<Vertice> Graph::getVertice(int i){
	return verticeList[i];
}

