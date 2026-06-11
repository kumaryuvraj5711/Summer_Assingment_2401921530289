class Solution {
public:
    void reverseWord(string &s, int left, int right) {
        // Base case
        if (left >= right)
            return;

        swap(s[left], s[right]);

        // Recursive call
        reverseWord(s, left + 1, right - 1);
    }

    string reverseWords(string s) {
        int start = 0;

        for (int i = 0; i <= s.length(); i++) {
            if (i == s.length() || s[i] == ' ') {
                reverseWord(s, start, i - 1);
                start = i + 1;
            }
        }

        return s;
    }
};
