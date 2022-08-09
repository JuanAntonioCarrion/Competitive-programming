#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct range {
	long int min;
	long int max;

	bool operator>(const range& b) {
		if (min > b.min) {
			return true;
		}
		else {
			return false;
		}
	}

    bool operator<=(const range& b) {
        if (min <= b.min) {
            return true;
        }
        else {
            return false;
        }
    }

    friend bool operator<(const range& a, const range& b) {
        if (a.min < b.min) {
            return true;
        }
        else {
            return false;
        }
    }
};


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


bool resuelveCaso() {
    // leer los datos de la entrada
    long int L, G;
    cin >> L >> G;
    if (L == 0 && G == 0) return false;

    vector<range> vector_gas;

    long int centro, radio;
    for (int i = 0; i < G; i++) {
        cin >> centro >> radio;
        range gas;

        gas.max = centro + radio;
        gas.min = centro - radio;

        vector_gas.push_back(gas);
        
    }

    sort(vector_gas.begin(), vector_gas.end());

    range initial;
    initial.min = 0;
    initial.max = 1;

    int prev_idx = -1;

    range actual = initial;
    int contador = 0;
    int idx_candidato_prev = 0;


    long int punto_actual = 0;
    bool impossible = false;

    if (vector_gas[0].min > 0) {
        impossible = true;
    }

    while (punto_actual < L && !impossible) {
        auto it = upper_bound(vector_gas.begin(), vector_gas.end(), actual);
        if (it != vector_gas.begin()) {
            it--;
        }
        int indice = std::distance(vector_gas.begin(), it);
        impossible = true;
        long int siguiente_max = 0;
        while (indice > prev_idx) {

            
            if (vector_gas[indice].max > punto_actual) {
                idx_candidato_prev = indice;
                impossible = false;
                siguiente_max = max(vector_gas[indice].max, siguiente_max);
            }
            
            indice--;
        }
        punto_actual = siguiente_max;
        actual.min = punto_actual;
        prev_idx = idx_candidato_prev;
        contador++;
        
    }
    if (!impossible) {
        cout << G - contador <<"\n";
    }
    else {
        cout << -1 << "\n";
    }

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    /*
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 
*/

    while (resuelveCaso())
        ;

/*
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif*/

    return 0;
}