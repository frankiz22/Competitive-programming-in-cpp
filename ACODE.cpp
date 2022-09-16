#include <iostream>;
#include <string>;

using namespace std;
int main() {
	string code;
	cin >> code;

	int64_t u, v, w;

	while (code.compare("0") != 0) {
		u = 1;
		v = 1;

		for (int i = 1; i < code.length(); i++) {
			if (code.at(i) == '0') {
				w = u;
			}
			else {
				if (code.at(i - 1) == '1') {
					w = u + v;
				}
				else if (code.at(i - 1) == '2') {
					if (code.at(i) <= '6') {
						w = u + v;
					}
					else {
						w = v;
					}
				}
				else {
					w = v;
				}
			}
			

			u = v;
			v = w;


		}
		cout << v << '\n';
		cin >> code;

		
	}

}