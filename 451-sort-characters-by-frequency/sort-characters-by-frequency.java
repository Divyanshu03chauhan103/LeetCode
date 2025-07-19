import java.util.*;

class Pair {
    char a;
    int b;
    Pair(char a, int b) {
        this.a = a;
        this.b = b;
    }
}

class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> mp = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            mp.put(ch, mp.getOrDefault(ch, 0) + 1);
        }

        List<Pair> ls = new ArrayList<>();
        for (Map.Entry<Character, Integer> entry : mp.entrySet()) {
            ls.add(new Pair(entry.getKey(), entry.getValue()));
        }

        ls.sort((a, b) -> b.b - a.b);

        StringBuilder sb = new StringBuilder();
        for (Pair p : ls) {
            for (int i = 0; i < p.b; i++) {
                sb.append(p.a);
            }
        }

        return sb.toString();
    }
}
