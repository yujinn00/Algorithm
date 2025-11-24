#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int maxW = 0, maxH = 0;
    
    for (const auto& size : sizes)
    {
        int curMax = max(size[0], size[1]);
        int curMin = min(size[0], size[1]);
        
        maxW = max(maxW, curMax);
        maxH = max(maxH, curMin);
    }
    
    answer = maxW * maxH;
    
    return answer;
}