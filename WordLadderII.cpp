class Solution {
public:
    vector<string> nextWord(string w,unordered_set<string> &dict){
        vector<string> next;
        int len = w.size();
        for(int i=0;i<len;i++)
            for(char c='a';c<='z';c++){
                string w1 = w;
                if(c==w1[i]) continue;
                w1[i]=c;
                if(dict.count(w1))
                    next.push_back(w1);
            }
        return next;
    }
    void dfs(int w,int e,vector<int> &dist,vector<string> &words, vector<vector<int>> &next_word, unordered_set<string> &dict, vector<string> &path, vector<vector<string>> &paths){
        path.push_back(words[w]);
        if(w==e){
            paths.push_back(path);
            path.pop_back();
            return;
        }
        for(int i:next_word[w]){
            if(dist[i]==dist[w]+1){
                dfs(i,e,dist,words,next_word,dict,path,paths);
            }
        }
        path.pop_back();
        
    }
    
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        int n = dict.size();
        vector<string> words(n);
        unordered_map<string,int> word_id;
        vector<vector<int> > next_word(n);
        int cnt = 0;
        for(auto i = dict.begin();i!=dict.end();i++)
            words[cnt] = *i, word_id[*i] = cnt++;
        
        int s = word_id[start];
        int e = word_id[end];
        for(int i=0;i<n;i++)
            for(string w:nextWord(words[i],dict)) next_word[i].push_back(word_id[w]);
        vector<int> dist(n,-1);
        queue<int> q;
        q.push(s);
        dist[s] = 1;
        while(!q.empty()){
            int head = q.front();
            q.pop();
            for(int i:next_word[head])
                if(dist[i]==-1){
                    dist[i] = dist[head]+1;
                    q.push(i);
                }
            
        }
        vector<vector<string>> paths;
        if(dist[e]==-1)
            return paths;
        vector<string> path;
        dfs(s,e,dist,words,next_word,dict,path,paths);
        return paths;
    }
};
