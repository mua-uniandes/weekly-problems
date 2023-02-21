//make sure to make new file!
import java.io.*;
import java.util.*;
 
public class OmkarAndHeavenlyTreeSolution{
   
   public static void main(String[] args)throws IOException{
      BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter out = new PrintWriter(System.out);
      
      int t = Integer.parseInt(f.readLine());
      
      for(int q = 1; q <= t; q++){
      
         StringTokenizer st = new StringTokenizer(f.readLine());
      
         int n = Integer.parseInt(st.nextToken());
         int m = Integer.parseInt(st.nextToken());
      
         HashSet<Integer> hset = new HashSet<Integer>();
         for(int k = 0; k < m; k++){
            st = new StringTokenizer(f.readLine());
         
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
         
            hset.add(b);
         }
      
         int middle = -1;
         for(int k = 1; k <= n; k++){
            if(!hset.contains(k)){
               middle = k;
               break;
            }
         }
      
         for(int k = 1; k <= n; k++){
            if(k == middle) 
               continue;
            out.println(k + " " + middle);
         }
      
      }      
      out.close();
   }
   
      
}

