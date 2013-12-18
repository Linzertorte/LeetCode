class Solution {
public:

    void dfs(int sub,int pos,int val,const string& s, string ip,vector<string> &ips){
        if(sub==4){
            ip.pop_back();
            if(pos==s.size()) ips.push_back(ip);
            return;
        } 
        if(pos==s.size()) return;
        int oldval=val;
        val=val*10+s[pos]-'0';
        if(val>255) return;
        if(ip.size() && ip[ip.size()-1]=='0' &&oldval==0) return;
        dfs(sub+1,pos+1,0,s,ip+s[pos]+".",ips); //a new subnet
        dfs(sub,pos+1,val,s,ip+s[pos],ips);
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        dfs(0,0,0,s,"",ips);
        return ips;
    }
};
