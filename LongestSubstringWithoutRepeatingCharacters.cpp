class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<char,int> freq;
        int re=0,cnt=0;
        for(int i=0,j=0;i<s.size();i++){
            char c=s[i];
            if(!freq[c]){
                //no found
                cnt++;
                freq[c]=1;
            }else
            {
                re=max(re,cnt);
                while(s[j]!=c) freq[s[j]]=0,j++,cnt--;
                j++;
            }
        }
        re=max(re,cnt);
        return re;
        
    }
};
