#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<algorithm>
#include"busqueda_binaria.h"

long encontrar2020(std::vector<long> x){
	int res;
	std::sort(x.begin(),x.end());
	for (auto iterador = x.begin(); iterador < x.end(); iterador++){
		int res = busqueda_binaria(2020-*iterador,x,0,x.size()-1);
		if(res != -1) return x[res]*(*iterador);
	}
	return -1;
}

int main(){
	std::ifstream f("2020.txt");
	std::vector<long> x;
	char c[10];
	long res;

	while(!f.eof()){
		f.getline(c,10);
		x.push_back(strtol(c,NULL,10));
	}

	f.close();
	res = encontrar2020(x);
	if(res == -1) std::cout<<"No hay dos numeros que sumen 2020"<<std::endl;
	else std::cout<<"El resultado es "<<res<<" ."<<std::endl;
	return 0;
}