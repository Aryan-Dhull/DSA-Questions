class Solution {
    public boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        String a="";
        String b="";
        for(String c:word1){a+=c;}
        for(String c:word2){b+=c;}
        return a.equals(b);
    }
}