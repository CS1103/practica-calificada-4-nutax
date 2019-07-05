// PC4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "max.h"

using namespace std;

int main()
{
	vector<int> entero = {3,2,1,1, 4, 4};
	vector<double> decimal = {4.2, 5.1, 12.0, 32.9};
	//vector<double> numgrande = { 123231, 3123122, 2312315, 1232131, 1231231, 2312381293 };
	vector<char> letra = {'s', 'z', 'a', 'r'};
	vector<bool> logica = {false, false, true, true};

	cout << max(entero, 3);
	cout << max(decimal, 3);
	cout << max(letra, 3);
	cout << max(logica, 3);
}