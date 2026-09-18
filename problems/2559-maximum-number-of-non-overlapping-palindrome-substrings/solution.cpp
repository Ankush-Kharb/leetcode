class Solution {
public:
    bool valid(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {
        int count = 0;
        int i = 0;

        while (i + k <= s.size()) {

            bool found = false;

            // j = ending position
            for (int j = i + k - 1; j < s.size(); j++) {

                // Try every possible starting position
                // for this ending position.
                for (int start = i; start <= j - k + 1; start++) {

                    string sub = s.substr(start, j - start + 1);

                    if (valid(sub)) {
                        count++;

                        // Start searching after this palindrome
                        i = j + 1;

                        found = true;
                        break;
                    }
                }

                if (found)
                    break;
            }

            if (!found)
                break;
        }

        return count;
    }
};