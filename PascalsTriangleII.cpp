class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> row1;
        row1.push_back(1);
        if(!rowIndex) return row1;
        row1.push_back(1);
        vector<int> row2;
        vector<int> *row=&row1;
        vector<int> *prow=&row2;
        
        for(int i=2;i<=rowIndex;i++){
	  (*prow).clear();
	  (*prow).push_back(1);
	  for(int j=1;j<(*row).size();j++)
	    (*prow).push_back((*row)[j]+(*row)[j-1]);
	    (*prow).push_back(1);
            vector<int> *t=prow;
            prow=row;
            row=t;
	   // cout<<i<<"----------\n";
	  //  for(int i=0;i<(*row).size();i++)
	   //   cout<<(*row)[i]<<" ";
	//    cout<<endl;
        }
        
        return *row;
    }
};
