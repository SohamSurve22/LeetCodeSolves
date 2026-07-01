class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;


        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        vector<int> dr={1,-1,0,0};
        vector<int> dc={0,0,1,-1};

        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr>=0 && nc>=0 && nr<n && nc<n &&
                   dist[nr][nc]==INT_MAX){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }

        auto can=[&](int safe){

            if(dist[0][0]<safe) return false;

            queue<pair<int,int>> qq;
            vector<vector<int>> vis(n, vector<int>(n,0));

            qq.push({0,0});
            vis[0][0]=1;

            while(!qq.empty()){
                auto [r,c]=qq.front();
                qq.pop();

                if(r==n-1 && c==n-1)
                    return true;

                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];

                    if(nr>=0 && nc>=0 && nr<n && nc<n &&
                       !vis[nr][nc] &&
                       dist[nr][nc]>=safe){

                        vis[nr][nc]=1;
                        qq.push({nr,nc});
                    }
                }
            }

            return false;
        };

        int low=0, high=2*n;

        while(low<=high){
            int mid=(low+high)/2;

            if(can(mid))
                low=mid+1;
            else
                high=mid-1;
        }

        return high;
    }
};