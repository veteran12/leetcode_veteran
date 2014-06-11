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
    static bool cmp(const Interval &a,const Interval &b) //here must be decleared as static function
    {
        return a.start<b.start;
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        if (intervals.size() == 0)
            return res;
        sort(intervals.begin(),intervals.end(),cmp);
        int start_tmp = intervals[0].start;
        int end_tmp = intervals[0].end;
        for (int i=1; i<intervals.size(); i++){
            if (end_tmp >= intervals[i].start){
                if (end_tmp < intervals[i].end)
                    end_tmp = intervals[i].end;
                continue;
            }else{
                Interval x(start_tmp, end_tmp);
                res.push_back(x);
                start_tmp = intervals[i].start;
                end_tmp = intervals[i].end;
            }
        }
        Interval x(start_tmp, end_tmp);
        res.push_back(x);
        
        return res;
    }
};