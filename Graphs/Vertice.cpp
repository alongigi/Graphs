/*
 * Vertice.cpp
 *
 *  Created on: Jan 13, 2017
 *      Author: alex
 */
#include "Vertice.h"
Vertice::Vertice(): visited(false),d(0){
	state="%";
}
Vertice::Vertice(string name):visited(false),d(0){
	symbol=name;
	state="%";

}
Vertice::Vertice(string name,string st):visited(false),d(0){
	symbol=name;
	state=st;

}
Vertice::Vertice(const Vertice& other){
	symbol=other.symbol;
	visited=other.visited;
	d=other.d;
	dad=other.dad;
	state=other.state;


}
Vertice& Vertice::operator=(const Vertice& other){
	symbol=other.symbol;
	visited=other.visited;
	d=other.d;
	dad=other.dad;
	state=other.state;
	return *this;
}
bool Vertice::operator==(const Vertice& other){
	return symbol.compare(other.symbol)==0;
}
bool Vertice::operator!=(const Vertice& other){
	return symbol.compare(other.symbol)!=0;
}
bool Vertice::operator<(const Vertice& other)const{
	return d>other.d;
}
void Vertice::printV(){
	cout<<symbol;
}
Vertice:: ~Vertice(){}
ostream& operator<<(ostream& out, const Vertice& v) {
	return v.Show(out);
}
string Vertice::getState(){
	return state;
}
ostream& Vertice::Show(ostream& out) const{
	out<<symbol;
	return out;
}
