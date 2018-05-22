/*
 * roadE.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */

#include "roadE.h"

using namespace std;

roadE::roadE(): RoadLength(0),RoadType(0){}
roadE::roadE(Vertice city1, Vertice city2, double roadl, int roadT, double roadI){
	start=city1;
	end=city2;
	RoadLength=roadl;
	RoadType=roadT;
	double temp=(double)1/RoadType;
	weight=temp*RoadLength;
	weight=weight+roadI*RoadLength;
	weight=weight+RoadLength;
	//weight=RoadLength+(1/RoadType)*RoadLength+roadI*RoadLength;
}
roadE& roadE::operator=(const roadE& other){
	start=other.start;
	end=other.end;
	weight=other.weight;
	RoadLength=other.RoadLength;
	RoadType=other.RoadType;
	return *this;
}
void roadE::print(){
	cout<<start<<","<<RoadLength<<"-"<<RoadType<<end;
}

roadE::~roadE() {}

