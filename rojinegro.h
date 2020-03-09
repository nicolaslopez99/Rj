#ifndef ROJINEGRO_H
#define ROJINEGRO_H

#include<iostream>
#include<iostream>
using namespace std;

struct nodor{
	int dato;
	nodor *izq,*der;
	bool color;
};

class rojinegro{
	nodor *raiz;
	void comprobar(nodor *padre,nodor *hijo);
	void inorden(nodor *raiz);
	void rotarizq(nodor *pibote);
	void rotarder(nodor *pibote);
	
	public:
		
		rojinegro(){
			raiz = NULL;			
		}
		void insertar(int dato);
		nodor buscar(int dato);
		void mostrar(nodor *p);
};
void rojinegro::rotarizq(nodor *pibote){
	nodor *hijoizq, *hijoder,*padre,aux;
	aux = buscar(pibote->dato);
	hijoder = pibote->der;
	if (aux.der->dato != pibote->dato){
		
		padre = aux.der;
		padre->izq = hijoder; 
		pibote->der = hijoder->izq;
		hijoder->izq = pibote;
		
	}else {
		nodor *aux1;
		padre = NULL;
		aux1 = hijoder;
		pibote->der = aux1->izq;
		aux1->izq = pibote;
		raiz = aux1;
	}

	
}
void rojinegro::rotarder(nodor *pibote){
	nodor *hijoizq, *hijoder,*padre,aux;
	aux = buscar(pibote->dato);
	hijoizq = pibote->izq;
	hijoder = pibote->der;
	
	if (aux.der != pibote){
		
		padre = aux.der;
		padre->der = hijoizq; 
		pibote->izq = hijoizq->der;
		hijoizq->der = pibote;
	}else {
		nodor *aux1;
		padre = NULL;
		aux1 = hijoizq;
		pibote->izq = aux1->der;
		aux1->der = pibote;
		raiz = aux1;
	}
	
}
void rojinegro::inorden(nodor *p){
	nodor *aux;
	int cuenta = 0;
	if (p!=NULL){
		inorden(p->izq);
		if (p->color == 1 && cuenta<1){
			if (p->izq!=NULL){
				aux = p->izq;
				if (aux->color==1){
					//cout<<p->dato<<" "<<aux->dato<<"HOLA"<<endl;
					comprobar(p,aux);
					cuenta++;
				}
			}
			if (p->der !=NULL){
				aux = p->der;
				if(aux->color==1){
					//cout<<p->dato<<" "<<aux->dato<<"CHAO"<<endl;
					comprobar(p,aux);
					cuenta++;
				}
			}	
		}
        inorden(p->der);
	}
	
}
void rojinegro::comprobar(nodor *padre,nodor *hijo){
	if (padre->color!=1 || hijo->color !=1){
		return;
	}
	nodor *tio=NULL;
	bool colortio;
	nodor *abuelo;
	nodor aux;
	aux = buscar(padre->dato);
	abuelo = aux.der;
	
	
	if (abuelo->der == NULL || abuelo->izq == NULL){
		colortio = 0;
		if (abuelo->der == NULL){
			if (hijo->dato > padre->dato){
				cout<<"Caso 2 sin tio derecho"<<endl;
				rotarizq(padre);
//				cout<<hijo->dato<<" "<<padre->dato<<" "<<abuelo->dato<<endl;
				padre = hijo;
				hijo =padre->izq;
			//	cout<<hijo->dato<<" "<<padre->dato<<" "<<abuelo->dato<<endl;
				if (abuelo->color ==0){
					abuelo->color = 1;	
				}else {
					abuelo->color = 0;
				}
				padre->color = 0;
				rotarder(abuelo);
				
			}else if(hijo->dato < padre->dato) {
				cout<<"Caso 3 sin tio derecho"<<endl;
				if (abuelo->color ==0){
					abuelo->color = 1;	
				}else {
					abuelo->color = 0;
				}
				padre->color = 0;
				rotarder(abuelo);
			}
		} else if(abuelo->izq == NULL) {
			if (hijo->dato < padre->dato){
				cout<<"Caso 2 sin tio izquierdo"<<endl;
				rotarder(padre);
				padre = hijo;
				hijo =padre->der;
				if (abuelo->color ==0){
					abuelo->color = 1;	
				}else {
					abuelo->color = 0;
				}
				padre->color = 0;
				rotarizq(abuelo);
			}else if (hijo->dato > padre->dato){
				cout<<"Caso 3 sin tio izquierdo"<<endl;
				if (abuelo->color ==0){
					abuelo->color = 1;	
				}else {
					abuelo->color = 0;
				}
		//		cout<<abuelo->dato<<endl;
				padre->color = 0;
				rotarizq(abuelo);
			}
		}
		
	}else if (abuelo->izq !=NULL && abuelo->der !=NULL){
		if (abuelo->der == padre){
			tio = abuelo->izq;
		}else if (abuelo->izq == padre){
			tio = abuelo->der;
		}
		if (tio->color == 1){
			cout<<"Caso 1 "<<endl;
			if (abuelo->color ==0){
				abuelo->color = 1;	
			}else {
				abuelo->color = 0;
			}
			padre->color = 0;
			tio->color =0;
		} else if (tio->color ==0){
			if(tio->dato > abuelo->dato){
				if (hijo->dato > padre->dato){
					cout<<"Caso 2 con tio derecho"<<endl;
					rotarizq(padre);
					padre = hijo;
					hijo =padre->izq;
					if (abuelo->color ==0){
						abuelo->color = 1;	
					}else {
						abuelo->color = 0;
					}
					padre->color = 0;
					rotarder(abuelo);
				}else if(hijo->dato < padre->dato) {
					cout<<"Caso 3 con tio derecho"<<endl;
					if (abuelo->color ==0){
						abuelo->color = 1;	
					}else {
						abuelo->color = 0;
					}
			//		cout<<abuelo->dato<<endl;
					padre->color = 0;
					rotarder(abuelo);
				}
			} else  if(tio->dato < abuelo->dato){
				if (hijo->dato < padre->dato){
					cout<<"Caso 2 con tio izquierdo"<<endl;
					rotarder(padre);
					padre = hijo;
					hijo =padre->der;
					if (abuelo->color ==0){
						abuelo->color = 1;	
					}else {
						abuelo->color = 0;
					}
					padre->color = 0;
					rotarizq(abuelo);
				}else if (hijo->dato > padre->dato){
					cout<<"Caso 3 con tio izquierdo"<<endl;
					if (abuelo->color ==0){
						abuelo->color = 1;	
					}else {
						abuelo->color = 0;
					}
					padre->color = 0;
					
					rotarizq(abuelo);
				}
				
			}
		}	
	}
	raiz->color=0;
	
}

