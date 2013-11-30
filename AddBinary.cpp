class Solution {
public:
    string reverse(string s){
        
        int len=s.size();
        for(int i=0;i<len/2;i++) swap(s[i],s[len-1-i]);
        return s;
    }
    string addBinary(string a, string b) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(a.size()>b.size()) swap(a,b);
        a=reverse(a),b=reverse(b);
        int carry=0;
        int i;
        for(i=0;i<a.size();i++)
        {
            int num=a[i]+b[i]-2*'0'+carry;
            carry=num/2;
            b[i]='0'+num%2;
        }
        for(;i<b.size();i++){
            int num=b[i]-'0'+carry;
            carry=num/2;
            b[i]='0'+num%2;
        }
        if(carry) b.append(1,'1');
        return reverse(b);
    }
};
