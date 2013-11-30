class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n=prices.size();
   
        int profit=0;
        int j=n-1;
        int i=n-2;
        while(i>=0){
            while(i>=0&& prices[i]<prices[i+1]) i--;
            profit += prices[j]-prices[i+1];
            j=i;
            i--;
            if(i<0) break;
           
        }
        
        return profit;
    }
};
