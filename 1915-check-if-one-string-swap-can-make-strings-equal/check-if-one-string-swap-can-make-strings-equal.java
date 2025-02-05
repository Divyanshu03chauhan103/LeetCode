class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        
         int n = s1.length();

        if (n != s2.length()) return false; // Length mismatch

        int firstIndex = -1, secondIndex = -1, mismatchCount = 0;

        for (int i = 0; i < n; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                mismatchCount++;

                if (firstIndex == -1) 
                    firstIndex = i;
                else if (secondIndex == -1) 
                    secondIndex = i;
                else 
                    return false; // More than two mismatches
            }
        }

        // If no mismatch, strings are already equal
        if (mismatchCount == 0) return true;

        // If only one mismatch, it's impossible to swap -> return false
        if (mismatchCount != 2) return false;

        // Swap and check if they become equal
        char[] s1Array = s1.toCharArray();
        char temp = s1Array[firstIndex];
        s1Array[firstIndex] = s1Array[secondIndex];
        s1Array[secondIndex] = temp;

        return new String(s1Array).equals(s2);//creating a new string object
    }
}