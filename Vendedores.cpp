#include <iostream>
#include <stdlib.h>
using namespace std;

int menu();
int menu2();
void mostrar(int tienda[][6],int t);
void producto(int tienda[][6],int t,int ven);
void agregar(int tienda[][6], int t, int vendedor, int producto);
int suma(int tienda[][6],int t);

int main()
{
	system("color a");
	int tienda[5][6]={0};
	int op;
	do
	{
		op=menu();
		switch(op)
		{
			case 1:
			{	
				producto(tienda,5,op);
				break;
			}
			case 2:
			{	
				producto(tienda,5,op);
				break;
			}
			case 3:
			{	
				producto(tienda,5,op);
				break;
			}
			case 4:
			{	
				producto(tienda,5,op);
				break;
			}
			case 5:
			{
				mostrar(tienda,5);
				break;
			}	
		}
	}while(op!=0);
	
	return 0;
}

int menu()
{
	int vendedor;
	cout << "1. Vendedor 1" << endl;
	cout << "2. Vendedor 2" << endl;
	cout << "3. Vendedor 3" << endl;
	cout << "4. Vendedor 4" << endl;
	cout << "5. Mostar tabla" << endl;
	cout << "Press 0 salir" << endl;
	cin >> vendedor;
	cout << endl;
	return vendedor;
}

int menu2()
{
	int producto;
	cout << "1. Producto 1" << endl;
	cout << "2. Producto 2" << endl;
	cout << "3. Producto 3" << endl;
	cout << "4. Producto 4" << endl;
	cout << "5. Producto 5" << endl;
	cout << "6. Mostar tabla" << endl;
	cout << "Press 0 salir" << endl;
	cin >> producto;
	cout << endl;
	return producto;
}

void producto(int tienda[][6],int t,int ven)
{
	int op;
	do
	{
		op=menu2();
		switch(op)
		{
			case 1:
			{
				agregar(tienda,t,ven,op);
				break;
			}
			case 2:
			{
				agregar(tienda,t,ven,op);
				break;
			}
			case 3:
			{
				agregar(tienda,t,ven,op);
				break;
			}
			case 4:
			{
				agregar(tienda,t,ven,op);
				break;
			}
			case 5:
			{
				agregar(tienda,t,ven,op);
				break;
			}
			case 6:
			{
				mostrar(tienda,5);
				break;
			}
		}
	}while(op!=0);
}

void agregar(int tienda[][6], int t, int vendedor, int producto)
{
	int cosa;
	cout << "Cantidad: " << endl;
	cin >> cosa;
	cout << endl;
	tienda[vendedor-1][producto-1]+=cosa;
}

void mostrar(int tienda[][6],int t)
{	
	suma(tienda,5);
	for(int i=0;i<6;i++)
		cout << "\t[" << i+1 << "]" ;
	cout << endl;
	
	for(int i=0;i<t;i++)
	{
		cout << "[" << i+1 << "] = \t";
		for(int j=0;j<6;j++)
		{
			cout << tienda[i][j] << "\t";
		}
		cout << endl;
	}	
}

int suma(int tienda[][6],int t)
{
	int n1=0, n2=0;
	for(int i=0;i<t-1;i++)
	{
		for(int j=0;j<5;j++)
		{
			
			
			n2+=tienda[i][j];//renglones
			tienda[i][5]=n2;
		}
		n2=0;
	}
	for(int j=0;j<5;j++)
	{
		for(int i=0;i<t-1;i++)
		{
			n1+=tienda[i][j];//columnas
			tienda[4][j]=n1;
		}
		n1=0;
	}
}
