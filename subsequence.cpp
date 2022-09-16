#include<iostream>
#include <vector>
#include <string>

using namespace std;
int main() {

	int n, m;
	string mot1, mot2;
	vector<int> letter = vector<int>(26);	
	cin >> n, cin >> m;
	vector<vector<int64_t>> value = vector<vector<int64_t>>(n, vector<int64_t>(m, 0));

	for (int i = 0; i < 26; i++)
		cin >> letter[i];
	cin >> mot1;
	cin >> mot2;
	for (int i = 0; i < n; i++) {
		if (mot1.substr(0, i + 1).find(mot2[0]) != string::npos)
			value[i][0] = letter[(int)(mot2[0]) - (int)('a')];
	}

	for (int j = 0; j < m; j++) {
		if (mot2.substr(0, j + 1).find(mot1[0]) != string::npos)
			value[0][j] = letter[(int)(mot1[0]) - (int)('a')];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (mot1[i] == mot2[j]) {
				value[i][j] = value[i - 1][j - 1] + letter[(int)(mot1[i]) - (int)('a')];
			}
			else {
				value[i][j] = max(value[i][j - 1], value[i - 1][j]);
			}
		}
	}

	cout << value[n - 1][m - 1];


	
	return 0;
}