#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    ifstream fin("trip.inp");
    ofstream fout("trip.out");

    int n;

    while (fin >> n && n != 0) {
        vector<double> expenses(n);
        double sum = 0.0;

        for (int i = 0; i < n; i++) {
            fin >> expenses[i];
            sum += expenses[i];
        }

        double average = sum / n;
        double diffMore = 0.0, diffLess = 0.0;

        for (int i = 0; i < n; i++) {
            double diff = static_cast<long>((expenses[i] - average) * 100.0) / 100.0;

            if (diff > 0) {
                diffMore += diff;
            } else {
                diffLess += -diff;
            }
        }

        double minExchange = max(diffMore, diffLess);

        fout << fixed << setprecision(2) << "$" << minExchange << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}