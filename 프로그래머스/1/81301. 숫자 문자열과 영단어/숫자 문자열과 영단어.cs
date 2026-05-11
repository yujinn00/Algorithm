using System;

public class Solution {
    public int solution(string s) {
        string[] words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        
        for (int i = 0; i < words.Length; ++i)
        {
            s = s.Replace(words[i], i.ToString());
        }
        
        return int.Parse(s);
    }
}