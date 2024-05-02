#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class RectangleEvent {
public:
    int position, height, eventType;
    RectangleEvent(int position, int height, int eventType) : position(position), height(height), eventType(eventType) {}

    bool operator<(const RectangleEvent& rhs) const {
        if (position != rhs.position) return position < rhs.position;
        else return eventType > rhs.eventType;
    }
};

int main() {
    ifstream fin("contour.inp");
    ofstream fout("contour.out");

    vector<RectangleEvent> event;
    int caseNumber = 0;

    while (true) {
        int L, H, R;
        event.clear();

        while (fin >> L >> H >> R) {
            if (L == 0 && H == 0 && R == 0) break;
            event.emplace_back(L, H, 1);
            event.emplace_back(R, H, -1);
        }

        if (event.empty()) break;

        fout << "Test Case #" << ++caseNumber << " :";

        sort(event.begin(), event.end());

        multimap<int, int> heightCount;
        vector<long long> recordArea;
        int prePosition = -1;
        long long maxHeight = 0, areaCover = 0;
        auto eventIter = event.begin();

        while (eventIter != event.end()) {
            const RectangleEvent& rectEvent = *eventIter;

            if (prePosition != -1 && rectEvent.position != prePosition) {
                long long width = rectEvent.position - prePosition;

                if (maxHeight > 0) areaCover += width * maxHeight;

                if (heightCount.empty() && areaCover > 0) {
                    recordArea.push_back(areaCover);
                    areaCover = 0;
                }
            }

            if (rectEvent.eventType == 1) heightCount.insert({ rectEvent.height, rectEvent.eventType });
            else {
                auto itr = heightCount.find(rectEvent.height);
                if (itr != heightCount.end()) heightCount.erase(itr);
            }

            if (!heightCount.empty()) maxHeight = heightCount.rbegin()->first;
            else {
                maxHeight = 0;
                if (areaCover > 0) {
                    recordArea.push_back(areaCover);
                    areaCover = 0;
                }
            }

            prePosition = rectEvent.position;
            ++eventIter;
        }

        if (areaCover > 0) recordArea.push_back(areaCover);

        for (const auto area : recordArea) {
            fout << " " << area;
        }

        fout << '\n';
    }

    fin.close();
    fout.close();

    return 0;
}