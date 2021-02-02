import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Building {

	public static void main(String[] args) {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

		try {

			String[] line  = bf.readLine().split(" ");
			int a = Integer.parseInt(line[2]);
			int b = Integer.parseInt(line[3]);
			int k = Integer.parseInt(line[4]);		
			for(int i = 0; i < k; i++) {
				String[] query = bf.readLine().split(" ");
				int ta = Integer.parseInt(query[0]);
				int fa = Integer.parseInt(query[1]);
				int tb = Integer.parseInt(query[2]);
				int fb = Integer.parseInt(query[3]);

				if(ta == tb)
					System.out.println(Math.abs(fa - fb));
				else {
					if(fa < a) 
						System.out.println(a - fa + Math.abs(ta - tb) + Math.abs(a - fb));
					else if(fa > b) 
						System.out.println(fa - b + Math.abs(ta - tb) + Math.abs(b - fb));
					else
						System.out.println(Math.abs(fa - fb) + Math.abs(ta - tb));
				}
			}
		} catch (IOException e) {
			e.printStackTrace();	
		}
	}
}
