/*
 * Dfs.h
 *
 *  Created on: Jan 15, 2017
 *      Author: ise
 */

#ifndef DFS_H_
#define DFS_H_
#include "absGraph.h"
#include "helpFunc.h"
#include "Graph.h"
#include "cityGraph.h"
#include <stack>
#include <list>
#include <iterator>
using namespace std;
void update(list<Vertice>** list);
list<Vertice> Dfs(absGraph* G,Vertice V);
void dfs(list<Vertice>** listG, Vertice V,list<Vertice>* L,int size);



#endif /* DFS_H_ */
