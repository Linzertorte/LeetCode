class Solution {
public:
    
    string add(string num1,string num2){
        if(num1.size()<num2.size()) swap(num1,num2);
        int i=num1.size()-1;
        int j=num2.size()-1;
        int carry=0;
        int x,y;
        while(j>=0 || i>=0){
            
            if(i>=0)x=num1[i]-'0';
            else x=0;
            if(j>=0)y=num2[j]-'0';
            else y=0;
            num1[i]=(x+y+carry)%10+'0';
            carry=(x+y+carry)/10;
            j--,i--;
        }
        if(carry) num1="1"+num1;
        return num1;
    }
    string mul(string num,int n,int zeros){
      int carry=0;
      int j=num.size()-1;
      for(;j>=0;j--){
        int x=num[j]-'0';
        num[j]=((x*n)+carry)%10+'0';
        carry=(x*n+carry)/10;
      }
      if(carry) num=char(carry+'0')+num;
      return num.append(zeros,'0');
      
    }
        
    string multiply(string num1, string num2) {
        string ans="0";
        for(int j=num2.size()-1,zero=0;j>=0;j--,zero++){
            ans=add(ans,mul(num1,num2[j]-'0',zero));
        }
        
        while(ans.size()>1&&ans[0]=='0') ans=ans.substr(1);
        return ans;
    }
};
