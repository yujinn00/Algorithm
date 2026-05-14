#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> map;
    
    for (int num : nums)
    {
        map[num]++;
    }
    
    int a = map.size();
    int b = nums.size() / 2;
    
    return min(a, b);
}