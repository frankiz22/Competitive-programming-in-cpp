#include <iostream>
#include <vector>

using namespace std;
int main() {
	int t, n, m, w, j, a;
	cin >> t;
	vector<int> somme;
	vector<int> S;
	for (int p = 0; p < t; p++) {
		somme.clear();
		S.clear();
		cin >> n;
		somme = vector<int>(n);
		S = vector<int>(n);
		cin >> somme[0];
		for (int k = 1; k < n; k++){
			cin >> somme[k];
			somme[k] += somme[k - 1];
		}

		S[0] = (somme[0] - 2000) * (somme[0] - 2000);
		for (int i = 1; i < n; i++) {
			j = i - 1;
			w = somme[i] - somme[j];
			m = S[j] + (w - 2000) * (w - 2000);

			while (j >= 0 && w <= 4000) {
				w = somme[i] - somme[j];
				m = min(m , S[j] + (w - 2000) * (w - 2000));
				j--;
			}

			if (j < 0) {
				m = min(m, (somme[i] - 2000) * (somme[i] - 2000));
			}

			S[i] = m;
		}
		cout << S[n - 1] << '\n';
	}
}