class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    int n=height.size();
    vector<int> left(n),right(n);
    for(int i=0;i<n;i++) left[i]=right[i]=i;

    for(int i=1;i<n;i++){
      int l=left[i];
      while(l>0 && height[i]<=height[l-1]) l=left[l-1];
      left[i]=l;
    }
    for(int i=n-2;i>=0;i--){
      int r=right[i];
      while(r+1<n&&height[i]<=height[r+1]) r=right[r+1];
      right[i]=r;
    }
   /* for(int i=0;i<n;i++)
      printf("%d ",left[i]);
    cout<<endl;

    for(int i=0;i<n;i++) printf("%d ",right[i]);
    cout<<endl;*/
    int ans=0;
    for(int i=0;i<n;i++) ans=max(ans,(right[i]-left[i]+1)*height[i]);
    return ans;

  }
};
