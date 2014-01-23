class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int diff=INT_MAX;
        int answer;
        for(int i=0;i<num.size();i++)
        {
            int s=i+1,e=num.size()-1;
            while(s<e){
             	int sum=num[i]+num[s]+num[e];
                if(abs(target-sum)<diff) diff=abs(target-sum),answer=sum;
                if(sum<target) s++;
                else if(sum>target) e--;
                else return target;

            }
        }
        return answer;
    }
};



