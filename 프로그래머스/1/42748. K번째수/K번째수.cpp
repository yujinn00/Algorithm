#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (const auto& command : commands)
    {
        int i = command[0];
        int j = command[1];
        int k = command[2];
        
        vector<int> tmpArray(array.begin() + i - 1, array.begin() + j);
        sort(tmpArray.begin(), tmpArray.end());
        answer.push_back(tmpArray[k - 1]);
    }
    
    return answer;
}