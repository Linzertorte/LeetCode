enum Roman{
    I=1,V=5,X=10,L=50,C=100,D=500,M=1000
};


class Solution {
public:
    string helper(int *num,int v,int i,string si,string sv,string sx){
    
            if(*num>=v+4*i) {
                *num-=(v+4*i);
                return si+sx;
            }
            *num-=v;
            return sv;
    }
    string int_to_string(int *num){
        if(*num>=M) {
            *num-=M;
            return "M";
        }else if(*num>=D){
            return helper(num,D,C,"C","D","M");
        }else if(*num>=C){
            if(*num>=4*C) {
                *num-=4*C;
                return "CD";
            }
            *num-=C;
            return "C";
        }else if(*num>=L) return helper(num,L,X,"X","L","C");
        else if(*num>=X){
            if(*num>=4*X){
                *num-=4*X;
                return "XL";
            }
            *num-=X;
            return "X";
        }else if(*num>=V) return helper(num,V,I,"I","V","X");
        else if(*num>=I){
            if(*num>=4*I){
                *num-=4*I;
                return "IV";
            }
            *num-=I;
            return "I";
        }
            
        
        
    }
    string intToRoman(int num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.    
        string s="";
        while(num){
            
            s+=int_to_string(&num);
            
        }
        return s;
    }
};
