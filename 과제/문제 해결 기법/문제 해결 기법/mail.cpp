#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char decode(string code) {
    if (code == "000000") return 'A';
    if (code == "001111") return 'B';
    if (code == "010011") return 'C';
    if (code == "011100") return 'D';
    if (code == "100110") return 'E';
    if (code == "101001") return 'F';
    if (code == "110101") return 'G';
    if (code == "111010") return 'H';

    string chars = "ABCDEFGH";
    string codes[8] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };

    for (int i = 0; i < 8; ++i) {
        int diff = 0;

        for (int j = 0; j < 6; ++j) {
            if (code[j] != codes[i][j]) diff++;
        }

        if (diff == 1) return chars[i];
    }

    return 'X';
}

int main() {
    ifstream fin("mail.inp");
    ofstream fout("mail.out");

    int T;
    fin >> T;

    while (T--) {
        int N;
        fin >> N;

        string message, result = "";
        fin >> message;

        for (int i = 0; i < N; ++i) {
            string code = message.substr(i * 6, 6);
            result += decode(code);
        }

        fout << result << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}