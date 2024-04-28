#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

bool isPalindrome(int n) {
	int original = n;
	int rev = 0;

	while (n > 0) {
		rev = rev * 10 + n % 10;
		n /= 10;
	}

	return original == rev;
}

int rev(int n) {
	string s = to_string(n);
	reverse(s.begin(), s.end());
	return atoi(s.c_str());
}

int main() {
	ifstream fin("palindrome.inp");
	ofstream fout("palindrome.out");

	int T;
	fin >> T;

	for (int i = 0; i < T; i++) {
		int n;
		fin >> n;

		int count = 1;

		if (isPalindrome(n) == 1) {
			fout << 0 << "\n";
		}
		else {
			while (true) {
				n = abs(n - rev(n));

				if (isPalindrome(n) == 0) {
					count++;
				}
				else {
					fout << count << "\n";
					break;
				}

				if (count >= 1000) {
					fout << -1 << "\n";
					break;
				}
			}
		}
	}

	fin.close();
	fout.close();

	return 0;
}