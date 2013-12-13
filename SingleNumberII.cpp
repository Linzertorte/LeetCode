class Solution {
public:
    int singleNumber(int A[], int n) {
        map<int,int> dict;
        for(int i=0;i<n;i++){
            int x=A[i];
            if(dict[x]==2) dict.erase(x);
            else dict[x]++;
        }
        
        return dict.begin()->first;
    }
};
