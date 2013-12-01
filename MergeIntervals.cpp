/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Event{
    int num;
    int sign;
};
bool operator<(const Event &e1,const Event &e2){
    if(e1.num==e2.num) return e1.sign>e2.sign;
    return e1.num<e2.num;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Event> events;
        for(int i=0;i<intervals.size();i++){
            events.push_back(Event{intervals[i].start,1});
            events.push_back(Event{intervals[i].end,-1});
        }
        sort(events.begin(),events.end());
        vector<Interval> merged;
        Interval v;
        int num=0;
        int in=0;
        for(int i=0;i<events.size();i++){
            num+=events[i].sign;
            if(num==1&&!in) v.start=events[i].num,in=1;
            if(i&&!num){
                v.end=events[i].num;
                in=0;
                merged.push_back(v);
            }
        }
        return merged;
        
    }
};
