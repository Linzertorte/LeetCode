class Solution {
public:
    void get_two_operands(int *a,int *b,stack<int> &st){
        *a=st.top();
        st.pop();
        *b=st.top();
        st.pop();
    }
    int evalRPN(vector<string> &tokens) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        stack<int> st;
        int a,b;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
    
                get_two_operands(&a,&b,st);
                st.push(b+a);
            }
            else if(tokens[i]=="-")
            {
                get_two_operands(&a,&b,st);
                st.push(b-a);
            }
            else if(tokens[i]=="*"){
                get_two_operands(&a,&b,st);
                st.push(b*a);
            }
            else if(tokens[i]=="/"){
                get_two_operands(&a,&b,st);
                st.push(b/a);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
