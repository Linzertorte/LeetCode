class Solution {
public:
    bool isScramble(string s1, string s2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
       int n1=s1.size(),n2=s2.size();
       if(s1==s2) return true;
       if(n1!=n2) return false;
       if(n1==1) return false;
       int alpha1[26]={0};
       int alpha2[26]={0};
       for(int i=0;i<n1;i++) alpha1[s1[i]-'a']++;
       for(int i=0;i<n2;i++) alpha2[s2[i]-'a']++;
       for(int i=0;i<26;i++) if(alpha1[i]!=alpha2[i]) return false;
       
       
       string s1_l,s1_r;
       string s2_l,s2_r;
       
       for(int i=1;i<n1;i++){
           
       
       
       s1_l=s1.substr(0,i);
       s1_r=s1.substr(i,n1);
       s2_l=s2.substr(0,i);
       s2_r=s2.substr(i,n2);
       string s1_ll=s1.substr(0,n1-i);
       string s1_rr=s1.substr(n1-i,n1);
       string s2_ll=s2.substr(0,n2-i);
       string s2_rr=s2.substr(n2-i,n2);
       if( isScramble(s1_l,s2_l) && isScramble(s1_r,s2_r)) return true;
       if( isScramble(s1_ll,s2_r) && isScramble(s1_rr,s2_l)) return true;
       if( isScramble(s1_l,s2_rr) && isScramble(s1_r,s2_ll)) return true;
       
    }
       return false;
       
       
    }
};
