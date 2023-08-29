//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class Item {
    int value, weight;
    Item(int x, int y){
        this.value = x;
        this.weight = y;
    }
}

class GfG {
    
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
            String inputLine[] = br.readLine().trim().split(" ");
            int n = Integer.parseInt(inputLine[0]);
            int w = Integer.parseInt(inputLine[1]);
            Item[] arr = new Item[n];
            inputLine = br.readLine().trim().split(" ");
            for(int i=0, k=0; i<n; i++){
                arr[i] = new Item(Integer.parseInt(inputLine[k++]), Integer.parseInt(inputLine[k++]));
            }
            System.out.println(String.format("%.2f", new Solution().fractionalKnapsack(w, arr, n)));
        }
    }
}
// } Driver Code Ends


/*
class Item {
    int value, weight;
    Item(int x, int y){
        this.value = x;
        this.weight = y;
    }
}
*/

class Solution
{
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) 
    {
        // Your code here
        double ans = 0.00;
        List<double[]> a = new ArrayList<double[]>();
        for(int i=0;i<n;i++){
            double[] tmp = new double[3];
            tmp[0] = ((double)arr[i].value/arr[i].weight);
            tmp[1] = arr[i].value;
            tmp[2] = arr[i].weight;
            a.add(tmp);
        }
        Collections.sort(a,(x,y) -> Double.compare(y[0],x[0]));
        int cur = 0;
        for(int i=0;i<n;i++){
            if(cur+a.get(i)[2] > W){
                double val = a.get(i)[0]*(W-cur);
                ans += val;
                break;
            }
            else{
                ans += a.get(i)[1];
                cur += a.get(i)[2];
            }
                
        }
        return ans;
        
    }
}