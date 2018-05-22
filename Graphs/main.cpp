/*
 * main.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */
#include "Graph.h"
#include "cityGraph.h"
#include <list>
#include <iostream>
#include <string>
#include "string.h"

#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Dfs.h"
#include "Dijkstra.h"
#include "Bfs.h"
#include "helpFunc.h"

//#include "readFile.cpp"
using namespace std;
int checkFunction(int args,char** argv){
	if(args<4||args>8)
		return 0;
	if(strcmp(argv[2],"-r")!=0&&strcmp(argv[2],"-c")!=0&&strcmp(argv[2],"-a")!=0)
		return 0;
	std::ifstream file(argv[1]);
	if(!file.is_open()){
		return 2;
	}
	if(strcmp(argv[2],"-a")==0){
		if(args==6&&strcmp(argv[3],"-m")!=0)
			return 0;
		std::ifstream file2(argv[2]);
		if(!file.is_open()){
			return 3;
		}
	}
	if(strcmp(argv[2],"-r")==0||strcmp(argv[2],"-c")==0)
		if(strcmp(argv[3],"-bfs")!=0&&strcmp(argv[3],"-dfs")!=0&&strcmp(argv[3],"-dijkstra")!=0)
			return 0;
	if(strcmp(argv[3],"-dfs")==0){
		if(args==7&&strcmp(argv[5],"-m")!=0){
			return 0;
		}
	}
	else if(strcmp(argv[3],"-bfs")==0||strcmp(argv[3],"-dijkstra")==0){
		if(args!=6&&args!=8)
			return 0;
		else if(args==8&&strcmp(argv[6],"-m")!=0)
			return 0;
	}
	return 1;
}
int main(int args,char* argv[]) {
	if(checkFunction(args,argv)==0){
		cout<<"Invalid Parameter Syntax"<<endl;
		return 0;
	}
	if(checkFunction(args,argv)==2){
		string filname(argv[1]);
		cout<<"File "+filname+" Does Not Exist"<<endl;
		return 0;
	}
	if(checkFunction(args,argv)==3){
		string filname(argv[2]);
		cout<<"File "+filname+" Does Not Exist"<<endl;
		return 0;
	}
	try{

	char* path=argv[1];
	char* type=argv[2];
	list<Vertice> answer;
	if(argv[2][1]!='a'){
		char* search=argv[3];
		if(strcmp(argv[3],"-dfs")==0){//DFS
			std::string vert(argv[4]);
			Vertice V1(vert);
			if(argv[2][1]=='r'){
				Graph* dfs=new Graph(readFile(path));
				if(args==8&&atoi(argv[7])<dfs->memory){
					delete dfs;
					throw OutOfMemory();
				}
				answer=Dfs(dfs,V1);
				delete dfs;

			}
			else if(argv[2][1]=='c'){
				cityGraph* dfs=new cityGraph(readFile2(path));
				if(args==8&&atoi(argv[7])<dfs->memory){
					delete dfs;
					throw OutOfMemory();
				}
				answer=Dfs(dfs,V1);
				//print(dfs,answer);
				delete dfs;

			}
		}
		else if(strcmp(argv[3],"-dijkstra")==0){//Dijkstra
			std::string vert1(argv[4]);
			Vertice V1(vert1);
			std::string vert2(argv[5]);
			Vertice V2(vert2);
			if(argv[2][1]=='r'){
					Graph* dijkstra=new Graph(readFile(path));
					if(args==8&&atoi(argv[7])<dijkstra->memory){
						delete dijkstra;
						throw OutOfMemory();
					}
					answer=Dijkstra(dijkstra,V1,V2);
					delete dijkstra;

			}
			else if(argv[2][1]=='c'){
					cityGraph* dijkstra=new cityGraph(readFile2(path));
					if(args==8&&atoi(argv[7])<dijkstra->memory){
						delete dijkstra;
						throw OutOfMemory();
					}
					answer=Dijkstra(dijkstra,V1,V2);
					printCity(dijkstra,&answer);
					delete dijkstra;
				}
			}
			else if(strcmp(argv[3],"-bfs")==0){
				std::string vert1(argv[4]);
				Vertice V1(vert1);
				std::string vert2(argv[5]);
				Vertice V2(vert2);
				if(argv[2][1]=='r'){
						Graph* bfs=new Graph(readFile(path));
						if(args==8&&atoi(argv[7])<bfs->memory){
							delete bfs;
							throw OutOfMemory();
						}
						answer=Bfs(bfs,V1,V2);
						delete bfs;

				}
				else if(argv[2][1]=='c'){
						cityGraph* bfs=new cityGraph(readFile2(path));
						if(args==8&&atoi(argv[7])<bfs->memory){
							delete bfs;
							throw OutOfMemory();
						}
						//bfs->printG();
						answer=Bfs(bfs,V1,V2);
						list<Vertice>::iterator it;
						/*for(it=answer.begin();it!=answer.end();++it){
							cout<<*it;
						}*/

						printCity(bfs,&answer);
						delete bfs;
				}
			}
		if(strcmp(argv[2],"-c")!=0||(strcmp(argv[2],"-c")==0&&strcmp(argv[3],"-dfs")==0)){
			list<Vertice>::iterator it;
			for(it=answer.begin();it!=answer.end();it++){

				cout<<*it;
				if(it!=--answer.end())
					cout<<",";
				if(it==--answer.end())
					cout<<endl;

			}
		}
	}


	else if(argv[2][1]=='a'){
			autoGraph G(readFile3(path));
			//G.printG();
			autoAlg(G,argv[3]);
		//autoAlg(G,argv[3]);
	}
	return 1;

	}
	catch(exception& e){
		cout<<e.what()<<endl;
	}
}
