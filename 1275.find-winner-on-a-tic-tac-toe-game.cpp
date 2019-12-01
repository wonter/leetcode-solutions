class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        char grids[9][9];
        memset(grids, '*', sizeof(grids));

        int now = 0;
        for (const auto& move : moves) {
            if (now == 0) {
                grids[move[0]][move[1]] = 'A';
            } else {
                grids[move[0]][move[1]] = 'B';
            }
            now ^= 1;
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << grids[i][j];
            }
            cout << endl;
        }

        bool awin = false;
        bool bwin = false;
        for (int i = 0; i < 3; ++i) {
            if (grids[i][0] == grids[i][1] && grids[i][1] == grids[i][2]) {
                if (grids[i][0] == 'A') {
                    awin = true;
                }
                if (grids[i][0] == 'B') {
                    bwin = true;
                }
            }
            if (grids[0][i] == grids[1][i] && grids[1][i] == grids[2][i]) {
                if (grids[0][i] == 'A') {
                    awin = true;
                }
                if (grids[0][i] == 'B') {
                    bwin = true;
                }
            }
        }
        if (grids[0][0] == grids[1][1] && grids[1][1] == grids[2][2]) {
            if (grids[0][0] == 'A') {
                awin = true;
            }
            if (grids[0][0] == 'B') {
                bwin = true;
            }
        }
        if (grids[0][2] == grids[1][1] && grids[1][1] == grids[2][0]) {
            if (grids[0][2] == 'A') {
                awin = true;
            }
            if (grids[0][2] == 'B') {
                bwin = true;
            }
        }

        if (awin && bwin) {
            return "Draw";
        } else if (awin) {
            return "A";
        } else if (bwin) {
            return "B";
        } else {
            if (moves.size() == 9) {
                return "Draw";
            } else {
                return "Pending";
            }
        }
    }
};