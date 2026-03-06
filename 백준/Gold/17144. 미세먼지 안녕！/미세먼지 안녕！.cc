#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int R, C, T;
int board[50][50];
int next_board[50][50] = {0};
int airconx1, airconx2;
vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

//Top circulation
vector<pair<int,int>> top_air_dir = {{-1,0}, {0,1}, {1,0}, {0,-1}};

//Bottom circulation
vector<pair<int,int>> bottom_air_dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

bool isValid(int r, int c) {
    if (c == 0 && (r == airconx1 || r == airconx2)) return false;
    if (0 <= r && r < R && 0 <= c && c < C) return true;
    return false;
}

//so that the cycle only goes on for the top half
bool topIsValid(int r, int c) {
    if (c == 0 && (r == airconx1 || r == airconx2)) return false;
    if (0 <= r && r <= airconx1 && 0 <= c && c < C) return true;
    return false;
}

bool bottomIsValid(int r, int c) {
    if (c == 0 && (r == airconx1 || r == airconx2)) return false;
    if (airconx2 <= r && r < R && 0 <= c && c < C) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> R >> C >> T;
    for (int i = 0; i < R; ++i) {
        for (int j = 0;  j < C; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < R; ++i) {
        if (board[i][0] == -1) {
            airconx1 = i;
            airconx2 = i+1;
            break;
        }
    }

    int total_count = 0;
    while (T--) {
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (board[i][j] > 0) {
                    int count = 0;
                    for (auto [dir1, dir2] : dir) {
                        if (!isValid(i+dir1, j+dir2)) continue;
                        next_board[i+dir1][j+dir2] += board[i][j]/5;
                        count++;
                    }
                    next_board[i][j] -= (board[i][j]/5)*count;
                }
            }
        }
        
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                board[i][j] += next_board[i][j];
                next_board[i][j] = 0;
            }
        }

        //starts from above aircon, and "pulls" from the next node.
        int currx = airconx1-1;
        int curry = 0;

        for (int i = 0; i < 4; ++i) {
            auto [xdir, ydir] = top_air_dir[i];
            while (true) {
                if (!topIsValid(currx + xdir, curry + ydir)) break;
                //"pulls"
                board[currx][curry] = board[currx + xdir][curry + ydir];
                currx = currx + xdir;
                curry = curry + ydir;
            }
        }
        
        currx = airconx2+1;
        curry = 0;

        for (int i = 0; i < 4; ++i) {
            auto [xdir, ydir] = bottom_air_dir[i];
            while (true) {
                if (!bottomIsValid(currx + xdir, curry + ydir)) break;
                board[currx][curry] = board[currx + xdir][curry + ydir];
                currx = currx + xdir;
                curry = curry + ydir;
            }
        }
        
        board[airconx1][0] = -1;
        board[airconx2][0] = -1;
        board[airconx1][1] = 0;
        board[airconx2][1] = 0;
        
        fill(&next_board[0][0], &next_board[0][0] + 50*50, 0);
    }
    
    for (int i = 0; i < R; ++i) {
        for (int j = 0;  j < C; ++j) {
            total_count += board[i][j];
        }
    }
    
    //accounts for the airconditioner
    cout << total_count + 2;
    return 0;
}