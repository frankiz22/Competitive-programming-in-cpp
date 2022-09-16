#include <iostream>
#include <vector>

using namespace std;


int find(vector<int>& pere, int i) {
	int j = i, k =i;
	if (pere[i] == -1) {
		return -1;
	}
	else {
		while (pere[j] != j) {
			j = pere[j];
		}
		while (pere[i] != i) {
			k = i;
			i = pere[i];
			pere[k] = j;
		}
	}

	return j;
}
void unir(vector<int>& pere, vector<int>& taille, int i, int j) {
	int perei = find(pere, i), perej = find(pere, j);
	if (perei != perej) {
		if (taille[perei] > taille[perej])
			pere[perej] = perei;
		else if (taille[perei] < taille[perej])
			pere[perei] = perej;
		else {
			if (perei < perej) {
				pere[perej] = perei;
				taille[perei] += 1;
			}
			else {
				pere[perei] = perej;
				taille[perej] += 1;
			}
			
		}
			

	}

}
void marquer(vector<int>& pere, vector<int>& board , vector<int>& taille, int i) {

	int r = i / 10;
	int c = i % 10;
	

	if ((r - 2 >= 0) && (c - 1 >= 0) && board[10 * (r - 2) + c - 1] == 0) {
		unir(pere, taille, i, 10 * (r - 2) + c - 1);
	}
	if ((r - 2 >= 0) && (c + 1 <= 9) && board[10 * (r - 2) + c + 1] == 0) {
		unir(pere, taille, i, 10 * (r - 2) + c + 1);
	}
	if ((r - 1 >= 0) && (c - 2 >= 0) && board[10 * (r - 1) + c - 2] == 0) {
		unir(pere, taille, i, 10 * (r - 1) + c - 2);
	}
	if ((r - 1 >= 0) && (c + 2 <= 9) && board[10 * (r - 1) + c + 2] == 0) {
		unir(pere, taille, i, 10 * (r - 1) + c + 2);
	}
	

	if ((r + 1 <= 9) && (c - 2 >= 0)  && board[10 * (r + 1) + c - 2] == 0) {
		unir(pere, taille, i, 10 * (r + 1) + c - 2);
	}
	if ((r + 2 <= 9) && (c - 1 >= 0) && board[10 * (r + 2) + c - 1] == 0) {
		unir(pere, taille, i, 10 * (r + 2) + c - 1);
	}
	if ((r + 1 <= 9) && (c + 2 <= 9) && board[10 * (r + 1) + c + 2] == 0) {
		unir(pere, taille, i, 10 * (r + 1) + c + 2);
	}
	if ((r + 2 <= 9) && (c + 1 >= 0) && board[10 * (r + 2) + c + 1] == 0) {
		unir(pere, taille, i, 10 * (r + 2) + c + 1);
	}
}

void afficherboard(vector<int>& board) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[10 * i + j] == -1)
				cout << " -1 ";
			else
				cout << "  0 ";
		}
		cout << '\n';
	}

	cout << '\n';
}

void afficher(vector<int>& pere, vector<int>& board, int upper) {
	 
}


int main() {
	vector<int> board = vector<int>(100, -1);
	vector<int> pere = vector<int>(100, -1);
	vector<int> taille = vector<int>(100, 1);
	int n, row, l, v, r, upper;
	cin >> n;
	cin >> row; cin >> l;
	for (int j = 0; j < l; j++) {
		board[row + j] = 0;
	}
	upper = row;
	for (int i = 1; i < n; i++) {
		cin >> row; cin >> l;
		for (int j = 0; j < l; j++) {
			board[10 * i + row + j] = 0;
		}
	}

	for (int i = 0; i < 100; i++) {
		if (board[i] == 0) {
			pere[i] = i;
		}
	}
	afficherboard(board);
	for (int i = 0; i < 100; i++) {
		if (board[i] == 0) {
			cout << i << '\n';
			marquer(pere, board, taille, i);
			afficher(pere, board, upper);
		}
	}

	v = pere[find(pere, upper)];
	r = 0;
	for (int i = 0; i < 100; i++) {
		if (board[i] == 0 && pere[find(pere, i)] != v) {
			r++;
		}
	}

	afficherboard(board);
	
	cout << "\n\n\n" << upper << "\n\n\n";

	afficher(pere, board, upper);

	cout << "\n\n\n" << r << "\n";


	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[10 * i + j] == -1)
				cout << " -1 ";
			else
				cout << "  0 ";
		}
		cout << '\n';
	}

}