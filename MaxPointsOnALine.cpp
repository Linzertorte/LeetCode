#include<algorithm>

int gcd(int a,int b)
{
  if(!b) return a;
  return gcd(b,a%b);
}
struct Pt{
  int dx,dy;
  Pt(){dx=0,dy=0;}
  Pt(int x,int y){
    int g=gcd(abs(x),abs(y));
    if(x==0 && y==0) dx=0,dy=0;
    else if(x==0) dx=0,dy=1;
    else if(y==0) dx=1,dy=0;
    else if(y>0)
      dx=x/g,dy=y/g;
    else if(y<0)
      dx=-x/g,dy=-y/g;
  }
  
};
bool operator==(const Pt &a, const Pt &b)
{
  return a.dx==b.dx && a.dy==b.dy;
}
bool operator<(const Pt &a,const Pt &b){

  if(a.dx==b.dx) return a.dy<b.dy;
  return a.dx<b.dx;
}

class Solution {
public:
  

    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
      int n=points.size();
      vector<Pt> angles(n);
      int ans=0;
      for(int i=0;i<n;i++)
	  {
	      map<Pt,int> dict;
	      int same=0;
	      int lm=0;
	  for(int j=0;j<n;j++)
	    {
	      Point p=points[i];
	      Point q=points[j];
	      angles[j]=Pt(q.x-p.x,q.y-p.y);
	      if(angles[j]==Pt(0,0)) same++;
	      else lm=max(lm,++dict[angles[j]]);
	    }
	    ans=max(ans,same+lm);
	  }
	  return ans;
    }
};


