
class Solution {
	public:

		void rmq_init(int M[2100][20], int A[], int N)
		{
			int i, j;

			//initialize M for the intervals with length 1
			for (i = 0; i < N; i++)
				M[i][0] = i;
			//compute values from smaller to bigger intervals
			for (j = 1; 1 << j <= N; j++)
				for (i = 0; i + (1 << j) - 1 < N; i++)
					if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
						M[i][j] = M[i][j - 1];
					else
						M[i][j] = M[i + (1 << (j - 1))][j - 1];
		}

		void makesa(const char *s,int sa[],int height[],int rank[])
		{
			int n=strlen(s)+1;
			int *x,*y;
			int cnt[2100];
			int ma[2100],mb[2100];

			x=ma,y=mb;
			int na=n>256?n:256;
			//radix sort
			memset(cnt,0,sizeof(cnt));
			for(int i=0;i<n;i++)
				cnt[x[i]=s[i]]++;
			for(int i=1;i<na;i++) cnt[i]+=cnt[i-1];
			for(int i=n-1;i>=0;i--) sa[--cnt[x[i]]]=i;


			//double radix sort
			int p,j,i;
			for(p=1,j=1;p<n;j*=2)
			{

				for(p=0,i=n-j;i<n;i++) y[p++]=i; //sort 2nd key
				for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
				memset(cnt,0,sizeof(cnt));
				for(i=0;i<n;i++) cnt[x[y[i]]]++;
				for(i=1;i<na;i++) cnt[i]+=cnt[i-1];
				for(i=n-1;i>=0;i--) sa[--cnt[x[y[i]]]]=y[i];
				//  print(sa,n);
				swap(x,y);
				x[sa[0]]=0;
				p=1;
				for(i=1;i<n;i++)
					x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+j]==y[sa[i-1]+j]) ?p-1:p++;

			}
			for(int i=0;i<n;i++) rank[sa[i]]=i;
			int k=0;
			for(int i=0;i<n;height[rank[i++]]=k)
				for(k?k--:0,j=sa[rank[i]-1];s[i+k]==s[j+k];k++);
		}
		int rmq(int M[][20],int a,int b,int h[]){
			if(a>b) swap(a,b);
			a++;
			if(a==b) return h[b];
			int k=floor(log(b-a+1.0)/log(2.0));
			return min(h[M[a][k]], h[M[b-(1<<k)+1][k]]);


		}
		string longestPalindrome(string s) {
			string t=s;
			int n=s.size();
			reverse(t.begin(),t.end());
			s=s+"#"+t;
			int sa[2100];
			int height[2100];
			int rank[2100];
			makesa(s.c_str(),sa,height,rank);
			//		cout<<"sa====="<<endl;
			/*	for(int i=0;i<2*n+2;i++)
				cout<<sa[i]<<" ";
				cout<<endl;
				for(int i=0;i<2*n+2;i++)
				cout<<height[i]<<" ";
				cout<<endl;
				*/

			int M[2100][20];
			rmq_init(M,height,2*n+2);
			int m=0;
			int l,r;
			for(int i=0;i<n;i++)
			{
				//偶数个
				int temp=rmq(M,rank[i],rank[2*n+1-i],height);
				if(2*temp>m){
					m=2*temp;
					l=i-temp;
					r=i+temp-1;
				}
				temp=rmq(M,rank[i],rank[2*n-i],height);
				if(2*temp-1>m){
					m=2*temp-1;
					l=i-temp+1;
					r=i+temp-1;
				}
			}
			//	cout<<"M"<<m<<endl;
			//     	cout<<"["<<l<<","<<r<<"]"<<endl;
			return s.substr(l,r-l+1);


		}
};