void rojinegro::insertar(int dato){
	nodor *aux = raiz;
	nodor *aux1;
	nodor *nuevo = new nodor;
	nuevo->dato = dato;
	nuevo->color = 1;
	nuevo->izq = NULL;
	nuevo->der = NULL;
	
	if (raiz == 0){
		nuevo->color = 0;	
		raiz=nuevo;
	}else {
		while(aux!=NULL){
			aux1=aux;
			if(dato<aux->dato){
				aux=aux->izq;
			}else{
				aux=aux->der;
			}
		}
		if(dato<aux1->dato){
			aux1->izq=nuevo;
		} else {
			aux1->der=nuevo;
		}
	}
	inorden(raiz);
	mostrar(raiz);
	cout<<endl;
}
nodor rojinegro::buscar(int dato){
	nodor *hijo;
	nodor *padre = raiz;
	nodor info;
	info.dato = NULL;
	info.izq = NULL;
	info.der = NULL;
	info.color = NULL;
	hijo=padre;
	while(padre!=NULL && dato!= padre->dato){
		hijo=padre;
		if(dato<padre->dato){
			padre=padre->izq;
		}else{
			padre = padre->der;
		}
	}
	if (padre == NULL){
		cout<<"Dato no encontrado "<<dato<<endl;
		return info;
	} else if (dato == padre->dato){
		cout<<"Dato encontrado "<<endl;
		info.dato = padre->dato;
		info.izq = padre;
		info.der= hijo;
		info.color = padre->color;
		return info;	
	} else {
		cout<<"Hola :3"<<endl;
	}
	
}
void rojinegro::mostrar(nodor *p){
	if (p!=NULL){
		mostrar(p->izq);
		cout<<p->dato<<" "<<p->color<<endl;
        mostrar(p->der);
	}
}
#endif
