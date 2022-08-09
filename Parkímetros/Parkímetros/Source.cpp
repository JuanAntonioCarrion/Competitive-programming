#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void lee_datos(int& dif_monedas, int& max_monedas) {
	cin >> dif_monedas >> max_monedas;
}

void recursiveCase(unordered_set<int>& collection, const vector<int> &monedas, int index, bool use_next, int total_result, int monedas_restantes, int max_monedas) {
	if (monedas_restantes == 0 || index == max_monedas) {
		if (collection.find(total_result) == collection.end()) {
			collection.insert(total_result);
		}
	}
	else {
		if (use_next) {
			monedas_restantes -= 1;
			total_result += monedas[index];
			recursiveCase(collection, monedas, index, true, total_result, monedas_restantes, max_monedas);
			recursiveCase(collection, monedas, index + 1, true, total_result, monedas_restantes, max_monedas);
			recursiveCase(collection, monedas, index + 1, false, total_result, monedas_restantes, max_monedas);
		}
		else {
			recursiveCase(collection, monedas, index, true, total_result, monedas_restantes, max_monedas);
			recursiveCase(collection, monedas, index + 1, true, total_result, monedas_restantes, max_monedas);
			recursiveCase(collection, monedas, index + 1, false, total_result, monedas_restantes, max_monedas);
		}
	}
}

int main() {
	int ncasos;
	cin >> ncasos;
	for (int i = 0; i < ncasos; i++) {
		int dif_monedas = 0, max_monedas = 0;
		lee_datos(dif_monedas, max_monedas);
		vector<int> monedas;
		for (int j = 0; j < dif_monedas; j++) {
			int moneda;
			cin >> moneda;
			monedas.push_back(moneda);
		}
		
		unordered_set<int> collection;
		int index = 0;
		int total_result = 0;

		recursiveCase(collection, monedas, index, true, total_result, max_monedas, dif_monedas);
		recursiveCase(collection, monedas, index, false, total_result, max_monedas, dif_monedas);

		cout << collection.size()-1 <<"\n";


	}

	return 0;
}