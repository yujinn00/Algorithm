#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

void convert(int left, int right, int& cur, int inorder[], vector<char>& result) {
    if (left >= right) return;

    int root = left;

    while (root < right && inorder[root] != cur) {
        root++;
    }

    cur++;
    result.push_back('(');
    convert(left, root, cur, inorder, result);
    result.push_back(')');
    convert(root + 1, right, cur, inorder, result);
}

int main() {
    ifstream fin("transform.inp");
    ofstream fout("transform.out");

    int T;
    fin >> T;

    while (T--) {
        int n, k;
        fin >> n >> k;

        fout << n << " ";

        if (k == 1) {
            char* bracket = new char[40001];
            fin >> bracket;

            stack<int> stk;

            for (int i = 0, node = 1; i < 2 * n; ++i) {
                if (bracket[i] == '(') stk.push(node++);
                else {
                    fout << stk.top() << ' ';
                    stk.pop();
                }
            }

            delete[] bracket;
        } else {
            int* inorder = new int[20001];

            for (int i = 0; i < n; ++i) {
                fin >> inorder[i];
            }

            int cur = 1;
            vector<char> result;
            convert(0, n, cur, inorder, result);

            for (char c : result) {
                fout << c;
            }

            delete[] inorder;
        }

        fout << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}