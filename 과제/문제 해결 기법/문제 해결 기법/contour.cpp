#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Event {
    int x, height, type; // type: 1 for start, -1 for end
    bool operator<(const Event& other) const {
        return x < other.x || (x == other.x && type > other.type);
    }
};

int main() {
    ifstream infile("contour.inp");
    ofstream outfile("contour.out");
    vector<Event> events;
    int caseNumber = 0;

    while (true) {
        int L, H, R;
        events.clear();

        while (infile >> L >> H >> R) {
            if (L == 0 && H == 0 && R == 0) break;
            events.push_back({L, H, 1});
            events.push_back({R, H, -1});
        }

        if (events.empty()) break; // No more input

        sort(events.begin(), events.end());

        map<int, int> activeHeights;
        int prevX = 0;
        long long totalArea = 0;
        vector<long long> areas;
        for (const auto& e : events) {
            if (!activeHeights.empty()) {
                int currentWidth = e.x - prevX;
                totalArea += (long long)activeHeights.rbegin()->first * currentWidth;
                if (e.type == -1 || (e.type == 1 && activeHeights.rbegin()->first < e.height)) {
                    areas.push_back(totalArea);
                    totalArea = 0;
                }
            }
            if (e.type == 1) {
                activeHeights[e.height]++;
            } else {
                if (--activeHeights[e.height] == 0) {
                    activeHeights.erase(e.height);
                }
            }
            prevX = e.x;
        }

        outfile << "Test Case #" << ++caseNumber << " :";
        for (auto area : areas) {
            outfile << " " << area;
        }
        outfile << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}