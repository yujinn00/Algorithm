#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

int arr[4][2];
float a, b;

void linear(int n1, int n2) {
	a = (float)(arr[n1][1] - arr[n2][1]) / (float)(arr[n1][0] - arr[n2][0]);
	b = (float)arr[n1][1] - a * (float)arr[n1][0];
}

int check(int n1, int n2) {
	float tmp1, tmp2;

	tmp1 = a * (float)arr[n1][0] + b;
	tmp2 = a * (float)arr[n2][0] + b;

	if (tmp1 > (float)arr[n1][1] && tmp2 < (float)arr[n2][1]) return 1;
	else if (tmp1 < (float)arr[n1][1] && tmp2 >(float)arr[n2][1]) return 1;

	return 0;
}

int main() {
	ifstream fin("point.inp");
	ofstream fout("point.out");

	int T;
	fin >> T;

	for (int i = 0; i < T; i++) {
		fin >> arr[0][0] >> arr[0][1];
		fin >> arr[1][0] >> arr[1][1];
		fin >> arr[2][0] >> arr[2][1];
		fin >> arr[3][0] >> arr[3][1];

		linear(0, 1);
		if (check(2, 3) == 1) {
			linear(2, 3);
			if (check(0, 1) == 1) {
				fout << 3 << "\n";
				continue;
			}
		}

		linear(0, 2);
		if (check(1, 3) == 1) {
			linear(1, 3);
			if (check(0, 2) == 1) {
				fout << 3 << "\n";
				continue;
			}
		}

		linear(0, 3);
		if (check(1, 2) == 1) {
			linear(1, 2);
			if (check(0, 3) == 1) {
				fout << 3 << "\n";
				continue;
			}
		}

		fout << 2 << "\n";
	}
	
	fin.close();
	fout.close();

	return 0;
}