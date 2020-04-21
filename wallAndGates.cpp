#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int rows = rooms.size();
        if(rows < 1)
            return;
        int cols = rooms.size();
        vector<pair<int,int>> dirs{{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<pair<int,int>,int>> q;
        
        auto checkBound = [&](int r,int c){
            return r>=0 && c>=0 && r<rows && c<cols;
        };

        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                
                if(rooms[i][j] == 0)
                    q.push({ {i,j}, 0});
                
                while(!q.empty()){
                    auto indices = q.front().first;
                    int dist = q.front().second;
                    int r = indices.first, c = indices.second;
                    
                    rooms[r][c] = min(rooms[r][c], dist);

                    for(auto dir : dirs){
                        int a = r + dir.first;
                        int b = c + dir.second;
                        if(checkBound(a,b) && rooms[r][c] != -1 ){
                            q.push({{a,b},dist+1});
                        }
                    }

                }
            }
        }
    }
};