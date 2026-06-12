class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;   // write pointer
        int i = 0;       // read pointer

        while (i < n) {
            char current = chars[i];
            int count = 0;

            // Count consecutive characters
            while (i < n && chars[i] == current) {
                count++;
                i++;
            }

            // Write the character
            chars[index++] = current;

            // Write the count if greater than 1
            if (count > 1) {
                string cnt = to_string(count);

                for (char ch : cnt) {
                    chars[index++] = ch;
                }
            }
        }

        return index;
    }
};
