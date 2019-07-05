#pragma once
#include <vector>
#include <memory>
#include <thread>
#include <algorithm>
using namespace std;

template<typename T>
T mayor(vector<T>& vec, int inicio, int fin) {
	auto mayor = vec[inicio];
	for (int i = inicio; i < fin; i++) {
		if (mayor < vec[i]) {
			mayor = vec[i];
		}
	}
}


template<typename T>
void comparar_rango (vector<T>& vec, int n_t, int id, vector<T>& delimitado) {

	int limite = (id < (n_t-1)) ? (id + 1)*n_t : vec.size();
	int inicio = id * n_t;

	delimitado.emplace_back(mayor, vec, inicio, limite);
	
}


template<typename T>
T max(vector<T>& vec, int n_t) {
	vector<unique_ptr<thread>> hilos;

	vector<T> delimitado;

	if (n_t < vec.size()) { n_t = vec.size(); }

	for (int i = 0; i < n_t; i++) {
		hilos.emplace_back(thread(comparar_rango<T>(vec, n_t, i, ref(delimitado) ) ));
	}
	for (int i = 0; i < n_t; i++) {
		hilos[i]->join();
	}

	return mayor(delimitado, 0, delimitado.size());
}