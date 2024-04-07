//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        // Your code goes here
        vector<string>ans;
        string str="";
        vector<vector<int>>vis (n,vector<int>(n,0));
        if(matrix[0][0]==0 || matrix[n-1][n-1]==0)return {"-1"};
        vis[0][0]=1;
        f(0,0,matrix,n,ans,str,vis);
        return ans;
    }
    void f(int row,int col,vector<vector<int>>&matrix,int n,vector<string>&ans,string str,
    vector<vector<int>>&vis){
        
        if(row==n-1 and col==n-1){
            ans.push_back(str);
            return;
        }
        
        int dr[]={0,0,1,-1},dc[]={1,-1,0,0};
        string check="RLDU";
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and matrix[nrow][ncol]==1
                and vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                f(nrow,ncol,matrix,n,ans,str+check[i],vis);
                vis[nrow][ncol]=0;
                
            }
            
        }
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends