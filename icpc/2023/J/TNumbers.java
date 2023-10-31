import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class TNumbers {
	public static long a, b;	
	public static boolean fin = false;
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in),1024);
	public static String lineain, data[];

	public static void main(String[] args) throws IOException{
		lectura();
		while (!fin) {
			long r = 0;
			for (long n=a; n!=b+1; n++){
				double k = ((Math.sqrt((double)(2*n*(n+1)+1))-1)/2);
				if (!(k - Math.floor(k) > 0.0)) {
					//					System.out.println(n + " " + k);
					r++;
				}
			}
			//System.out.println();
			System.out.println(r);

			lectura();
		}
	}

	private static void lectura () throws IOException{
		lineain = br.readLine();
		data = lineain.split(" ");
		a = Long.parseLong(data[0]);
		b = Long.parseLong(data[1]);
		if (a==0 && b==0) {
			fin = true;
		}
	}
}
