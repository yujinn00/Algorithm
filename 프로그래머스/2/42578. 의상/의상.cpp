#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> fashion;
    
    for (const auto& c : clothes)
    {
        fashion[c[1]]++;
    }
    
    for (const auto& f : fashion)
    {
        answer *= f.second + 1;
    }
    
    return answer - 1;
}