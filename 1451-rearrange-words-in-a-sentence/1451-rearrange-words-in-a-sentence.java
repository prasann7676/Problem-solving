class Solution {
    public String arrangeWords(String txt) {
        StringBuilder text = new StringBuilder(txt);
        char tmp = text.charAt(0);
        tmp = Character.toLowerCase(tmp);
        text.setCharAt(0,tmp);
        String arr[] = text.toString().split(" ");
        int n = arr.length;
        List<int[]> l = new ArrayList<int[]>();
        for(int i=0;i<n;i++){
            int len = arr[i].length();
            int[] tmpp = new int[2];
            tmpp[0]=len;
            tmpp[1]=i;
            l.add(tmpp);
        }
        Collections.sort(l,new Comparator<int[]>(){
            public int compare(int[] x, int[] y){
                if(x[0]==y[0])
                    return Integer.compare(x[1],y[1]);
                return Integer.compare(x[0],y[0]);
            }
        });
        StringBuilder ans = new StringBuilder();
        for(int i=0;i<n;i++){
            ans.append(arr[l.get(i)[1]]);
            ans.append(" ");
        }
        tmp = ans.charAt(0);
        tmp = Character.toUpperCase(tmp);
        ans.setCharAt(0,tmp);
        String ans1 = ans.toString().substring(0,ans.length()-1);
        return ans1;
    }
}