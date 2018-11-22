#include <iostream>
using namespace std;

int menu();
void Imprimir(int piso[][20], int t);
void Avanzar(int piso[][20],int tam,int sentido, int pluma,int &fila, int &columna);

int main()
{
	int pluma=0;
	int op,pos,fila=0,columna=0;
	int sentido = 2; //1.-arriba, 2.-derecha, 3.-abajo, 4.-izquierda
	int piso[20][20]={0};
	do
	{
		op=menu();
		switch(op)
		{
			case 1:
			{
				pluma=0;
				cout <<"\nLa pluma esta hacia arriba. " <<endl;
				break;
			}
			case 2:
			{
				pluma=1;
				cout <<"\nLa pluma esta hacia abajo. " <<endl;
				break;
			}
			case 3:
			{
				if(sentido == 4)
					sentido = 1;
				else
					sentido++;
					cout << "Gira a la derecha";

				break;
			}
			case 4:
			{
				if(sentido==1)
					sentido=4;
				else
					sentido--;
					cout << "Gira a la izquierda";
				break;
			}
			case 5:
			{
				Avanzar(piso,20,sentido,pluma,fila,columna);
				break;
			}
			case 6:
			{
				Imprimir(piso,20);
				break;
			}
		}
	}while(op!=0);
	return 0;
}

int menu()
{
	int op;
	cout << "--------Menu--------" << endl;
	cout << "1. Pluma hacia arriba" << endl;
	cout << "2. Pluma hacia abajo" << endl;
	cout << "3. Girar hacia la derecha" << endl;
	cout << "4. Girar hacia la izquierda" << endl;
	cout << "5. Avanzar" << endl;
	cout << "6. Mostrar" << endl;
	cout << "0. Salir" << endl;
	cin >> op;
	cout << endl;
	return op;
}

void Imprimir(int piso[][20], int t)
{
	for(int r=0;r<t;r++)
	{
		for(int c=0;c<20;c++)
		{
			if (1==piso[r][c])
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
}

void Avanzar(int piso[][20],int tam,int sentido, int pluma,int &fila, int &columna)
{
	int num,num1,num2;
	cout << "Cuantos pasos desea avanzar: " << endl;
	cin >> num;
	cout << endl;
	num1=num;
	num1+=fila;
	num2=num;
	num2+=columna;
	if(sentido==1)
	{
		for(;fila>(num1-(num*2));fila--)
		piso[fila][columna]=pluma;
	}
	else if(sentido==2)
	{
		for(;columna<num2;columna++)
			piso[fila][columna]=pluma;
	}
	else if(sentido==3)
	{
		for(;fila<num1;fila++)
			piso[fila][columna]=pluma;
	}
	else
	{
		while(columna>(num2-(num*2)))
		{
			piso[fila][columna]=pluma;
			columna--;
		}
	}
}

