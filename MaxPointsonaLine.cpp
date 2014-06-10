/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int N=points.size();
        int max1=0;
        int max2=0;
        int same=0;
        int vertical=0;
        map<float,int> tmp;
        for(int i=0;i<N;i++){
            tmp.clear();
            max2=0;
            vertical=0;
            same=0;//must take the repeated points into consideration
            for(int j=0;j<N;j++){
                if((points[i].y==points[j].y)&&(points[i].x==points[j].x))
                    same++;
                else if((points[i].x==points[j].x)&&(points[i].y!=points[j].y)){
                    vertical++;
                    max2=max(vertical,max2);
                }
                else{
                    float x=(float)(points[i].y-points[j].y)/(points[i].x-points[j].x);
                    tmp[x]++;
                    max2=max(tmp[x],max2);
                }
            }
            max1=max(max1,max2+same);
        }
        return max1;
    }
};