#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if (s.length() == 4 || s.length() == 6)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (!isdigit(s[i]))
            {
                answer = false;
                break;
            }
        }
    }
    else
    {
        return false;
    }
    
    return answer;
}