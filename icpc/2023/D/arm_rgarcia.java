//Code by Rafael Garcia
import java.io.BufferedReader;
//import java.io.File;
import java.io.InputStreamReader;
//import java.io.PrintStream;

public class arm_rgarcia {
	
//	public static StringBuffer out;
	
	public static void main(String[] args) throws Throwable {
	    try (BufferedReader reader=new BufferedReader(new InputStreamReader(System.in))) {
	    	
//	    	out = new StringBuffer();
	    	
	    	while (true) {
	    		String line = reader.readLine();
		    	String data[] = line.split(" ");
		    	int N = Integer.parseInt(data[0]);
		    	int m = Integer.parseInt(data[1]);
		    	if (N==0) break;
		    	else {
		    		long R = 0L;
			    	long s = 0L;
			    	long lM = 0L;
			    	long d = 0L;
			    	data = reader.readLine().split(" ");
			    	for (int j=0; j<N; j++) {
			    		d = Long.parseLong(data[j]);
			    		lM = Math.max(lM,d);
			    		R = R+d;
			    	}
			    	s = R - lM;
			    	long r = lM <= s?0L:lM-s;
			    	
			    	for (int i=0; i<m; i++) {
			    		data = reader.readLine().split(" ");
						long xi = Long.parseLong(data[0]);
						long yi = Long.parseLong(data[1]);
						double l = Math.sqrt(xi*xi+yi*yi);
						System.out.println((r <= l && l <= R)?"Y":"N");
//						out.append(((r <= l && l <= R)?"Y":"N")+"\n");
			    	}	
		    	}
	    	}
	    	
//	    	PrintStream o = new PrintStream(new File("arm.out"));
//			PrintStream console = System.out;
//			System.setOut(o);
//			System.out.print(out);
//			System.setOut(console);
//			System.out.print(out);
	    	
	    }
	  }
	
}




