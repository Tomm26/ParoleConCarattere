#include "pch.h"
#include "funzioni.h"
#include <iostream>
using namespace std;


int main()
{
	string *parole, nomefile;
	int n;
	cout <<"Inserisci nome file: " ;
	cin >> nomefile;

	n=ottieni_N(nomefile);

	parole = new string[n];

	caricaVettore(nomefile, parole);

	for (int i = 0; i < n; i++) {
		cout <<"la parola "<< parole[i] << " ha lettera massima: ";
		ordinaParola(parole[i]);
		controllaOccorrenze(parole[i]);
	}
	delete[] parole;
}
