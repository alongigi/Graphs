/*
 * helpFunc.h
 *
 *  Created on: Jan 21, 2017
 *      Author: ise
 */

#ifndef HELPFUNC_H_
#define HELPFUNC_H_
#include "Graph.h"
#include "autoGraph.h"
#include "Exceptions.h"
#include "cityGraph.h"
#include <list>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
roadE createRoad(string name);

Edge createEdge(string name);
cityGraph readFile2(char* dest);
Graph readFile(char* dest);
autoGraph readFile3(char* dest);
void update(list<Vertice>** listV, int size, Vertice& u);
list<Vertice> path(list<Vertice>* listG ,Vertice v1,Vertice v2,int size);
Edge createAutoEdge(string name);
void autoAlg(autoGraph G, char* path);
void printCity(cityGraph* G,list<Vertice>* listV);
bool check(absGraph* G, Vertice v1, Vertice v2);
bool check(absGraph* G, Vertice v1);
#endif /* HELPFUNC_H_ */
