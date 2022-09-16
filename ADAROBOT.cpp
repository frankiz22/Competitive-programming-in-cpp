#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main() {
	int Q, N;
	cin >> Q;
	vector<int> valeur = vector<int>(32);
	vector<int> power = vector<int>(32);
	valeur[0] = 8;
	power[0] = 1;
	int n, p, m, v;
	for (int i = 1; i < 32; i++) {
		valeur[i] = 2 * valeur[i - 1] + 3 * i * i + 9 * i + 7;
		power[i] = 2 * power[i - 1];
	}
	for (int i = 0; i < Q; i++) {

		cin >> N;
		v = 0;
		p = N / 2;
		while(p > 0){
			n = int(log2(p));
			p -= power[n];
			v += valeur[n]; 
		}
		cout << v << '\n';
	}
}