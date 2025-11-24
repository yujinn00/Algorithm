#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> player;
    
    for (const string& name : participant)
    {
        player[name]++;
    }
    
    for (const string& name : completion)
    {
        player[name]--;
    }
    
    for (const auto& pair : player)
    {
        if (pair.second > 0)
        {
            answer = pair.first;
            break;
        }
    }
    
    return answer;
}