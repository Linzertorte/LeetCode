class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> net_gas=gas;
        int n=gas.size();
        for(int i=0;i<n;i++) net_gas[i] -= cost[i];
        int start=0;
        while(start<n){
            int i=0;
            int sum=0;
            for(i=0;i<n;i++){
                int idx=(start+i)%n;
                sum+=net_gas[idx];
                if(sum<0){
                    start=start+i+1;
                    break;
                }
            }
            if(i==n) return start;
            
        }
        
        return -1;
        
    }
};
