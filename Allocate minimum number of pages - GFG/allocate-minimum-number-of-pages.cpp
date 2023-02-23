//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to verify we can allocate or not
    bool canAllocate(int pages[], int capacity, int student, int n){
        int curPage = 0, neededStudent = 1;
        for(int i = 0; i < n; ++i){
            curPage += pages[i];
            if(curPage > capacity){
                curPage = pages[i];
                ++neededStudent;
            }
        }
        return neededStudent <= student;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        if(n < m){
            return -1;
        }
        int sum = 0, mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            mx = max(mx, arr[i]);
        }
        int left = mx, right = sum;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (canAllocate(arr, mid, m, n)) {
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends