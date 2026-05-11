using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int[] solution(int[] array, int[,] commands) {
        List<int> answer = new List<int>();
        
        for (int i = 0; i < commands.GetLength(0); ++i)
        {
            int start = commands[i, 0];
            int end = commands[i, 1];
            int k = commands[i, 2];
            
            var temp = array.Skip(start - 1).Take(end - start + 1).OrderBy(x => x).ToList();
            
            answer.Add(temp[k - 1]);
        }
        
        return answer.ToArray();
    }
}