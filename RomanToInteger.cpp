enum Roman{
    I=1,V=5,X=10,L=50,C=100,D=500,M=1000
};
class Solution {
public:
    int char_to_int(char c){
        switch(c){
            case 'I': return I;
            case 'V': return V;
            case 'X': return X;
            case 'L': return L;
            case 'C': return C;
            case 'D': return D;
            case 'M': return M;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int result=0;
        int last=0,cur;
        for(int i=0;i<s.size();i++){
            cur=char_to_int(s[i]);
            result+=cur;
            if(cur>last) result-=2*last;
            last=cur;
        }
        return result;
    }
};
