class Solution {
public:
    void sortColors(int A[], int n) {
        int pivot=1;
        int i,j,k;
        i=-1,j=-2;
        for(k=0;k<n;k++)
         if(A[k]<pivot){
            if(j<i) swap(A[k],A[++i]),j++;
            else{
                swap(A[k],A[++j]);
                swap(A[i++],A[j]);
            }
         }else if(A[k]==pivot) {
             if(j<i)j=i,i++;
             swap(A[k],A[++j]);
             
         }
    }
};
