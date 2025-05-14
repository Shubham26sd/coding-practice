//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

    int min(int arr[], int n){
        int min = INT_MAX;
        for(int i = 0; i<n; i++){
            if(min>arr[i])
                min = arr[i];
        }
        return min;
    }
    
	int findKRotation(int arr[], int n) {
	    int minValue = min(arr,n);
	    for(int i = 0; i<n; i++){
	        if(arr[i]==minValue){
	            return i;
	        }
	    }
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends