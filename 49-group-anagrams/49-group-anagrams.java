class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> mp = new HashMap<>();
        int n = strs.length;
        for (int i = 0; i < n; ++i) {
            char charsHere[] = strs[i].toCharArray();
            Arrays.sort(charsHere);
            String keyHere = String.valueOf(charsHere);
            if (!mp.containsKey(keyHere)) mp.put(keyHere, new ArrayList<>());
            mp.get(keyHere).add(strs[i]);
        }
        return new ArrayList<>(mp.values());
    }
}