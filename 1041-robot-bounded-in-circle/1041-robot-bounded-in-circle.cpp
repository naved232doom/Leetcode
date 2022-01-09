class Solution {
private:
    void rotate_left(int &dx, int &dy) {
        if (dx == -1) {
            swap(dx, dy);
        }
        else if (dx == 1) {
            swap(dx, dy);
        }
        else if (dy == 1) {
            dx = -1;
            dy = 0;
        }
        else {
            dx = 1;
            dy = 0;
        }

    }
    void rotate_right(int &dx, int &dy) {
        if (dx == 1) {
            dy = -1;
            dx = 0;
        }
        else if (dx == -1) {
            dy = 1;
            dx = 0;
        }
        else if (dy == 1) {
            dx = 1;
            dy = 0;
        }
        else {
            dx = -1;
            dy = 0;
        }
    }
public:
    bool isRobotBounded(string s) {
        int x = 0, y = 0;
        int dx = 0, dy = 1;
        string S = "";
        for (int i = 0; i < 4; ++i) {
            S += s;
        }
        int n = S.length();
        int x_here = 0, y_here = 0;
        for (int i = 0; i < n; ++i) {
            if (S[i] == 'L') {
                rotate_left(dx, dy);
            }
            else if (S[i] == 'R') {
                rotate_right(dx, dy);
            }
            else {
                x_here += dx;
                y_here += dy;
            }

        }

        return (x_here == 0 && y_here == 0);
    }
};