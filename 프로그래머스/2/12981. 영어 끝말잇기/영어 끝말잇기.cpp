#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    
    set<string> usedWords;
    
    char lastChar = ' ';
    
    for (int i = 0; i < words.size(); ++i)
    {
        string curWord = words[i];
        
        if (i > 0 && lastChar != curWord[0])
        {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            return answer;
        }
        else if (usedWords.find(curWord) != usedWords.end())
        {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            return answer;
        }
        else
        {
            usedWords.insert(curWord);
            lastChar = curWord[curWord.length() - 1];
        }
    }
    
    return answer;
}