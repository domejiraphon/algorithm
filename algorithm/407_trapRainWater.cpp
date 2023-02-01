class Solution {
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    int n=heightMap.size();
    int m=heightMap[0].size();
    vector<vector<int>> leftMost(n, vector<int> (m));
    vector<vector<int>> rightMost(n, vector<int> (m));
    vector<vector<int>> topMost(n, vector<int> (m));
    vector<vector<int>> bottomMost(n, vector<int> (m));

    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (j == 0){
          leftMost[i][j] = heightMap[i][j];}
        else if (j == m -1){
          rightMost[n-i-1][m-j-1] = heightMap[n-i-1][m-j-1];}

        leftMost[i][j] = max(leftMost[i][j-1], heightMap[i][j]);
        rightMost[n-i-1][m-j-2] = max(rightMost[n-i-1][m-j-1], 
                                      heightMap[n-i-1][m-j-2]);
      }
    }
    exit(0);

    for (int j=0; j<n; j++){
      for (int i=0; i<m; i++){
        if (i == 0 && j == 0){
          topMost[i][j] = heightMap[i][j];
          bottomMost[n-i-1][m-j-1] = heightMap[n-i-1][m-j-1];}

        topMost[i][j] = max(topMost[i][j-1], heightMap[i][j]);
        bottomMost[n-i-1][m-j-2] = max(bottomMost[n-i-1][m-j-1], 
                                      heightMap[n-i-1][m-j-2]);
        
      }
    }
    int res=0;
    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        res += min(min(leftMost[i][j], rightMost[i][j]),
                   min(topMost[i][j], bottomMost[i][j])) - heightMap[i][j];
      }
    }
    return res;
  }
};
