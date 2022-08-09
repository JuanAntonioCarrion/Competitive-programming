#include <iostream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;


void resuelveCaso(bool final) {
    // leer los datos de la entrada

    int millas;
    cin >> millas;
    millas /= 100;

    std::vector<std::vector<int>> matrix_air_map(10, std::vector<int>());

    for (int i = 9; i >= 0; i--) {
        std::vector<int> line(millas, 0);
        matrix_air_map[i] = line;
        for (int j = 0; j < millas; j++) {
            cin >> matrix_air_map[i][j];
        }
    }


    

    // escribir sol

    std::vector<int> solution_column(10, -1);
    std::vector<int> prev_vector(10, -1);
    prev_vector[0] = 0;

    for (int j = 1; j <= millas; j++) {
        for (int i = 0; i < 10; i++) {
            int dist_arriba = -1;
            int dist_plana = -1;
            int dist_abajo = -1;
            
            if (i > 0 && prev_vector[i - 1] != -1) {
                dist_abajo = prev_vector[i - 1] - matrix_air_map[i-1][j-1] + 60;
            }
            if (i < 9 && prev_vector[i + 1] != -1) {
                dist_arriba = prev_vector[i + 1] - matrix_air_map[i + 1][j - 1] + 20;
            }
            if (prev_vector[i] != -1) {
                dist_plana = prev_vector[i] - matrix_air_map[i][j - 1] + 30;
            }
            
            
            int solucion = -1;
            if (dist_plana != -1) {
                solucion = dist_plana;
            }
            if (dist_arriba != -1 && (dist_arriba < solucion || solucion == -1)) {
                solucion = dist_arriba;
            }
            if (dist_abajo != -1 && (dist_abajo < solucion || solucion == -1)) {
                solucion = dist_abajo;
            }

            solution_column[i] = solucion;
        }

        


        prev_vector = solution_column;
    }
        cout << prev_vector[0] << "\n\n";


    
    


}

int main() {


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos-1; ++i) {
        resuelveCaso(false);
    }
    resuelveCaso(true);
        

    return 0;
}