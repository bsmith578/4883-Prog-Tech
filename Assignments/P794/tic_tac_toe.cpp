class Solution {
public:
    void checkWinners(vector<string>& b, bool& xw, bool& ow) {
        //Top Left to Bottom Right Diagonal
        if(b[0][0] == 'X' && b[0][0] == b[1][1] && b[1][1] == b[2][2])
            xw = true;
        
        if(b[0][0] == 'O' && b[0][0] == b[1][1] && b[1][1] == b[2][2])
            ow = true;

        //Top Right to Bottom Left Diagonal
        if(b[0][2] == 'X' && b[0][2] == b[1][1] && b[1][1] == b[2][0])
            xw = true;

        if(b[0][2] == 'O' && b[0][2] == b[1][1] && b[1][1] == b[2][0])
            ow = true;

        //Rows
        for(const string& s : b) {
            if(s[0] == 'X' && s[0] == s[1] && s[1] == s[2])
                xw = true;
            
            if(s[0] == 'O' && s[0] == s[1] && s[1] == s[2])
                ow = true;
        }

        //Columns
        for(int i = 0; i < 3; i++) {
            if(b[0][i] == 'X' && b[0][i] == b[1][i] && b[1][i] == b[2][i])
                xw = true;

            if(b[0][i] == 'O' && b[0][i] == b[1][i] && b[1][i] == b[2][i])
                ow = true;
        }
    }

    bool validTicTacToe(vector<string>& board) {
        int x = 0, o = 0;
        bool x_win = false, o_win = false;

        //Count the number of X's and O's on the board
        for(const string& s : board) {
            for(char c : s) {
                if(c == 'X')
                    x++;
                
                else if(c == 'O')
                    o++;
            }
        }

        //Since X goes first, there should not be more O's than X's
        //And X should never have more than one extra space than O
        if(o > x || x - o > 1)
            return false;

        //Check the board for any winners
        checkWinners(board, x_win, o_win);

        //X and O cannot both win at the same time
        if(x_win && o_win)
            return false;

        //If X wins, it cannot have more than one extra space than O
        if(x_win && x - o != 1)
            return false;

        //If O wins, there has to be the exact same number of X's
        if(o_win && o != x)
            return false;
        
        return true;
    }
};