#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include "funzioni.h"

using namespace std;

int ottieni_N(string nomefile) {
	int n=0;
	fstream file;
	string temp;
	file.open(nomefile, std::ios::in);
	if (!file) { std::cout << "errore! file non trovato!"; exit(1); }
	while (file >> temp) {
		n++;
	}
	return n;
}
void caricaVettore(string nomefile, string v[]) {
	int i = 0;
	fstream file;
	file.open(nomefile, ios::in);
	if (!file) { std::cout << "errore! file non trovato!"; exit(1); }
	while (file >> v[i]) {
		i++;
	}
}
void scambia(char &a, char &b) {
	char t = a;
	a = b;
	b = t;
}
void ordinaParola(string &parola) {
	//ordinamento a bolle
	int n = parola.length();
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j <n-i- 1; j++) {
			if (parola[j] > parola[j + 1]) {
				scambia(parola[j], parola[j + 1]);
			}
		}
	}
}
void controllaOccorrenze(string parola) {
	//studio ogni parola
	string salvaP = parola;
	int k = 0, j = 0, max = 0;
	bool t = false;
	char occM=' ';

	lettere *temp = new lettere[parola.length()];
	for (unsigned i = 0; i <parola.length()-1; i++) {
		//assegno a j il carattere successivo ad i
		j = i + 1;
		t = false;//mi indica se ho trovato una lettera più di una volta
		while (parola[i] == parola[j]) {
			//fin quando ci sono lettere uguali, incremento le occorrenze della lettera
			temp[k].lettera = parola[i];
			temp[k].occ++;
			t = true;
			j++;
		}
		if (t) k++;//se ho trovato più di una parola, vado alla lettera successiva
		i = j-1;//faccio un salto nel for per ritrovarmi alla nuova lettera differente
	}

	//trovo il massimo
	for (int i = 0; i < k; i++) {
		if (temp[i].occ > max) {
			max = temp[i].occ;
			occM = temp[i].lettera;
		}
	}
	delete[]temp;
	cout<< occM << " " << max<<endl;
}
