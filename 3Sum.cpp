class Solution {
public:
  vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(),num.end());
    map<int,int> dict;
    map<pair<int,int>,int> vis;
    vector<vector<int> > ans;
    for(int i=0;i<num.size();i++){
      dict[num[i]]++;
    }
    for(int i=0;i<num.size();i++)
      for(int j=i+1;j<num.size();j++){
	vector<int> three(3);
	three[0]=num[i],three[1]=num[j];
	int want=0-three[0]-three[1];
	if(want>three[1]&&dict[want]&&!vis[make_pair(three[0],three[1])]){
	  three[2]=want;
	  ans.push_back(three);
	  vis[make_pair(three[0],three[1])]=1;
	}
	else if(want==three[1]){
	  int dup=2;
	  if(three[1]==three[0]) dup++;
	  if(dict[want]>=dup && !vis[make_pair(three[0],three[1])]){
	    three[2]=want,ans.push_back(three);
	    vis[make_pair(three[0],three[1])]=1;
	  }
	}
      }
            
    return ans;
  }
};
