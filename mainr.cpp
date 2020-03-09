#include<iostream>
#include "rojinegro.h"
using namespace std;
int main(){
	rojinegro a;
	nodor *b;

	a.insertar(86);
	cout<<endl;
	a.insertar(65);
	cout<<endl;
	a.insertar(70);
	cout<<endl;
	
	a.insertar(73);
	cout<<endl;
	a.insertar(93);
	cout<<endl;
	a.insertar(69);
	cout<<endl;
	
	a.insertar(25);
	cout<<endl;
	a.insertar(66);
	cout<<endl;
	a.insertar(68);
	cout<<endl;
	a.insertar(47);
	cout<<endl;
	a.insertar(62);
	cout<<endl;
	a.insertar(10);
	cout<<endl;
	a.insertar(30);
	cout<<endl;

	
	a.buscar(500);
	a.buscar(86);
	a.buscar(600);
	a.buscar(65);
	a.buscar(30);
	a.buscar(70);
	a.buscar(55);
	a.buscar(73);
	a.buscar(93);
	a.buscar(69);
	a.buscar(25);
	a.buscar(66);
	a.buscar(68);
	a.buscar(47);
	a.buscar(62);
	a.buscar(10);
		
	return 0;
}

