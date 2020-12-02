
template<typename T> class intervalo{
	public:
		int inicio, fin;
		intervalo(T A, T B){
			inicio = A;
			fin = B;
		}
		intervalo() {}
};