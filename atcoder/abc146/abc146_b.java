import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(bf.readLine());
        String S = bf.readLine(); 
        
        char[] arr = S.toCharArray();
        String msg = "";
        for(char i : arr){
            if(i+N > 90){
                int dif =(i+N - 90);
                i = (char)(64+dif);
            }
            else
                i+=N;
            
            msg+= i;
        }
        System.out.println(msg); 
        
    }
}