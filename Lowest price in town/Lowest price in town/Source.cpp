#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

bool resuelveCaso(int n_caso) {

	if (!cin) return false;

    vector<pair<int, double>> vector_precios;

    double precio;
    int unidades;
    int cantidad;
    cin >> precio >> cantidad;

    vector_precios.push_back({ 1, precio });

    for (int i = 0; i < cantidad; i++) {
        
        cin >> unidades;
        cin >> precio;
        vector_precios.push_back({ unidades, precio });
        
    }

    vector<int> list_numbers;
    int max_number = 0;
    string line;
    cin.ignore();
    getline(cin, line);
    istringstream stream(line);

    list_numbers = vector<int>(std::istream_iterator<int>(stream),std::istream_iterator<int>());
    for (int next_number : list_numbers) {
        max_number = std::max(next_number, max_number);
    }
    for (int i = 0; i < vector_precios.size(); i++) {
        max_number = std::max(vector_precios[i].first, max_number);
    }

    vector<double> matrix_dynamic(101, -1);
    matrix_dynamic[0] = 0;

    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j < vector_precios.size(); j++) {
            unidades = vector_precios[j].first;
            precio = vector_precios[j].second;
            while (i >= unidades && unidades > 0) {
                double precio_total = matrix_dynamic[i - unidades] + precio;
                if (matrix_dynamic[i] == -1 || matrix_dynamic[i] > precio_total) {
                    matrix_dynamic[i] = precio_total;
                }
                unidades--;
            }
        }
    }

    for (int i = 99; i >= 0; i--) {
        matrix_dynamic[i] = min(matrix_dynamic[i], matrix_dynamic[i + 1]);
    }


    if (list_numbers.size() > 0) {
        cout << "Case " << n_caso << ":\n";
    }

    for (int i = 0; i < list_numbers.size(); i++) {
        
        double result = matrix_dynamic[list_numbers[i]];

        
        cout << "Buy " << list_numbers[i] << " for $";
        cout << fixed << setprecision(2) << result  << "\n";
    }
    
	return true;
}


int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*
#ifndef DOMJUDGE
    ifstream in("datos.txt");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif */

    int i = 1;
    while (resuelveCaso(i)) {
        i++;
    }

/*
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}