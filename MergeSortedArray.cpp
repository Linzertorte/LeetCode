class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int k=0;
        int i,j;
        i=j=0;
        vector<int> C(m+n);
        while(i<m&&j<n) C[k++]=(A[i]<B[j]?A[i++]:B[j++]);
        while(i<m) C[k++]=A[i++];
        while(j<n) C[k++]=B[j++];
        for(i=0;i<m+n;i++) A[i]=C[i];
    }
};
