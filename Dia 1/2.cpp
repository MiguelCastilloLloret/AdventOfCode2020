#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<vector>
#include"busqueda_binaria.h"


long encontrar2020(std::vector<long> x){
	int res;
	std::sort(x.begin(),x.end());
	for (auto iterador = x.begin(); iterador < x.end(); iterador++){
		for(auto iterador2 = x.begin(); iterador2 < x.end(); iterador2++){
			res = busqueda_binaria(2020-((*iterador)+(*iterador2)),x,0,x.size()-1);
			if(res != -1) return x[res]*(*iterador)*(*iterador2);
		}
	}
	return -1;
}

int main(){
	std::ifstream f("2020.txt");
	std::vector<long> x;
	char c[10];
	int res;

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