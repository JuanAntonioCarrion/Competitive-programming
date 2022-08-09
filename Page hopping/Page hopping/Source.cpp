#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;

double bfs(int s, const vector<vector<int>> &lista_ady) {
    vector<double> dist(lista_ady.size(), 0);
    vector<bool> visited(lista_ady.size(), 0);
    queue<int> q;
    dist[s] = 0; visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int w : lista_ady[v]) {
            if (!visited[w]) {
                dist[w] = dist[v] + 1;
                visited[w] = true;
                q.push(w);
            }
        }
    }

    double total = 0;

    for (int i = 0; i < dist.size(); i++) {
        total += dist[i];
    }

    total /= dist.size()-1;
    return total;

}

bool resuelveCaso(int caso) {
    // leer los datos de la entrada
    vector<vector<int>> lista_ady;
    unordered_map<int, int> posicion_lista;
    int a, b;
    bool finalizado = false;
    while (!finalizado) {
        cin >> a >> b;
        if (a == 0 && b == 0) {
            finalizado = true;
        }
        else {
            if (posicion_lista.find(a) == posicion_lista.end()) {
                posicion_lista.insert({ a, lista_ady.size() });
                lista_ady.push_back(std::vector<int>());
            }
            if (posicion_lista.find(b) == posicion_lista.end()) {
                posicion_lista.insert({ b, lista_ady.size() });
                lista_ady.push_back(std::vector<int>());
            }

            lista_ady[posicion_lista[a]].push_back(posicion_lista[b]);
        }
    }

    if (lista_ady.size() == 0) return false;

    double sol = 0;
    for (int i = 0; i < lista_ady.size(); i++) {
        sol += bfs(i, lista_ady);
    }
    sol /= lista_ady.size();

    cin.ignore();

    cout << "Case " << caso << ": average length between pages = " << fixed << setprecision(3) << sol << " clicks\n";

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
    int caso = 1;
    while (resuelveCaso(caso)) {
        caso++;
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