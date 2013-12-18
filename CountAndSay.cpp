class Solution {
public:
    string next(string s){
        string nxt="";
        int i=0,j=0;
        while(i<s.size()){
            int cnt=0;
            while(j<s.size()&&s[j]==s[i]) j++,cnt++;
            nxt+=char(cnt+'0');
            nxt+=s[i];
            i=j;
        }
        return nxt;
        
    }
    string countAndSay(int n) {
        string result="1";
        for(int i=2;i<=n;i++)
        {
            result=next(result);
        }
        return result;
    }
};
