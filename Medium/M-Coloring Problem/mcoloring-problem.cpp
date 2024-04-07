//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int>color (n,0);
        return f(0,m,n,graph,color);
    }
    bool f(int idx,int m,int n,bool graph[101][101],vector<int>&color){
        
        if(idx==n){
            return true;
        }
        
        
        for(int col=1;col<=m;col++){
            
            if(isvalid(idx,n,col,graph,color)){
                color[idx]=col;
                if(f(idx+1,m,n,graph,color))
                return true;
                color[idx]=0;
            }
        }
        return false;
    }
    bool isvalid(int idx,int n,int col,bool graph[101][101],vector<int>&color){
        
        for(int i=0;i<n;i++){
            if(i!=idx and graph[i][idx]==1 and color[i]==col)
            return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends