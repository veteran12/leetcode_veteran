class Solution {
public:
    int search(int A[], int n, int target) {
        return sub(A, 0, n-1, target);
    }
    
    int sub(int A[], int start, int end, int target) {
        if( start > end )
            return -1;
        int mid = (start + end) / 2;
        
        if( A[mid] == target )
            return mid;
        else if( target < A[mid] ){
            if( target < A[start] && A[mid] >= A[start] )
                 return sub(A, mid + 1, end, target);
            else
                return sub(A, start, mid - 1, target);
        }else{
            if( target > A[end] && A[mid] <= A[end] )
                 return sub(A, start, mid - 1, target);
            else
                return sub(A, mid + 1, end, target);
        }
    }
};

/*
 *class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return an integer
    def search(self, A, target):  //member function is different from simple functions, in member function, a self variable must be added to the attribute list, when we want to call a member function use self.someMethod() :)
        return self.sub(A, 0, len(A) - 1, target)
    
    def sub(self, A, start, end, target ):
        if(start > end):
            return -1
        mid = (start + end)/2
        if( A[mid] == target ):
            return mid
        elif( target < A[mid] ):
            if( target < A[start] and A[mid] >= A[start] ):
                return self.sub(A, mid + 1, end, target)
            else:
                return self.sub(A, start, mid - 1, target)
        else:
            if( target > A[end] and A[mid] <= A[end] ):
                return self.sub(A, start, mid - 1, target)
            else:
                return self.sub(A, mid + 1, end, target)
 */