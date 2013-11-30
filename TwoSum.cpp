class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_map<int,int> dict;
        vector<int> answer;
        for(int i=0;i<numbers.size();i++){
            int n=numbers[i];
            int want=target-n;
            if(dict.find(want)!=dict.end()) {
                answer.push_back(dict[want]+1);
                answer.push_back(i+1);
                return answer;
            }else{
                dict[n]=i;
            }
            
        }
    }
};
