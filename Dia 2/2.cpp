#include<iostream>
#include<fstream>
#include<cstdlib>
#include"intervalo.h"

bool validar_password(intervalo<int> par, char letra[], char password[]){
	if((password[par.inicio] == letra[0] && password[par.fin] != letra[0]) || (password[par.inicio] != letra[0] && password[par.fin] == letra[0])) return true;
	else return false;
}

int main(){
	intervalo<int> par;
	std::ifstream f("2020.txt");
	char inicio[3], fin[3], letra[2], cadena[30];
	bool validez_password;
	int password_validas = 0;

	while(f.getline(inicio,3,'-')){
		par.inicio = strtol(inicio,NULL,10)-1;
		f.getline(fin,3,' ');
		par.fin = strtol(fin,NULL,10)-1;
		f.getline(letra,2,':');
		f.ignore(1);
		f.getline(cadena,25);
		validez_password = validar_password(par,letra,cadena);
		if(validez_password) password_validas++;
	}
	std::cout<<password_validas<<std::endl;
	f.close();
	return 0;
}