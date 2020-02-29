// Based on Rolling Hash 
// Here only 26 alphabets are considered
class Solution {
public:
    int strStr(string haystack, string needle) {
        int needleLen = needle.size();
        int haystackLen = haystack.size();
        if(needleLen > haystackLen) {
            return -1;
        }
        long hash_needle = 0, hash_window = 0;
        long aL = 1;
        int MOD = INT_MAX;
        int a = 26;
        for (int i = 0; i < needleLen; i++) {
            hash_needle = ((a * hash_needle) + (needle[i]-'a'))%MOD;
            hash_window = ((a * hash_window) + (haystack[i]-'a'))%MOD;
        }
        if(hash_needle == hash_window) {
            return 0;
        }
        for (int i = 1; i <= needleLen; i++) {
            aL = (aL*a)%MOD;
        }
        for (int start = 1; start < haystackLen-needleLen + 1; start++) {
            hash_window = ((hash_window * a) - (haystack[start - 1]-'a') * aL +( haystack[start + needleLen - 1]-'a')) % MOD;
            if(hash_window == hash_needle) {
                return start;
            }
        }
        return -1;
    }
};
