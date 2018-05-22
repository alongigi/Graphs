/*
 * Edge.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */


#include "Edge.h"
using namespace std;


Edge::Edge(Vertice symbol1, Vertice symbol2, double wei)  {
	start=symbol1;
	end=symbol2;
	weight=wei;
	state='~';
}
Edge::Edge(Vertice symbol1, Vertice symbol2 ,char st )  {
	start=symbol1;
	end=symbol2;
	weight=0;
	state=st;
}
Edge::Edge(const Edge& other){
	start=other.start;
	end=other.end;
	weight=other.weight;
	state=other.state;
}
Edge& Edge::operator=(const Edge& other){
	start=other.start;
	end=other.end;
	weight=other.weight;
	state=other.state;
	return *this;
}

void Edge::print(){
	cout<<start.symbol<<weight<<end.symbol<<endl;
}



