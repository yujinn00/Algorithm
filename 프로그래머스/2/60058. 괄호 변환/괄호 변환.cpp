#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string p) {
    string answer = "(";
    
    // 1단계.
    
    if (p.empty())
    {
        return p;
    }
    
    
    // 2단계.
    
    string u, v;
    int l = 0, r = 0;
    
    for (int i = 0; i < p.length(); ++i)
    {
        u += p[i];
        
        if (p[i] == '(')
        {
            l++;
        }
        else
        {
            r++;
        }
        
        if (l == r)
        {
            for (int j = i + 1; j < p.length(); ++j)
            {
                v += p[j];
            }
            break;
        }
    }
    
    // 3단계.
    
    stack<char> s;
    bool flag = true;
    
    for (int i = 0; i < u.length(); ++i)
    {
        if (u[i] == '(')
        {
            s.push(u[i]);
        }
        else
        {
            if (!s.empty())
            {
                s.pop();
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    
    // 3단계.
    
    if (flag && s.empty())
    {
        u += solution(v);
        return u;
    }
    
    // 4단계.
    
    else
    {
        answer += solution(v);
        answer += ")";
        u.erase(u.begin());
        u.erase(u.end() - 1);
        for (int i = 0; i < u.length(); i++)
        {
            if (u[i] == '(')
            {
                answer += ")";
            }
            else
            {
                answer += "(";
            }
        }
        
        return answer;
    }
}