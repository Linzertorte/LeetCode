class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int lmax=-1,lmin=INT_MAX,max_i,min_i;
        vector<int> lprofit=prices;
        vector<int> rprofit=prices;
        max_i=min_i=0;
        for(int i=0;i<prices.size();i++){
            if(max_i<min_i) lmax=-1;
            if(lmax<=prices[i]){
                max_i=i,lmax=prices[i];
            }
            if(lmin>prices[i]){
                min_i=i,lmin=prices[i];
            }
            lprofit[i]=(max_i>=min_i)?lmax-lmin:lprofit[i-1];
        }
        lmax=-1,lmin=INT_MAX;
        max_i=min_i=prices.size()-1;
        for(int i=prices.size()-1;i>=0;i--){
            if(max_i<min_i) lmin=INT_MAX;
            if(lmax<prices[i]){
                max_i=i,lmax=prices[i];
            }
            if(lmin>=prices[i]){
                min_i=i,lmin=prices[i];
            }
            rprofit[i]=(max_i>=min_i)?lmax-lmin:rprofit[i+1];
        }
        int ans=0;
      //  for(int i=0;i<prices.size();i++)
        //    cout<<lprofit[i]<<" "<<rprofit[i]<<endl;
        for(int i=0;i<prices.size();i++) ans=max(ans,lprofit[i]+rprofit[i]);
        return ans;
    }
};
