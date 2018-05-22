/*
 * Dfs.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: ise
 */

#include "Dfs.h"
using namespace std;
list<Vertice> Dfs(absGraph* G, Vertice V){
	list<Vertice>* listG=G->getVertList();
	for(int i=0;i<G->getSize();i++){
		listG[i].front().state="w";
		update(&listG,G->getSize(),listG[i].front());
	}
	list<Vertice> L;
	dfs(&listG,V,&L,G->getSize());
	return L;
}
void dfs(list<Vertice>** listG, Vertice V,list<Vertice>* L,int size){
	//list<Vertice>* listG=G->getVertList();
	V.state="w";
	int i;
	for(i=0;i<size;i++){
		if((*listG)[i].front()==V)
			break;
	}
	list<Vertice>::iterator it=(*listG)[i].begin();
	for(it++;it!=(*listG)[i].end();++it){
		if(it->state=="w"){
			it->dad=V.symbol;
			update(listG,size,*it);
			dfs(listG,*it,L,size);
		}
	}
	V.state="b";
	update(listG,size,V);
	L->push_front(V);


	/*
	if(!check(G,V))
			throw InvalidInput();
	list<Vertice>* listG=G->getVertList();
	stack<Vertice> S;
	S.push(V);
	list<Vertice> L;
	Vertice u;

	while(!S.empty()&&u!=S.top()){

		//Vertice u;
		u=S.top();
		S.pop();
		if(u.visited==false){
			int k=0;
			for(k=0; k<G->getSize() ;k++){
					list<Vertice>::iterator it1;
					for(it1=listG[k].begin();it1!=listG[k].end();++it1){
						if(u==*it1){
							it1->visited=true;
						}
					}
				}
			u.visited=true;
			list<Vertice>::iterator it2;
			bool check=true;
			for(it2=L.begin();it2!=L.end();++it2)
				if(u==*it2)
					check=false;
			if(check)
				L.push_back(u);
			//cout<<u;
			int i=0;
			for(i=0;i<G->getSize();i++){
				if(listG[i].front()==u)
					break;
			}

			list<Vertice>::iterator it=listG[i].begin();
			for(it++; it != listG[i].end(); ++it){
				if(it->visited==false)
					S.push(*it);
			}
		}
	}*/
	//return L;
}

