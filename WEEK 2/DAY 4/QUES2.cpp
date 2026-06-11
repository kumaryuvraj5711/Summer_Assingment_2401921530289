class Solution {
public:
    string solve(string &s, int &i) {
        string ans = "";
        int n = s.length();

        while (i < n && s[i] != ']') {

            if (isalpha(s[i])) {
                ans += s[i];
                i++;
            }
            else if (isdigit(s[i])) {

                int num = 0;

                // Form the complete number
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                i++;   // Skip '['

                string temp = solve(s, i);

                i++;   // Skip ']'

                while (num--) {
                    ans += temp;
                }
            }
        }

        return ans;
    }

    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
};
