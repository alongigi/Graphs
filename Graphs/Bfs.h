/*
 * Bfs.h
 *
 *  Created on: Jan 21, 2017
 *      Author: ise
 */

#ifndef BFS_H_
#define BFS_H_
#include "absGraph.h"
#include "Graph.h"
#include "cityGraph.h"
#include <queue>
#include <list>
#include <iterator>
#include <limits>
#include "helpFunc.h"

list<Vertice> Bfs(absGraph* G, Vertice V1,Vertice V2);



#endif /* BFS_H_ */
