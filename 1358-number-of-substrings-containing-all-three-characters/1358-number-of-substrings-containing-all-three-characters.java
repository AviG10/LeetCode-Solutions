class Solution {
    public int numberOfSubstrings(String s) {
        int n = s.length();
        Map<Character, Integer> lastSeen = new HashMap<>();
        int i = 0;
        int ans = 0;

        while(i < n){
            lastSeen.put(s.charAt(i), i);

            if(lastSeen.size() == 3)
                ans += (1 + Math.min(lastSeen.get('a'), Math.min(lastSeen.get('b'), lastSeen.get('c'))));

            i++;
        }

        return ans;
    }
}