#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class time_slot{

public:
	int debut;
	int fin;

	time_slot() {
		debut = 0;
		fin = 0;
	}
	time_slot(int _debut, int _fin) {
		debut = _debut;
		fin = _fin;
	}

	static bool comparetimeslot(time_slot& a, time_slot& b) {
		return (a.fin < b.fin) /* || ((a.fin = b.fin) && (a.debut < b.debut))*/;
	}
};

int main() {
	int N, T, r;
	cin >> T;
	time_slot tmp;
	vector<time_slot> planning;
	for (int j = 0; j < T; j++) {
		planning.clear();
		cin >> N;
		planning = vector<time_slot>(N);
		for (int i = 0; i < N; i++) {
			cin >> planning[i].debut; cin >> planning[i].fin;
		}

		sort(planning.begin(), planning.end(), time_slot::comparetimeslot);

		if (N >= 1)
			r = 1;
		else
			r = 0;
		tmp = planning[0];
		for (int i = 1; i < N; i++) {
			if (planning[i].debut >= tmp.fin) {
				r++;
				tmp = planning[i];
			}
		}

		cout << r << '\n';
	}


	


	
	
}