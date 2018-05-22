/*
 * helpFunc.cpp

 *
 *  Created on: Jan 21, 2017
 *      Author: ise
 */
#include "helpFunc.h"

Edge createAutoEdge(string name){
	string symbol1="";
	string symbol2="";
	//double weight;
	string temp="";
	int i=0;
	//roadE returnEdge;
	while(name[i]!=','&&i<name.length()){
		symbol1=symbol1+name[i];
		i++;
	}
	if(i==name.length())
			throw InvalidInput();
	i++;
	while(name[i]!=','&&i<name.length()){
		symbol2=symbol2+name[i];
		i++;
	}
	if(i==name.length())
				throw InvalidInput();
	i++;

	Vertice v1(symbol1);
	Vertice v2(symbol2);
	if(i==name.length())
			throw InvalidInput();
	char state=name[i];

	Edge returnEdge(symbol1,symbol2,state);
		return returnEdge;
}
roadE createRoad(string name){
	string symbol1="";
	string symbol2="";
	//double weight;
	string temp="";
	int i=0;
	//roadE returnEdge;
	while(name[i]!=','&&i<name.length()){
		symbol1=symbol1+name[i];
		i++;
	}
	if(i==name.length())
			throw InvalidInput();
	i++;
	while(name[i]!=','&&i<name.length()){
		symbol2=symbol2+name[i];
		i++;
	}
	if(i==name.length())
		throw InvalidInput();
	i++;
	if(i==name.length())
		throw InvalidInput();
	Vertice v1(symbol1);
	Vertice v2(symbol2);
	while(name[i]!=','&&i<name.length()){
		temp=temp+name[i];
		i++;
	}
	if(i==name.length())
		throw InvalidInput();
	double roadL=atoi(temp.c_str());
	i++;
	temp="";
	while(name[i]!=','&&i<name.length()){
		temp=temp+name[i];
		i++;
	}
	if(i==name.length())
		throw InvalidInput();
	int roadT=atoi(temp.c_str());
	i++;
	if(i==name.length())
			throw InvalidInput();
	double roadI=atof(name.substr(i).c_str());
	roadE returnEdge(symbol1,symbol2,roadL,roadT,roadI);
	return returnEdge;
}
Edge createEdge(string name){
		string symbol1="";
		string symbol2="";
		double weight;
		int i=0;
		//Edge *returnEdge;
		while(name[i]!=','&&i<name.length()){
			symbol1=symbol1+name[i];
			i++;
		}
		if(i==name.length())
			throw InvalidInput();
		i++;
		while(name[i]!=','&&i<name.length()){
			symbol2=symbol2+name[i];
			i++;
		}
		if(i==name.length())
			throw InvalidInput();
		i++;
		if(i==name.length())
					throw InvalidInput();
		weight=atoi(name.substr(i).c_str());
		Vertice v1(symbol1);
		Vertice v2(symbol2);
		Edge returnEdge(symbol1,symbol2,weight);
		return returnEdge;
	}
