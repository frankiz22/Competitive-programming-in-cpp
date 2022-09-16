#include <iostream>
#include<vector>

using namespace std;

int main() {
	int N, K;
	cin >> N;
	cin >> K;
	vector<int> H = vector<int>(N);
	vector<vector<int>> C = vector<vector<int>>(N, vector<int>(K+1, 0));
	vector<vector<int>>decue = vector<vector<int>>(N, vector<int>(N,0));
	for (int i = 0; i < N; i++)
		cin >> H[i];
	for (int k = 1; k < K + 1; k++) {
		C[k - 1][k] = 0;
	}

	{
		vector<vector<int>> M = vector<vector<int>>(N, vector<int>(N, 0));


		for (int i = 0; i < N; i++) {
			M[i][0] = (H[0] > H[i]) ? 1 : 0;
			for (int j = 1; j < i; j++) {
				M[i][j] = (H[j] > H[i]) ? M[i][j - 1] + 1 : M[i][j-1];
			}
		}

		for (int j = 1; j < N; j++) {
			decue[0][j] = decue[0][j - 1] + M[j][j - 1];
		}
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				decue[i][j] = decue[i][j - 1] + M[j][j - 1] - M[j][i - 1];
			}
		}
	}


	for (int n = 1; n < N; n++) {

		C[n][1] = decue[0][n];
	}

	int m;
	for (int k = 2; k < K + 1; k++) {
		for (int n = k; n < N; n++) {
			m = C[k-2][k - 1] + decue[k-1][n];
			for (int j = k - 2; j < n; j++) {
				m = min(m, C[j][k - 1] + decue[j + 1][n]);
			}
			C[n][k] = m;
		}
	}

	cout << C[N - 1][K];

	
}