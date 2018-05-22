/*
 * cityGraph.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */

#include "cityGraph.h"

using namespace std;

cityGraph::cityGraph():memory(0),size(0),sizeEdge(0){
	cityList=NULL;
	edgeArr=NULL;

}
cityGraph::cityGraph(Vertice* vertexlist, roadE* edgelist , int numofV, int numofE){
	memory=0;
	sizeEdge=numofE;
	size=numofV;
	cityList=new list<Vertice>[numofV];
	edgeArr=new roadE [numofE];

	for(int i=0;i<numofE;i++){
		edgeArr[i]=edgelist[i];
	}
	for(int i=0;i<numofV;i++){
		cityList[i].push_back(vertexlist[i]);
	}
	for(int i=0;i<numofV;i++){
		for(int j=0;j<numofE;j++){
			if(cityList[i].front()==edgeArr[j].start)
				cityList[i].push_back(edgeArr[j].end);
		}
	}
	for(int i=0;i<numofV;i++){
		memory=memory+4+cityList[i].front().symbol.length();
	}
	for(int i=0;i<numofE;i++){
			memory=memory+6;
		}
}
cityGraph::cityGraph(const cityGraph& G){

	memory=G.memory;
	size=G.size;
	sizeEdge=G.sizeEdge;
	cityList=new list<Vertice>[size];
	edgeArr=new roadE [sizeEdge];
	for(int i=0;i<sizeEdge;i++){
		edgeArr[i]=G.edgeArr[i];
	}
	for(int i=0;i<size;i++){
		list<Vertice>::iterator it;
		for(it=G.cityList[i].begin();it!=G.cityList[i].end();++it){
			cityList[i].push_back(*it);
		}
	}
}

cityGraph::~cityGraph() {
	delete[] cityList;
	delete[] edgeArr;
}
list<Vertice>* cityGraph::getVertList(){
	return cityList;
}
roadE* cityGraph::getEdge(int i){
	return &edgeArr[i];
}
void cityGraph::printG(){
	for(int i=0;i<size;i++){
		cout<<cityList[i].front();
		if(i<size-1)
			cout<<",";
	}
}
int cityGraph::getSize(){
	return size;
}
int cityGraph::getEdgeSize(){
	return sizeEdge;
}
void cityGraph::setEdgeSize(double wei){
	for(int i=0;i<edgeSize;i++)
			edgeArr[i].weight=wei;
}
list<Vertice> cityGraph::getVertice(int i){
	return cityList[i];
}