cityGraph readFile2(char* dest){
	std::ifstream file(dest);
	string line;
	int numofV=0;
	int numofE=0;
	getline(file,line);
	if(line[0]=='C')
		numofV++;
	else
		throw InvalidInput();
	while(line[0]=='C'&&file && std::getline(file,line)){
		string check=line.substr(0,2);
		if(check.compare("C:")==0){
			numofV++;
		}
	}
	if(line[0]=='R')
		numofE++;
	else
		throw InvalidInput();
	while(line[0]=='R'&&file && std::getline(file,line)){
		string check=line.substr(0,2);
		if(check.compare("R:")==0)
			numofE++;
	}
	if(line!=""&&line[0]!='R')
		throw InvalidInput();
	file.close();
	Vertice* vlist=new Vertice[numofV];
	roadE* elist=new roadE[numofE];
	int i=0;
	int j=0;
	file.open(dest);
	while(file && std::getline(file,line)){
		if(i<numofV&&line.substr(0,2).compare("C:")==0){

			if(line.substr(1).length()-1<1)
				throw InvalidInput();
			if(line[line.length()-1]=='\r'){
				Vertice newV(line.substr(2,line.substr(2).length()-1));
				vlist[i]=newV;
			}
			else{
				Vertice newV(line.substr(2,line.substr(2).length()));
				vlist[i]=newV;
				}
		//	Vertice newV(line.substr(2,line.substr(2).length()-1));
			//vlist[i]=newV;
			i++;
		}
		if(j<numofE&&line.substr(0,2).compare("R:")==0){
			roadE newE;
			if(line[line.length()-1]=='\r')
				newE=createRoad(line.substr(2,line.substr(2).length()-1));
			else
				newE=createRoad(line.substr(2,line.substr(2).length()));
			elist[j]=newE;
			j++;
		}

	}
	file.close();

	bool counter0 = false;
		bool counter1 = false;
		for(int j=0;j<numofE;j++){
			Vertice start=elist[j].start;
			Vertice end=elist[j].end;
			for(int i=0; i<numofV; i++){
				if(start==vlist[i]){
					counter0=true;
					//temp1
				}
				if(end==vlist[i])
					counter1=true;
			}
			if (!counter0&&!counter1)
				throw undefinedVertice0(start.symbol +" and "+ end.symbol);
			if(!counter0)
				throw undefinedVertice0(start.symbol);
			if(!counter1)
				throw undefinedVertice0(end.symbol);
			counter0=false;
			counter1=false;
		}
	cityGraph returnGraph(vlist,elist,numofV,numofE);
	delete[] vlist;
	delete[] elist;
	return returnGraph ;

}
Graph readFile(char* dest){
		std::ifstream file(dest);
		/*if(file==NULL)
			throw*///to do
		string line;
		int numofV=0;
		int numofE=0;
		//bool letstry=true;
		getline(file,line);
		if(line[0]=='V')
			numofV++;
		else
			throw InvalidInput();
		while(line[0]=='V'&&file && std::getline(file,line)){
			string check=line.substr(0,2);
			if(check.compare("V:")==0){
				numofV++;
			}
		}
		if(line[0]=='E')
			numofE++;
		else
			throw InvalidInput();
		while(line[0]=='E'&&file && std::getline(file,line)){
			string check=line.substr(0,2);
			if(check.compare("E:")==0)
				numofE++;
		}
		if(line!="")
			throw InvalidInput();
		file.close();

		Vertice* vlist=new Vertice[numofV];
		Edge* elist=new Edge[numofE];
		int i=0;
		int j=0;
		file.open(dest);

		while(file && std::getline(file,line)){
					if(i<numofV&&line.substr(0,2).compare("V:")==0){
						if(line.substr(1).length()-1<1)
							throw InvalidInput();
						if(line[line.length()-1]=='\r'){
							Vertice newV(line.substr(2,line.substr(2).length()-1));
							vlist[i]=newV;
						}
						else{
							Vertice newV(line.substr(2,line.substr(2).length()));
							vlist[i]=newV;
							}
						i++;
					}
					if(j<numofE&&line.substr(0,2).compare("E:")==0){
						Edge newE;
						if(line[line.length()-1]=='\r')
							newE=createEdge(line.substr(2,line.substr(2).length()-1));
						else
							newE=createEdge(line.substr(2,line.substr(2).length()));
						elist[j]=newE;
						j++;
					}

				}
		bool counter0 = false;
		bool counter1 = false;
		for(int j=0;j<numofE;j++){
			Vertice start=elist[j].start;
			Vertice end=elist[j].end;
			for(int i=0; i<numofV; i++){
				if(start==vlist[i]){
					counter0=true;
					//temp1
				}
				if(end==vlist[i])
					counter1=true;
			}
			if (!counter0&&!counter1){
				delete[] vlist;
				delete[] elist;
				throw undefinedVertice0(start.symbol +" and "+ end.symbol);
			}
			if(!counter0){
				delete[] vlist;
				delete[] elist;
				throw undefinedVertice0(start.symbol);
			}
			if(!counter1){
				delete[] vlist;
				delete[] elist;
				throw undefinedVertice0(end.symbol);
			}
			counter0=false;
			counter1=false;
		}
		file.close();

		Graph returnGraph(vlist,elist,numofV,numofE);
		delete[] vlist;
		delete[] elist;
		return returnGraph ;
	}
