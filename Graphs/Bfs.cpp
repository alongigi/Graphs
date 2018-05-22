/*
 * Bfs.cpp
 *
 *  Created on: Jan 21, 2017
 *      Author: ise
 */

#include "Bfs.h"

using namespace std ;
list<Vertice> Bfs(absGraph* G, Vertice V1,Vertice V2){
	bool trecheck=check(G,V1,V2);
	if(!trecheck){
		delete G;
		throw InvalidInput();
	}
	queue<Vertice*> Q;
		list<Vertice>* listG=G->getVertList();

		for(int i=0;i<G->getSize();i++){
			listG[i].front().d=std::numeric_limits<double>::max();
			update(&listG,G->getSize(),listG[i].front());
		}
		Q.push(&V1);
		int counter=0;
		while(!Q.empty()){
			counter++;
			if(counter>G->getSize()+1)
				break;
			Vertice* u=Q.front();
			Q.pop();
			int i=0;
			for(i=0;i<G->getSize();i++)
				if(listG[i].front()==*u)
					break;
			list<Vertice>::iterator it=listG[i].begin();
				for(it++;it!=listG[i].end();++it){
					if(it->d==std::numeric_limits<double>::max()){
						it->d=u->d+1;
						it->dad=u->symbol;
						update(&listG,G->getSize(),*it);
						int k;
						for(k=0;k<G->getSize();k++){
							if(*it==listG[k].front())
								break;
						}
						//Vertice* adj=new Vertice(*it);
						Q.push(&(listG[k].front()));
						//delete adj;
					}
				}
		}

		list<Vertice> returnList=path(listG,V1,V2,G->getSize());

		return returnList;
}


