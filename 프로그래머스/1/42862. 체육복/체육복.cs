using System;
using System.Linq;

public class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        Array.Sort(lost);
        Array.Sort(reserve);
        
        var realLost = lost.Where(l => !reserve.Contains(l)).ToList();
        var realReserve = reserve.Where(r => !lost.Contains(r)).ToList();
        
        for (int i = 0; i < realReserve.Count; ++i)
        {
            int current = realReserve[i];
            
            if (realLost.Contains(current - 1))
            {
                realLost.Remove(current - 1);
            }
            else if (realLost.Contains(current + 1))
            {
                realLost.Remove(current + 1);
            }
        }
        
        return n - realLost.Count;
    }
}