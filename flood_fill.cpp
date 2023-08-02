
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>> &image,int row,int col,int newColor,int initial,
    vector<vector<bool>> &vis)
    {
        vis[row][col] = 1;
        int n = image.size();
        int m = image[0].size();
        image[row][col] = newColor;
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                int nrow = row+i;
                int ncol = col+j;
                if(i==0 || j==0)
                {
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol] == initial 
                    && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        initial = image[nrow][ncol];
                        image[nrow][ncol] = newColor;
                        dfs(image,nrow,ncol,newColor,initial,vis);
                    }
                }
                
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    
        int n = image.size();
        int m = image[0].size();
        
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int initial = image[sr][sc];
        dfs(image,sr,sc,newColor,initial,vis);
        
        return image;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}