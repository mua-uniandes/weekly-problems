import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class RelationalOperator {
	public static void main(String[] args) {
	    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
	    try {
	        int line  = Integer.parseInt(bf.readLine());
	        String[] l = new String[2];
	        for(int i=0; i< line; i++) {
	        	l = bf.readLine().split(" ");
	        	int z = Integer.parseInt(l[0]); 
	        	int o = Integer.parseInt(l[1]);
	        	if(z < o ) {
	        		System.out.println("<");
	        	} else if(z > o) {
	        		System.out.println(">");
	        	} else
	        		System.out.println("=");
	        }  
	    } catch (IOException e) {
	        e.printStackTrace();
	    }
	  }
}
