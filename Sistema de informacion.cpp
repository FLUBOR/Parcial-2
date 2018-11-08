#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int menu();
void reporte(int v[],int t);
void agregar(int v[],int t,int pos);
bool eliminar(int v[],int t, int valor);
int buscar(int v[],int t,int valor);
void insertar(int v[],int t,int pos);
void modificar(int v[],int t,int nuevo, int viejo);
int aleatorio();
void recorrer(int n[],int tam,int p);

int main()
{
	srand(time(NULL));
	int v[20];
	int cont=0,op;
	do
	{
		op=menu();
		switch(op)
		{
			case 1:
			{
				agregar(v,20,cont);
				cont++;
				break;
			}
			case 2:
			{
				int valor;
				cout << "Valor a eliminar: ";
				cin >> valor;
				cout << endl;
				if(eliminar(v,20,valor))
				{
					cont--;
					cout << "Eliminado" << endl; 
				}
				else
					cout << "No existe" << endl;
					
				break;
			}
			case 3:
			{
				int valor;
				cout << "Valor:";
				cin >> valor;
				cout << endl;
				int b=buscar(v,20,valor);
				cout << "Posicion del valor: " << b << endl <<endl;
				break;
			}
			case 4:
			{
				int nuevo,viejo;
				cout << "Valor a reemplazar: ";
				cin >> viejo;
				cout << endl << "Valor nuevo: ";
				cin >> nuevo;
				cout << endl;
				modificar(v,20,nuevo,viejo);
				break;
			}
			case 5:
			{
				int pos;
				do
				{
					cout << "Posicion:";
					cin >> pos;
					cout << endl;
				}while(!(pos>=0 && pos<20));
				
				insertar(v,20,pos);
				break;
			}
			case 6:
			{
				reporte(v,20);
				break;
			}
			case 0:{
				cout << endl << "Fin de programa." << endl;
				break;
			}
			default:
				cout << "Ingresa una opcion valida." << endl;
		}
	}while(op!=0);
	
	
}

int menu()
{
	int op;
	cout << "1.- Agregar" << endl;
	cout << "2.- Eliminar" << endl;
	cout << "3.- Buscar" << endl;
	cout << "4.- Modificar" << endl;
	cout << "5.- Insertar" << endl;
	cout << "6.- reporte" << endl;
	cout << "0.- salir" << endl;
	cout << ">";
	cin >> op;
	cout << endl;
	return op;
}

void agregar(int v[],int t,int pos)
{
	int num;
	if(pos<t)
	{
		v[pos]=aleatorio();
	}
}

bool eliminar(int v[],int t, int valor)
{
	int b=buscar(v,t,valor);
	if(b>=0)
	{
		v[b]=0;
		recorrer(v,t,b);
		return true;
	}
	else
		return false;
}


int buscar(int v[],int t,int valor)
{
	for(int i=0;i<t;i++)
	{
		if(v[i]==valor)
			return i;
	}
	return -1;
}

void modificar(int v[],int t,int nuevo, int viejo)
{
	int b=buscar(v,t,viejo);
	if(b>=0)
	{
		v[b]=nuevo;
	}
}

void insertar(int v[],int t,int pos)
{	
	for(int i=t-1;i>=pos;i--)
	{
		v[i+1]=v[i];	
	}
	v[pos]=aleatorio();	
}

void reporte(int v[],int t)
{
	for(int i=0;i<t;i++)
	{
		cout << "[" << i << "] = " << v[i] << endl;
	}
	cout << endl << endl;
}

int aleatorio()
{
	int num;
	num=11+rand()%301;
	return num;
}
//complemento para funcion eliminar
void recorrer(int n[],int tam,int p)
{
	for(int i=p;i<tam-1;i++)
	{
		n[i]=n[i+1];
	}
	n[tam-1]=0;
}
