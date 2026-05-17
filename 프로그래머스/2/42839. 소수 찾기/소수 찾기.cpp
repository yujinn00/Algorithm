#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int solution(string numbers) {   
    set<int> uniqueNumbers;
    
    sort(numbers.begin(), numbers.end());
    
    do
    {
        for (int i = 1; i <= numbers.size(); ++i)
        {
            string temp = numbers.substr(0, i);
            
            uniqueNumbers.insert(stoi(temp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    int answer = 0;
    
    for (int num : uniqueNumbers)
    {
        if (isPrime(num))
        {
            answer++;
        }
    }
    
    return answer;
}