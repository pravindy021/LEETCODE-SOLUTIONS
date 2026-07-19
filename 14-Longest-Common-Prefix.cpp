class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the array is empty, return an empty string
        if (strs.empty()) {
            return "";
        }

        // Assume the first string is the common prefix
        string prefix = strs[0];

        // Compare the prefix with each remaining string
        for (int i = 1; i < strs.size(); i++) {

            // Keep shortening the prefix until it matches
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);

                // If the prefix becomes empty, no common prefix exists
                if (prefix.empty()) {
                    return "";
                }
            }
        }

        return prefix;
    }
};