class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(!n) return 0;
        int i=0;
        int cnt=1;
        int j=1;
        while(j<n){
            while(j<n&& A[j]==A[i] && cnt<2) A[++i]=A[j],j++,cnt++;
            while(j<n&& A[j]==A[i]&&cnt==2) j++;
            cnt=0;
            if(j<n&&A[j]!=A[i]) cnt++,A[++i]=A[j],j++;
        }
        return i+1;
    }
};
