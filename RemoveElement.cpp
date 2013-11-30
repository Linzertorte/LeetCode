class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-1;j++)
                if(A[j]==elem) swap(A[j],A[j+1]);
        while(A[n-1]==elem) n--;
        return n;
    }
};
