class Solution {
public:
    bool isPalindrome(string s) {
        string letters;

        if(s.size() == 1)
            return true;

        if(s.size() < 4 && s[0] == s.back())
            return true;

        for(char c : s) {
            if(isalnum(c))
                letters += tolower(c);
        }

        cout << letters;

        int i = 0, j = letters.size() - 1;

        while(i <= j) {
            if(letters[i] == letters[j]) {
                i++;
                j--;
            }

            else
                return false;
        }

        return true;
    }
};