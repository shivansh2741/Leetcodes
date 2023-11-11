public class Solution {
    public int minChanges(String s) {
        int n = s.length();
        int count = 0;
        int i = 0;

        while (i < n) {
            if (s.charAt(i) != s.charAt(i + 1)) {
                count++;
            }
            i += 2;
        }
        return count;
    }
}
