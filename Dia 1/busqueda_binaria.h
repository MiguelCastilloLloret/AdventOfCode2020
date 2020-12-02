

int busqueda_binaria(long value, std::vector<long> x, int inicio, int fin){
	if(inicio >= fin && x[inicio] == value) return inicio;
	else if(inicio >= fin && x[inicio] != value) return -1;
	else{
		int pivote = inicio+((fin-inicio)/2);
		if(x[pivote] == value) return pivote;
		else if(x[pivote] < value){ 
			return busqueda_binaria(value,x,++pivote,fin);
		}
		else {
			return busqueda_binaria(value,x,inicio,--pivote);
		}
	}
}
