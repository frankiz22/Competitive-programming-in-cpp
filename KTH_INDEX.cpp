#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int N, Q, L, R, P, K, j;
	cin >> N; cin >> Q;
	int n;
	vector<vector<int>> position = vector<vector<int>>(1000000, vector<int>());

	
	for (int i = 0; i < N; i++) {
		cin >> n;
		position[n].push_back(i);
	}

	for (int i = 0; i < Q; i++) {
		cin >> L; cin >> R; cin >> P; cin >> K;
		if (position[P].size() == 0) {
			cout << -1 << '\n';
		}
		else {
			j = 0;
			while (j < position[P].size() && position[P][j] < L - 1)
				j++;
			if (j + K - 1 < position[P].size() && position[P][j + K - 1] <= R - 1) {
				cout << position[P][j + K - 1] + 1 << '\n';
			}
			else
				cout << -1 << '\n';
		}
	}
}