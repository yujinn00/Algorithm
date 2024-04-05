#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void findCycle(vector<int>& permutation, vector<bool>& visited, int& cycles) {
    for (int i = 0; i < permutation.size(); i++) {
        if (!visited[i]) {
            int cur = i;

            while (!visited[cur]) {
                visited[cur] = true;
                cur = permutation[cur] - 1;
            }

            cycles++;
        }
    }
}

int main() {
    ifstream fin("cycle.inp");
    ofstream fout("cycle.out");

    int T;
    fin >> T;

    while (T--) {
        int n;
        fin >> n;

        vector<int> permutation(n);
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            fin >> permutation[i];
        }

        int cycle = 0;
        findCycle(permutation, visited, cycle);

        fout << cycle << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}