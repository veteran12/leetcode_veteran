/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if(intervals.empty()){
            vector<Interval> res;
            res.push_back(newInterval);
            return res;
        }
        int head=-1;
        int tail=-1;
        for(int i=0;i<intervals.size();i++){
            if(newInterval.start<=intervals[i].end){
                head=i;
                break;
            }
        }
        for(int i=intervals.size()-1;i>=0;i--){
            if(newInterval.end>=intervals[i].start){
                tail=i;
                break;
            }
        }
            vector<Interval> res;
            for(int i=0;i<intervals.size();i++){
                if(head==-1&&i==tail){
                    res.push_back(intervals[i]);
                    res.push_back(newInterval);
                    continue;
                }else if(tail==-1&&head==i){
                    res.push_back(newInterval);
                    res.push_back(intervals[i]);
                    continue;
                }else if(tail==head-1&&head==i){
                    res.push_back(newInterval);
                    res.push_back(intervals[i]);
                    continue;
                }
                
                if(i!=head)
                    res.push_back(intervals[i]);
                else{
            Interval x(min(intervals[head].start,newInterval.start),max(intervals[tail].end,newInterval.end));
                        res.push_back(x);
                        i=tail;
                }
            }
            return res;
    }
    
    
    
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        vector<Interval>::iterator it = intervals.begin();
        bool inserted = false;
        for (; it != intervals.end(); ++it)
        {
            if (inserted || it->end < newInterval.start) // non-overlaping
            {
                res.push_back(*it);
            }
            else if (newInterval.end < it->start)
            {
                res.push_back(newInterval);
                res.push_back(*it);
                inserted = true;
            }
            else
            {
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
            }
        }
        if (!inserted)
            res.push_back(newInterval);
        return res;
    }
};
