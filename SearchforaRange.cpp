class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        return sub(A, 0, n-1, target);
    }
    
    vector<int> sub(int A[], int s, int e, int target) {
        vector<int> res;
        if(s > e){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        int mid = (e + s) / 2;
        if(A[mid] < target)
            return sub(A, mid+1, e, target);
        else if(A[mid] > target)
            return sub(A, s, mid-1, target);
        else {
            res.push_back(subfront(A, s, mid, target));
            res.push_back(subend(A, mid, e, target));
        }
        return res;
    }
    
    int subend(int A[], int s, int e, int target) {
        int mid;
        while(s < e) {
            mid = (e + s) / 2 + 1; //here mid=(start+end)/2+1 select mid close to high
            if(A[mid] > target)
                e = mid - 1;
            else {
                if(s == mid)
                    return mid;
                else
                    s = mid;
            }
        }
        return s;
    }
    
    int subfront(int A[], int s, int e, int target) {
        int mid;
        while(s < e) {
            mid = (e + s) / 2;  // be careful mid = mid=(start+end)/2 select mid close to low
            if(A[mid] < target)
                s = mid + 1;
            else {
                if(e == mid)
                    return mid;
                else
                    e = mid;
            }
        }
        return e;
    }
};




vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
        int low=findlow(A,0,n-1,target);
        int high=findhigh(A,0,n-1,target);
        res.push_back(low);
        res.push_back(high);
        return res;
    }
    int findlow(int A[], int start,int end, int target){
    if(start>end)
        return -1;
    if(start==end&&A[start]==target)
        return start;
    int mid=(start+end)/2; // be careful mid = mid=(start+end)/2 select mid close to low
    if(A[mid]<target)
        return findlow(A,mid+1,end,target);
    else if(A[mid]>target)
        return findlow(A,start,mid-1,target);
    else return findlow(A,start,mid,target);
}
    int findhigh(int A[], int start,int end, int target){
    if(start>end)
        return -1;
    if(start==end&&A[start]==target)
        return start;
    if(start==end&&A[start]!=target)
        return -1;
    int mid=(start+end)/2+1; //here mid=(start+end)/2+1 select mid close to high
    if(A[mid]>target)
        return findhigh(A,start,mid-1,target);
    else if(A[mid]<target)
        return findhigh(A,mid+1,end,target);
    else return findhigh(A,mid,end,target);
}