class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int l = 0, r = 0, ans = 0;

        Map<Character, Integer> mp = new HashMap<>();
        
        while (r < n) {
            char currentChar = s.charAt(r);

            if (!mp.containsKey(currentChar) || mp.get(currentChar) < l) {
                ans = Math.max(ans, r - l + 1);
                mp.put(currentChar, r);
            } else {
                l = mp.get(currentChar) + 1;
                mp.put(currentChar, r);
                ans = Math.max(ans, r - l + 1);
            }
            r++;
        }
        
        return ans;
    }
}