/*
 *This method uses stack to store a non-descending satck to avoid repeat calculating, details see code and note.
 *
 */
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        stack<int> stk;
        int res = 0;
        int i = 0;
        while( i < height.size() ){
            if( stk.empty() || height[stk.top()] <= height[i] )
                stk.push(i++);
            else{
                int index = stk.top();
                stk.pop();//must pop first
                int width = stk.empty()?i:i - stk.top() - 1;//tricky!
                res = max( res, height[index] * width );
            }
        }
        return res;
    }
};