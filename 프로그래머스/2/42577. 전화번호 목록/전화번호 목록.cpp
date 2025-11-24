#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        string curNum = phone_book[i];
        string nextNum = phone_book[i + 1];
        
        if (nextNum.length() >= curNum.length())
        {
            if (nextNum.substr(0, curNum.length()) == curNum)
            {
                return false; 
            }
        }
    }
    
    return answer;
}