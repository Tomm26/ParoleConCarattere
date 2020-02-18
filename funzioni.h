#pragma once
#include <string>
using namespace std;
struct lettere {
	char lettera=' ';
	int occ=1;
};

int ottieni_N(string nomefile);
void caricaVettore(string nomefile, string v[]);
void scambia(char &a, char &b);
void ordinaParola(string &parola);
void controllaOccorrenze(string parola);
