#include <iostream>
#include <vector>

using namespace std;

bool solve() {

	if (!cin) {
		return false;
	}

	int n_capas;

	cin >> n_capas;

	int lim_capas = n_capas - 1;

	vector<unsigned long long int> cumulo((n_capas+1)/2, 0);

	for (int i = 0; i < n_capas; i++) {
		for (int j = 0; j < n_capas; j++) {
			unsigned long long int humedad;
			cin >> humedad;

			cumulo[min(min(i, lim_capas - i), min(j, lim_capas - j))] += humedad;
		}
	}

	for (int i = cumulo.size() - 1; i > 0; i--) {
		cout << cumulo[i] << " ";
	}
	if (n_capas != -1) {
		cout << cumulo[0] << "\n";

	}

	return true;
}


int main() {

	while (solve());


	return 0;
}