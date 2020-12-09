#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<list>
#include<vector>
#include"slope.h"

int main(){
	std::ifstream f("2020.txt");
	std::list<std::string> toboggan;
	std::string p;
	std::vector<int> trees(5, 0);
	unsigned long result = 1;

	while(!f.eof()){
		f>>p;
		toboggan.push_back(p);
	}

	trees[0] = slope(toboggan,1,1);
	trees[1] = slope(toboggan,3,1);
	trees[2] = slope(toboggan,5,1);
	trees[3] = slope(toboggan,7,1);
	trees[4] = slope(toboggan,1,2);

	auto treeiterator = trees.begin();

	while(treeiterator != trees.end()){
		std::cout<<(*treeiterator)<<" ";
		result = result*(*treeiterator);
		++treeiterator;
	}

	std::cout<<std::endl<<result;

	return 0;
}