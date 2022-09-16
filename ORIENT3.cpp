#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;
int main() {
	int N;
	vector<int> power = vector<int>(12, 1);
	for (int i = 1; i < 12; i++) {
		power[i] = 2 * power[i - 1];
	}
	while (cin >> N) {
		vector<vector<int>> possible = vector<vector<int>>(N, vector<int>(N, 0));
		vector<vector<vector<int>>> move = vector<vector<vector<int>>>(N);
		string s;
		
		
		int n;
		vector<vector<int>> adjacence = vector<vector<int>>(N);
		{
			
			for (int i = 0; i < N; i++) {
				cin >> s;
				if (s.size() < 3) {
					std::cout << 0 << "\n";
					return 0;
				}
				for (int j = 0; j < s.length(); j++) {
					adjacence[i].push_back(int(s[j] - 'a'));
				}
			}

			bitset<12> b(0);
			for (int i = 0; i < N; i++) {
				b = 0;
				if (adjacence[i].size() < 3)
					continue;
				for (int j = 0; j < power[adjacence[i].size()]; j++) {
					b = j;
					vector<int> l;
					if (b.count() % 3 == 0) {
						for (int k = 0; k < adjacence[i].size(); k++) {
							if (j & (1 << k)) {
								l.push_back(adjacence[i][k]);
							}
						}

					}
					if (!l.empty())
						move[i].push_back(l);

				}
				if (move[i].empty()) {
					std::cout << 0 << "\n";
					return 0;
				}
			}
		}


		//bcdefghijkl acdefghijkl abdefghijkl abcefghijkl abcdfghijkl abcdeghijkl abcdefhijkl abcdefgijkl abcdefghjkl abcdefghikl abcdefghijl abcdefghijk

		vector<int> index = vector<int>(N, 0);
		int nb = 0;
		int noeud = 0;
		bool test = true;
		vector<bool> is_move;
		while (index[0] < move[0].size()) {
			// si
			if (noeud == N) {
				nb++;
				noeud--;
				for (int i : adjacence[noeud]) {
					possible[noeud][i] = 0;
				}

			}
			if (index[noeud] < move[noeud].size()) {
				test = true;
				is_move.clear();
				is_move = vector<bool>(N, false);
				for (int i : move[noeud][index[noeud]]) {
					is_move[i] = true;
				}
				for (int i : adjacence[noeud]) {
					if ((is_move[i] && (possible[noeud][i] == -1)) || (!(is_move[i]) &&(possible[noeud][i] == 1))) {
						test = false;
						break;
					}
				}
				if (test) {
					for (int i : adjacence[noeud]) {
						if (is_move[i]) {
							possible[noeud][i] = 1;
							possible[i][noeud] = -1;
						}
						else {
							possible[noeud][i] = -1;
							possible[i][noeud] = 1;
						}
						
					}
					index[noeud]++;
					noeud++;
				}
				else {
					index[noeud]++;
				}
			}
			else {
				index[noeud] = 0;
				noeud--;
				for (int i : adjacence[noeud]) {
					possible[noeud][i] = 0;
				}
			}


		}

		std::cout << nb << "\n";
	}

	

	return 0;
}
















/*vector<int> l1 = vector<int>(adjacence[noeud].size(), 0), l2 = vector<int>(adjacence[noeud].size(), 0);
if (adjacence[noeud].size() < 3)
	return;
for (int i = 0; i < power[adjacence[noeud].size()]; i++) {
	b = i;
	test = true;
	l1 = vector<int>(adjacence[noeud].size(), 0);
	l2 = vector<int>(adjacence[noeud].size(), 0);

	if (b.count() % 3 == 0 && b!=0) {
		for (int k = 0; k < adjacence[noeud].size(); k++) {
			if (((i & (1 << k)) && (possible[noeud][adjacence[noeud][k]] == -1) ) || ((!(i & (1 << k)) && (possible[noeud][adjacence[noeud][k]] == 1)))) {
				test = false;
				break;
			}
			l1[k] = possible[noeud][adjacence[noeud][k]];
			l2[k] = possible[adjacence[noeud][k]][noeud];

		}
		if (test) {
			for (int k = 0; k < adjacence[noeud].size(); k++) {
				if (i & (1 << k)) {
					possible[noeud][adjacence[noeud][k]] = 1;
					possible[adjacence[noeud][k]][noeud] = -1;
				}
				else {
					possible[noeud][adjacence[noeud][k]] = -1;
					possible[adjacence[noeud][k]][noeud] = 1;
				}
			}
			backtracking(nbNoeud, adjacence, possible, power, nombre, noeud + 1);

			for (int k = 0; k < adjacence[noeud].size(); k++) {
				possible[noeud][adjacence[noeud][k]] = l1[k];
				possible[adjacence[noeud][k]][noeud] = l2[k];
			}

		}

	}

}*/