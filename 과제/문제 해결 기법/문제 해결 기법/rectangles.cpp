#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int x, y1, y2, type;
    bool operator<(const Event& other) const {
        return x < other.x;
    }
};

void removeDuplicates(vector<int>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

int getHeight(const vector<int>& yy, const vector<int>& cnt) {
    int height = 0;

    for (int i = 0; i < yy.size() - 1; ++i) {
        if (cnt[i] > 0) height += yy[i + 1] - yy[i];
    }

    return height;
}

long long calculateTotalArea(vector<Event>& events, vector<int>& yy) {
    long long totalArea = 0;
    vector<int> cnt(yy.size(), 0);

    removeDuplicates(yy);

    sort(events.begin(), events.end());

    for (int i = 0; i < events.size(); ++i) {
        if (i > 0) {
            totalArea += static_cast<long long>(getHeight(yy, cnt)) * (events[i].x - events[i - 1].x);
        }

        for (int j = 0; j < yy.size() - 1; ++j) {
            if (yy[j] >= events[i].y1 && yy[j + 1] <= events[i].y2) cnt[j] += events[i].type;
        }
    }

    return totalArea;
}

int main() {
    ifstream fin("rectangles.inp");
    ofstream fout("rectangles.out");

    int n;
    fin >> n;

    vector<Event> events;
    vector<int> x, y;

    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;

        events.push_back({ x1, y1, y2, 1 });
        events.push_back({ x2, y1, y2, -1 });

        y.push_back(y1);
        y.push_back(y2);
    }

    long long totalArea = calculateTotalArea(events, y);

    fout << totalArea << "\n";

    fin.close();
    fout.close();

    return 0;
}