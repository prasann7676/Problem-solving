class Solution {
    public String sortSentence(String s) {
        int n = s.length();
        String ans = "", cur="";
        TreeMap<Integer,String> mp = new TreeMap<Integer,String>();
        for(int i=0;i<n;i++){
            char p = s.charAt(i);
            if(p>='1' && p<='9'){
                Integer tmp = (Integer)(p-'0');
                mp.put(tmp,cur);
                cur="";
                i++;
            }
            else
                cur += p;
        }
        for(Map.Entry<Integer,String> p: mp.entrySet()){
            ans += p.getValue();
            ans += " ";
        }
        ans = ans.substring(0,ans.length()-1);
        return ans;
    }
}