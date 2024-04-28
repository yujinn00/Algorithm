#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {
	ifstream fin("triangle.inp");
	ofstream fout("triangle.out");

	int T;
	fin >> T;

	for (int i = 0; i < T; i++) {
		int x1, y1, x2, y2, x3, y3;
		double a, b, c, temp;
		double k[3];

		fin >> x1 >> y1;
		fin >> x2 >> y2;
		fin >> x3 >> y3;

		a = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
		b = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
		c = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);

		k[0] = a;
		k[1] = b;
		k[2] = c;

		if ((y2 - y1) * (x3 - x2) == (x2 - x1) * (y3 - y2) && (y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1) && (y3 - y2) * (x3 - x1) == (x3 - x2) * (y3 - y1)) {
			fout << -1 << "\n";
		} else if (a == b && b == c && c == a) {
			fout << -1 << "\n";
		} else if (a == b) {
			if (a + b < c) fout << 2 << "\n";
			else if (a + b == c) fout << 1 << "\n";
			else if (a + b > c) fout << 0 << "\n";
		} else if (a == c) {
			if (a + c < b) fout << 2 << "\n";
			else if (a + c == b) fout << 1 << "\n";
			else if (a + c > b) fout << 0 << "\n";
		} else if (c == b) {
			if (c + b < a) fout << 2 << "\n";
			else if (c + b == a) fout << 1 << "\n";
			else if (c + b > a) fout << 0 << "\n";
		} else if (a != b && b != a && c != a) {
			int i, j;

			for (i = 0; i < 3; i++) {
				for (j = i + 1; j < 3; j++) {
					if (k[i] > k[j]) {
						temp = k[i];
						k[i] = k[j];
						k[j] = temp;
					}
				}
			}

			if (k[0] + k[1] < k[2]) fout << 2 << "\n";
			else if (k[0] + k[1] == k[2]) fout << 1 << "\n";
			else if (k[0] + k[1] > k[2]) fout << 0 << "\n";
		}
	}

	fin.close();
	fout.close();

	return 0;
}