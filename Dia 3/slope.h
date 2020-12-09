int slope(std::list<std::string> toboggan, int slope_right, int slope_down){
	auto iterator = toboggan.begin();
	int horizontal = 0;
	int trees = 0;
	int down = 0;

	while(iterator != toboggan.end()){
		horizontal = horizontal + slope_right;
		if(horizontal > ((*iterator).size()-1)) horizontal = horizontal - (*iterator).size();
		while(down < slope_down && ++iterator != toboggan.end()) ++down;
		if((*iterator)[horizontal] == '#') ++trees;
		down = 0;
	}

	return trees;
}