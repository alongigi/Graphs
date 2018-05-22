/*
 * autoGraph.cpp
 *
 *  Created on: Jan 21, 2017
 *      Author: ise
 */


#include "autoGraph.h"
using namespace std;

autoGraph::autoGraph():memory(0),size(0),edgeSize(0){
	vertList=NULL;
	edgeArr=NULL;

}
autoGraph::autoGraph(Vertice* vertexlist, Edge* edgelist , int numofV, int numofE){
	//memory=0;
	size=numofV;
	edgeSize=numofE;
	vertList=new list<Vertice>[numofV];
	edgeArr=new Edge [numofE];
	for(int i=0;i<numofE;i++){
		edgeArr[i]=edgelist[i];
	}
	for(int i=0;i<numofV;i++){
		vertList[i].push_back(vertexlist[i]);
	}
	for(int i=0;i<numofV;i++){
		for(int j=0;j<numofE;j++){
			if(vertList[i].front()==edgeArr[j].start)
				vertList[i].push_back(edgeArr[j].end);
		}
	}
	for(int i=0;i<numofV;i++){
		memory=memory+4+vertList[i].front().symbol.length();
	}
	for(int i=0;i<numofE;i++){
			memory=memory+2;
		}

}
autoGraph::autoGraph(const autoGraph& G){

	memory=G.memory;
	size=G.size;
	edgeSize=G.edgeSize;
	vertList=new list<Vertice>[size];
		edgeArr=new Edge [edgeSize];
	for(int i=0;i<edgeSize;i++){
		edgeArr[i]=G.edgeArr[i];
	}
	for(int i=0;i<size;i++){
		list<Vertice>::iterator it;
		for(it=G.vertList[i].begin();it!=G.vertList[i].end();++it){
			vertList[i].push_back(*it);
		}
	}
}
autoGraph::~autoGraph(){
	delete[] vertList;
	delete[] edgeArr;
}
void autoGraph::printG(){
	for(int i=0;i<size;i++){
		cout<<vertList[i].front();
		if(i<size-1)
			cout<<",";
	}
}
list<Vertice>* autoGraph::getVertList(){
	return vertList;
}
Edge* autoGraph::getEdgeList(){
	return edgeArr;
}
Edge autoGraph::getEdge(int i){
	return edgeArr[i];
}
list<Vertice> autoGraph::getList(int i){
	return vertList[i];
}
