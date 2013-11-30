
class Solution {
public:
   
    bool isPalindrome(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(x<0)return false;
        int div=1;
        int xx=x;
        while(xx>9) xx/=10,div*=10;
        //div/=10;
        while(x>10){
	  //	  cout<<"div"<<div<<endl;
	  //cout<<x<<endl;
            if(x%10==x/div){
                x=(x%div)/10;
                div/=100;
		//      cout<<"after"<<x<<endl;
            }else break;
        }
        if(x<10) return true;
        else return false;
    }
};

