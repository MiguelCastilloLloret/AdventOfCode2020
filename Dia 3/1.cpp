#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<list>
#include"slope.h"

int main(){
	std::ifstream f("2020.txt");
	std::list<std::string> toboggan;
	std::string p;
	int horizontal = 0;
	int trees = 0;

	while(!f.eof()){
		f>>p;
		toboggan.push_back(p);
	}

	trees = slope(toboggan,3,1);

	std::cout<<trees;

	return 0;
}