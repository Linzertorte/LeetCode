struct Config{
    string word;
    int step;
};
class Solution {
public:
    inline bool isNextWord(const string &w1,const string &w2){
        int cnt=0;
        for(int i=0;i<w1.size();i++) {
            if(w1[i]!=w2[i]) cnt++;
            if(cnt>1) return false;
        }
        return cnt==1;
    }
    
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        queue<Config> newest;
        newest.push(Config{start,1});
        //unordered_set<string> searched;
        dict.erase(start);
        while(!newest.empty()){
            Config head=newest.front();
            newest.pop();
            if(isNextWord(head.word,end)) return head.step+1;
            for (auto a = dict.begin(); a != dict.end();){
                
                if(isNextWord(*a,head.word)) {
                    newest.push(Config{*a,head.step+1}),a=dict.erase(dict.find(*a));
                }else a++;
                
            }
            
        }
        return 0;
        
    }
};
