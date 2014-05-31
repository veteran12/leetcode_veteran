/*
 *if duplicates are allowed, it is hard to split the array, so just traversal the array in linear time. 
*/
class Solution {
public:
    bool search(int A[], int n, int target) {
        for(int i=0; i < n; i++){
            if( A[i] == target )
                return true;
        }
        return false;
    }
};