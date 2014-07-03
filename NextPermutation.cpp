class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int front, back;
        front = back = -1;
        for (int i=num.size()-1; i>=0; i--) {
            for (int j=i-1; j>=0; j--){
                if (num[i] > num[j]) {
                    if (j > front) {
                        front = j;
                        back = i;
                    }
                }
            }
        }
        swap(num[front], num[back]);
        if (front != back )
            sort(num.begin()+front+1, num.end());
        else
            sort(num.begin(), num.end());
        return;
    }
};