public class Solution {
    public string solution(string[] seoul) {
        int x = 0;
        
        for (int i = 0; i < seoul.Length; ++i)
        {
            if (seoul[i] == "Kim")
            {
                x = i;
                break;
            }            
        }
        
        return $"김서방은 {x}에 있다";
    }
}