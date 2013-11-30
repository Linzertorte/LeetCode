class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n=prices.size();
        if(!n) return 0;
        int lowest=prices[0];
        int profit=0;
        for(int i=0;i<n;i++){
            if(prices[i]>=lowest) profit=max(profit,prices[i]-lowest);
            else lowest=prices[i];
        }
        return profit;
    }
};
