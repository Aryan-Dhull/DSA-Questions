class Solution {
    public void reverseString(char[] s) {
        for(int i=0;i<s.length/2;i++){
            char p1=s[i];
            char p2=s[s.length-1-i];
            s[i]=p2;
            s[s.length-1-i]=p1;
        }
        
    }
}