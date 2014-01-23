#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> lines;
        if(!L) {
            lines.push_back("");
            return lines;
        }
        vector<string> cur=words;
        string line="";
        int i=0;
        int cnt=0,l=0;
        int spaces;
        int extra,more;
        while(i<words.size()){
            while(i<words.size() && l<L){
                if(!cnt) l += words[i].size();
                else l += 1+words[i].size();
                cur[cnt++]=words[i++];
            }
            if(l>L) i--,cnt--,l-=(1+cur[cnt].size());
            // to line
            spaces=L-l;
            if(cnt>1)
            {
                extra = spaces/(cnt-1);
                more = spaces%(cnt-1);
            }else
            {
                extra=spaces, more = 1;
            }
            line = "";
            if(i==words.size()){
                l=0;
                for(int k=0;k<cnt;k++)
                    if(!k) line+=cur[k],l+=cur[k].size();
                    else line+=" "+cur[k],l+=1+cur[k].size();
                line+=(string(L-l,' '));
            }else{
                if(cnt>1)
                for(int k=0;k<cnt;k++){
                    if(!k) line+=cur[k];
                    else if(k>=1 && k<=more) line+=(string(extra+2,' '))+cur[k];
                    else line += (string(extra+1,' '))+cur[k];
                }else if(cnt==1) line+=cur[0]+(string(L-l,' '));
            }
            cnt=0,l=0;
            lines.push_back(line);
        }
        
        
        return lines;
    }
};

