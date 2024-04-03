#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
    if (start == end) return tree[node] = start;
    else {
        int mid = (start + end) / 2;
        int leftindex = init(a, tree, node * 2, start, mid);
        int rightindex = init(a, tree, node * 2 + 1, mid + 1, end);

        return tree[node] = (a[leftindex] <= a[rightindex]) ? leftindex : rightindex;
    }
}

int query(vector<int>& a, vector<int>& tree, int node, int start, int end, int i, int j) {
    if (i > end || j < start) return -1;
    if (i <= start && end <= j) return tree[node];

    int mid = (start + end) / 2;
    int leftindex = query(a, tree, node * 2, start, mid, i, j);
    int rightindex = query(a, tree, node * 2 + 1, mid + 1, end, i, j);

    if (leftindex == -1) return rightindex;
    if (rightindex == -1) return leftindex;

    return a[leftindex] <= a[rightindex] ? leftindex : rightindex;
}

void update(vector<int>& a, vector<int>& tree, int node, int start, int end, int index, int value) {
    if (index < start || index > end) return;

    if (start == end) {
        a[index] = value;
    } else {
        int mid = (start + end) / 2;
        
        update(a, tree, node * 2, start, mid, index, value);
        update(a, tree, node * 2 + 1, mid + 1, end, index, value);

        tree[node] = (a[tree[node * 2]] <= a[tree[node * 2 + 1]]) ? tree[node * 2] : tree[node * 2 + 1];
    }
}

int main() {
    ifstream fin("rmq.inp");
    ofstream fout("rmq.out");

    int n;
    fin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }

    int height = (int)ceil(log2(n));
    int treesize = (1 << (height + 1));

    vector<int> tree(treesize);
    init(a, tree, 1, 0, n - 1);

    long long sum = 0;

    while (true) {
        char op;
        fin >> op;

        if (op == 's') break;
        if (op == 'q') {
            int l, r;
            fin >> l >> r;
            sum += query(a, tree, 1, 0, n - 1, l, r);
        } else if (op == 'c') {
            int id, v;
            fin >> id >> v;
            update(a, tree, 1, 0, n - 1, id, v);
        }
    }

    fout << sum % 100000 << "\n";

    fin.close();
    fout.close();

    return 0;
}