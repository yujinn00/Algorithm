#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findMaxPathSum(int start, int end, const vector<int>& cost, const vector<int>& preorder, int& index, int& sum) {
    if (start == end) {
        sum = max(sum, cost[start]);
        index++;
        return cost[start];
    }

    if (start > end || index == cost.size()) return 0;

    int i = start;

    while (i <= end && preorder[index] != i) ++i;
    index++;

    int left = INT_MIN, right = INT_MIN;

    if (i == end) {
        left = findMaxPathSum(start, i - 1, cost, preorder, index, sum);
        return left + cost[i];
    } else if (i == start) {
        right = findMaxPathSum(i + 1, end, cost, preorder, index, sum);
        return right + cost[i];
    } else {
        left = findMaxPathSum(start, i - 1, cost, preorder, index, sum);
        right = findMaxPathSum(i + 1, end, cost, preorder, index, sum);
        sum = max(sum, left + right + cost[i]);
        return max(left + cost[i], right + cost[i]);
    }
}

int main() {
    ifstream fin("path.inp");
    ofstream fout("path.out");

    int T;
    fin >> T;

    while (T--) {
        int n;
        fin >> n;

        vector<int> preorder(n);
        vector<int> node(n);

        for (int i = 0; i < n; ++i) fin >> node[i];
        for (int i = 0; i < n; ++i) fin >> preorder[i];

        int sum = INT_MIN;
        int index = 0;

        findMaxPathSum(0, n - 1, node, preorder, index, sum);
        fout << sum << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}