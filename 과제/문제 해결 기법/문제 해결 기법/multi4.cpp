#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {
	ifstream fin("multi4.inp");
	ofstream fout("multi4.out");

	int T;
	fin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		fin >> n;


		vector<int> arr(n);

		for (int j = 0; j < n; j++) {
			fin >> arr[j];
		}

		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());


		long long result1 = arr[0] * arr[1] * arr[2] * arr[3];
		long long result2 = arr[0] * arr[arr.size() - 1] * arr[arr.size() - 2] * arr[arr.size() - 3];

		fout << min(result1, result2) << " " << max(result1, result2) << "\n";
	}

	fin.close();
	fout.close();

	return 0;
}