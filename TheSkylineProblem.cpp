struct Event{
    int x,h;
    bool in;
};
bool operator<(const Event& e1,const Event& e2){
    if(e1.x==e2.x) return e1.in;
    return e1.x<e2.x;
}
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Event> events;
        for(auto building:buildings){
            Event e;
            e.x = building[0];
            e.h = building[2];
            e.in = true;
            events.push_back(e);
            e.x = building[1];
            e.h = building[2];
            e.in = false;
            events.push_back(e);
        }
        sort(events.begin(),events.end());
        vector<pair<int,int>> ans;
        multiset<int> hs;
        int h = 0;
        for(auto e:events){
            if(e.in){
                hs.insert(e.h);
            }else{
                hs.erase(hs.find(e.h));
            }
            int nh;
            if(hs.empty()) nh = 0;
            else nh = *(--hs.end());
            if(nh!=h){
                h = nh;
                if(ans.size() && ans.back().first==e.x) ans.back().second=h;
                else 
                ans.push_back(make_pair(e.x,h));
            }
        }
        return ans;
    }
};
