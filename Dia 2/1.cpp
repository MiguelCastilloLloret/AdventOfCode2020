#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
#include"intervalo.h"

bool validar_password(intervalo<int> veces, char letra[], char password[]){
	int contador = 0;
	int i = 0;
	while(i<strlen(password) && contador<=veces.fin){
		if(password[i] == letra[0]) contador++;
		i++;
	}
	if(contador>=veces.inicio && contador<=veces.fin) return true;
	else return false;
}

int main(){
	intervalo<int> veces;
	std::ifstream f("2020.txt");
	char inicio[3], fin[3], letra[2], cadena[30];
	bool validez_password;
	std::string password, caracter;
	int password_validas = 0;

	while(f.getline(inicio,3,'-')){
		veces.inicio = strtol(inicio,NULL,10);
		f.getline(fin,3,' ');
		veces.fin = strtol(fin,NULL,10);
		f.getline(letra,2,':');
		f.ignore(1);
		f.getline(cadena,25);
		validez_password = validar_password(veces,letra,cadena);
		if(validez_password) password_validas++;
	}
	std::cout<<password_validas<<std::endl;
	f.close();
	return 0;
}