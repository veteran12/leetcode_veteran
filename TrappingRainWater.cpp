int trap(int A[], int n) {
        int i=0;
        int j=n-1;
        int low=min(A[i],A[n-1]);
        int res=0;
        while(i<j){
            if(A[i]<=A[j]){
                low=max(low,A[i]);
                i++;
                if(A[i]<low)
                    res+=low-A[i];
            }
            else{
                low=max(low,A[j]);
                j--;
                if(A[j]<low)
                    res+=low-A[j];
            }
        }
        return res;
    }
    /*int trap(int A[], int n) {
        int res = 0;
        int left = A[0];
        stack<int> tmp;
        tmp.push(A[0]);
        
        for (int i=1; i<n; i++) {
            if (A[i] >= left) {
                while (!tmp.empty() && left >= tmp.top()) {
                    res += left - tmp.top();
                    tmp.pop();
                }
                tmp.push(A[i]);
                left = A[i];
            }
            else
                tmp.push(A[i]);
        }
        
        int x = tmp.top();
        while (!tmp.empty()) {
            if (x >= tmp.top()) {
                res += x-tmp.top();
            }
            else {
                x = tmp.top();
            }
            tmp.pop();
        }
        return res;
    }*/