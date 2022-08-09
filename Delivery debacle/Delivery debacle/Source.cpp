#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
/*
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
*/
	int ncasos;

	cin >> ncasos;

	vector<vector<long long int>> dynamic_matrix;
	for (int i = 0; i <= 40; i++) {
		vector<long long int> column(4, 0);
		dynamic_matrix.push_back(column);
	}

	dynamic_matrix[1][2] = 1;
	dynamic_matrix[1][3] = 1;

	for (int i = 2; i <= 40; i++) {
		dynamic_matrix[i][0] = dynamic_matrix[i - 1][2] * 2 + dynamic_matrix[i - 1][1] * 1;
		dynamic_matrix[i][1] = dynamic_matrix[i - 1][2] * 2;
		dynamic_matrix[i][2] = dynamic_matrix[i - 1][0] + dynamic_matrix[i - 1][1] + dynamic_matrix[i - 1][2];
		dynamic_matrix[i][3] = dynamic_matrix[i][2] + dynamic_matrix[i][1] + dynamic_matrix[i][0];
	}

	int n_deseado;

	for (int i = 0; i < ncasos; i++) {
		cin >> n_deseado;
		cout << dynamic_matrix[n_deseado][3] << "\n";
	}
/*
	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif
*/


	return 0;
}