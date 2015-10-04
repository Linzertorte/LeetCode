struct M{
    string n;
};
bool operator<(const M& m1,const M& m2){
    return m1.n+m2.n<m2.n+m1.n;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        char buf[100];
        M m;
        priority_queue<M> Q;
        for(auto n:nums){
            sprintf(buf,"%d",n);
            m.n = string(buf);
            Q.push(m);
        }
        string result = "";
        while(!Q.empty()){
            result += Q.top().n;
            Q.pop();
        }
        int i=0;
        while(i<result.size()-1 && result[i]=='0') i++;
        return result.substr(i);
    }
};