autoGraph readFile3(char* dest){
	std::ifstream file(dest);
	string line;
	int numofV=0;
	int numofE=0;
	getline(file,line);
	if(line[0]=='S')
		numofV++;
	else if(line.length()==0)
		throw InvalidInput();
	while(line[0]=='S'&&file && std::getline(file,line)){
		string check=line.substr(0,2);
		if(check.compare("S:")==0){
			numofV++;
		}
	}
	if(line[0]=='T')
		numofE++;
	else
		throw InvalidInput();
	while(line[0]=='T'&&file && std::getline(file,line)){
		string check=line.substr(0,2);
		if(check.compare("T:")==0)
			numofE++;
	}
	if(line!=""&&file)
		throw InvalidInput();
	file.close();
	Vertice* vlist=new Vertice[numofV];
	Edge* elist=new Edge[numofE];
	int i=0;
	int j=0;
	file.open(dest);
	while(file && std::getline(file,line)){
			if(i<numofV&&line.substr(0,2).compare("S:")==0){
				if(line.substr(2).length()-3<1){
					delete[] vlist;
					delete[] elist;
					throw InvalidInput();
				}
				string temp=line.substr(2);
				int u=0;
				string name="";
				string state="";
				while(temp[u]!=','){
					name=name+temp[u];
					u++;
				}
				u++;
				if(temp[temp.length()-1]=='\r'){
					while(u<temp.length()-1){
						state=state+temp[u];
						u++;
					}
				}
				else
					while(u<temp.length()){
						state=state+temp[u];
						u++;
					}

				//name=name.substr(0,name.length()-name.find(',')-1);
				//string state;
				//if(line[line.length()-1]=='\r')
				//	 state=line.substr(line.length()-2,1);
				//else
				//	 state=line.substr(line.length()-1,1);
				Vertice newV(name,state);
				vlist[i]=newV;
				i++;
			}
			if(j<numofE&&line.substr(0,2).compare("T:")==0){
				Edge newE;
				if(line[line.length()-1]=='\r')
					 newE=createAutoEdge(line.substr(2,line.substr(2).length()-1));
				else
					 newE=createAutoEdge(line.substr(2,line.substr(2).length()));
				elist[j]=newE;
				j++;
			}

		}
	bool counter0 = false;
		bool counter1 = false;
		for(int j=0;j<numofE;j++){
			Vertice start=elist[j].start;
			Vertice end=elist[j].end;
			for(int i=0; i<numofV; i++){
				Vertice temp=vlist[i];
				if(start==vlist[i]){
					counter0=true;
					//temp1
				}
				if(end==vlist[i])
					counter1=true;
			}
			if (!counter0&&!counter1){
				delete[] vlist;
				delete[] elist;
				throw undefinedVertice0(end.symbol);
			}
			if(!counter0){
				delete[] vlist;
				delete[] elist;
				throw undefinedVertice0(end.symbol);
			}
			if(!counter1){
				delete[] vlist;
				delete[] elist;
				throw undefinedVertice0(end.symbol);
			}
			counter0=false;
			counter1=false;
		}
		file.close();

	autoGraph returnGr(vlist,elist,numofV,numofE);
	delete[] vlist;
	delete[] elist;
	return returnGr;
}
void update(list<Vertice>** listV, int size, Vertice& u){
	for(int i=0;i<size;i++){
		list<Vertice>::iterator it;
		for(it=(*listV)[i].begin();it!=(*listV)[i].end();++it){
			if(*it==u)
				*it=u;
		}
	}
}
list<Vertice> path(list<Vertice>* listG ,Vertice v1,Vertice v2,int size){
	string temp=v2.symbol;
	list<Vertice> returnlist;
	bool check2=true;
	int counter=0;
	while(temp.compare(v1.symbol)!=0){
		counter++;
		check2=true;
		if(counter>size+1)
			break;
		for(int i=0;i<size&&check2;i++){
				if(listG[i].front().symbol.compare(temp)==0){
					Vertice myver=listG[i].front();
					returnlist.push_front(myver);
					temp=myver.dad;
					check2=false;
				}
			}
	}
	if(counter>size+1){
		list<Vertice> nullList;
		return nullList;
	}

	returnlist.push_front(v1);
	return returnlist;
}
void autoAlg(autoGraph G, char* path){
	std::ifstream file(path);
	string line;
	list<Vertice>* listG=G.getVertList();
	/*for(int i=0;i<G.edgeSize;i++){
			listE[i]=G.getEdge(i);
		}*/

	bool check=true;
	Vertice temp;
	while(file && std::getline(file,line)){
		Vertice temp=listG[0].front();
		int length=line.length();
		if(line[line.length()-1]=='\r')
			length=line.length()-1;
		for(int k=0;k<length;k++){
			check=true;

			for(int i=0;i<G.edgeSize;i++){

				if(G.getEdge(i).start==temp&&line[k]==G.getEdge(i).state){
					for(int t=0;t<G.size;t++){
						if(G.vertList[t].front()==G.getEdgeList()[i].end){
							temp=listG[t].front();
							check=false;
							break;
						}
					}
					break;
				}
			}
			if(check){
				cout<<"FALSE"<<endl;
				break;
			}
		}
		if(check)
			continue;
		else if(temp.state=="$")
			cout<<"TRUE"<<endl;
		else
			cout<<"FALSE"<<endl;
	}
	file.close();

}
void printCity(cityGraph* G,list<Vertice>* listV){
	vector<Vertice> vectorV;
	//list<Vertice> listV=listG;
	list<Vertice>::iterator it;
	for(it=(*listV).begin();it!=(*listV).end();++it)
		vectorV.push_back(*it);
	if(vectorV.size()==0)
		return;
	for(int i=0;i<vectorV.size()-1;i++){
		Vertice v1(vectorV[i]);
		Vertice v2(vectorV[i+1]);
		for(int j=0;j<G->getEdgeSize();j++){
			if(G->getEdge(j)->start==v1&&G->getEdge(j)->end==v2){
				if(i==0)	{
					cout<<G->getEdge(j)->start<<","<<G->getEdge(j)->RoadLength<<"-"<<G->getEdge(j)->RoadType<<","<<G->getEdge(j)->end;
					break;
				}
				else{
					cout<<","<<G->getEdge(j)->RoadLength<<"-"<<G->getEdge(j)->RoadType<<","<<G->getEdge(j)->end;
					break;
				}
			}
		}
		if(i==vectorV.size()-2)
			cout<<endl;
	}
}
bool check(absGraph* G, Vertice v1, Vertice v2){
	bool test1=true;
	bool test2=true;
	for(int i=0;i<G->getSize();i++){
		if(G->getVertice(i).front()==v1)
			test1=false;
		if(G->getVertice(i).front()==v2)
			test2=false;
	}
	if(!test1&&!test2)
		return true;
	return false;
}
bool check(absGraph* G, Vertice v1){
	bool test1=true;
	for(int i=0;i<G->getSize();i++){
		if(G->getVertice(i).front()==v1)
			test1=false;
	}
	if(!test1)
		return true;
	return false;
}
