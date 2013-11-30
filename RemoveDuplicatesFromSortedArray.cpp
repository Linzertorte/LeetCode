class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i=-1,j=0;
        for(j=0;j<n;j++){
            if(i==-1||A[j]!=A[i]) A[++i]=A[j];
        }
        return i+1;
    }
};
