#include <string>
#include <vector>

using namespace std;

vector<int> numbersArray;
int targetNumber;
int answer;

void dfs(int curIndex, int curSum)
{
    if (curIndex == numbersArray.size())
    {
        if (curSum == targetNumber)
        {
            answer++;
        }
        
        return;
    }
    
    int curNum = numbersArray[curIndex];
    
    dfs(curIndex + 1, curSum + curNum);
    dfs(curIndex + 1, curSum - curNum);

}

int solution(vector<int> numbers, int target) {
    numbersArray = numbers;
    targetNumber = target;
    answer = 0;
    
    dfs(0, 0);
    
    return answer;
}