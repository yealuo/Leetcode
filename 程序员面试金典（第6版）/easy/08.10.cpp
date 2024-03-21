#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution1 {
   public:
    unordered_set<string> flag;

    vector<vector<int>> do_floodFill(vector<vector<int>>& image,
                                     int sr,
                                     int sc,
                                     int newColor,
                                     int oldColor) {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()) {
            return image;
        }

        if (image[sr][sc] == oldColor) {
            if (flag.find(to_string(sr) + to_string(sc)) != flag.end()) {
                return image;
            }

            image[sr][sc] = newColor;
            flag.insert(to_string(sr) + to_string(sc));

            do_floodFill(image, sr - 1, sc, newColor, oldColor);
            do_floodFill(image, sr + 1, sc, newColor, oldColor);
            do_floodFill(image, sr, sc - 1, newColor, oldColor);
            do_floodFill(image, sr, sc + 1, newColor, oldColor);

            return image;
        } else {
            return image;
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int newColor) {
        return do_floodFill(image, sr, sc, newColor, image[sr][sc]);
    }
};

class Solution2 {
   public:
    const vector<int> dx{1, 0, 0, -1};
    const vector<int> dy{0, 1, -1, 0};

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int newColor) {
        int oldColor = image[sr][sc];

        if (oldColor == newColor) {
            return image;
        }

        queue<pair<int, int>> que;

        image[sr][sc] = newColor;
        que.emplace(sr, sc);

        while (!que.empty()) {
            int ox = que.front().first;
            int oy = que.front().second;

            que.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = ox + dx[i];
                int ny = oy + dy[i];

                if (nx >= 0 && ny >= 0 && nx < image.size() &&
                    ny < image[0].size() && image[nx][ny] == oldColor) {
                    image[nx][ny] = newColor;
                    que.emplace(nx, ny);
                }
            }
        }

        return image;
    }
};

class Solution {
   public:
    const vector<int> dx{1, 0, 0, -1};
    const vector<int> dy{0, 1, -1, 0};

    vector<vector<int>> dfs(vector<vector<int>>& image,
                            int sr,
                            int sc,
                            int newColor,
                            int oldColor) {
        if (image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
        }

        for(int i=0;i<4;++i){
            int nx=sr+dx[i];
            int ny=sc+dy[i];

            if(nx>=0&&ny>=0&&nx<image.size()&&ny<image[0].size()&&image[nx][ny]==oldColor){
                dfs(image,nx,ny,newColor,oldColor);
            }
        }

        return image;
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int newColor) {
        if (image[sr][sc] == newColor) {
            return image;
        }

        return dfs(image, sr, sc, newColor, image[sr][sc]);
    }
};

int main() {
    vector<vector<int>> a = {{0, 0, 0}, {0, 1, 1}};
    Solution test;

    test.floodFill(a, 1, 1, 1);

    return 0;
}