#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<string, string> parentMap;
unordered_map<string, int> depthMap;
unordered_set<string> allName;

void calcDepth(const string& name) {
    if (depthMap.find(name) != depthMap.end()) return;
    if (parentMap.find(name) == parentMap.end()) {
        depthMap[name] = 0;
        return;
    }

    calcDepth(parentMap[name]);
    depthMap[name] = depthMap[parentMap[name]] + 1;
}

string findLca(const string& a, const string& b) {
    unordered_set<string> ancestorsA;
    string cur = a;

    while (parentMap.find(cur) != parentMap.end()) {
        ancestorsA.insert(cur);
        cur = parentMap[cur];
    }

    ancestorsA.insert(cur);
    cur = b;

    while (ancestorsA.find(cur) == ancestorsA.end()) {
        if (parentMap.find(cur) == parentMap.end()) return "";
        cur = parentMap[cur];
    }

    return cur;
}

int main() {
    ifstream fin("tree.inp");
    ofstream fout("tree.out");

    string line, child, parent;

    while (getline(fin, line)) {
        if (line == "no.child no.parent") break;

        istringstream iss(line);
        iss >> child >> parent;

        parentMap[child] = parent;
        allName.insert(child);
        allName.insert(parent);
    }

    for (const auto& name : allName) {
        calcDepth(name);
    }

    while (getline(fin, line)) {
        istringstream iss(line);
        string p, q;
        iss >> p >> q;

        if (p == q) {
            fout << "sibling\n";
            continue;
        }

        if (parentMap[p] == q) {
            fout << "child\n";
            continue;
        }

        if (parentMap[q] == p) {
            fout << "parent\n";
            continue;
        }

        string lca = findLca(p, q);

        if (lca == "") {
            fout << "no relation\n";
            continue;
        }

        int depthP = depthMap[p] - depthMap[lca];
        int depthQ = depthMap[q] - depthMap[lca];

        if (depthP == 0 || depthQ == 0) {
            fout << "no relation\n";
            continue;
        }

        if (depthP == depthQ) {
            if (depthP == 1) fout << "sibling\n";
            else fout << depthP - 1 << " cousin\n";
        }
        else fout << min(depthP, depthQ) - 1 << " cousin removed " << abs(depthP - depthQ) << "\n";
    }

    fin.close();
    fout.close();

    return 0;
}