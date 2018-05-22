/*
 * roadE.h
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */

#ifndef ROADE_H_
#define ROADE_H_
#include "Edge.h"
using namespace std;

class roadE: public Edge {
public:
	//Vertice CityName1;
	//Vertice CityName2;
	double RoadLength;
	int RoadType;
	//double AverageIncline;
	roadE();
	roadE(Vertice city1, Vertice city2, double roadl, int roadT, double roadI);
	roadE& operator=(const roadE& other);
	void print() ;
	 ~roadE();

	 friend class cityGraph;
};


#endif /* ROADE_H_ */
