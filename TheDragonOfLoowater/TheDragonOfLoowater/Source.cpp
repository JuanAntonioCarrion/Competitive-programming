
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


bool resuelveCaso() {
    // leer los datos de la entrada

    int n_caballeros, n_cabezas;

    cin >> n_cabezas >> n_caballeros;

    if (n_cabezas == 0 && n_caballeros == 0) return false;

    vector<int> cabezas;
    vector<int> caballeros;
    int cabeza;
    int caballero;
    for (int i = 0; i < n_cabezas; i++) {
        cin >> cabeza;
        cabezas.push_back(cabeza);
    }

    for (int i = 0; i < n_caballeros; i++) {
        cin >> caballero;
        caballeros.push_back(caballero);
    }

    sort(cabezas.begin(), cabezas.end());
    sort(caballeros.begin(), caballeros.end());

    int cabez_idx = 0;
    int cabal_idx = 0;

    int coste_total = 0;

    while (cabez_idx < cabezas.size() && cabal_idx < caballeros.size()) {
        if (caballeros[cabal_idx] >= cabezas[cabez_idx]) {
            coste_total += caballeros[cabal_idx];
            cabez_idx++;
            cabal_idx++;
        }
        else {
            cabal_idx++;
        }
    }

    if (cabez_idx < cabezas.size()) {
        cout << "Loowater is doomed!\n";
    }
    else {
        cout << coste_total << "\n";
    }

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
/*#ifndef DOMJUDGE
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
#endif
*/
    return 0;
}