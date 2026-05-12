using System;
using System.Linq;

public class Solution {
    public string solution(string s) {
        var sortedChars = s.OrderByDescending(c => c);
        
        return string.Concat(sortedChars);
    }
}