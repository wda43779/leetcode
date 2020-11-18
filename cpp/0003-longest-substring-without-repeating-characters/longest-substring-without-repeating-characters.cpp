class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
      int pre[256] {0}; // previous appeare
      int start = 0; // start and end of a passible maximum substring
      int end = 0;
      
      int max = 0;
      for (int end = 1; end <= s.size(); end++) {
          if (pre[s[end - 1]] >= start) {
              start = pre[s[end - 1]];
          }
          pre[s[end - 1]] = end;
          max = (end - start) > max ? (end - start) : max;
      }
      return max;
  }
};
