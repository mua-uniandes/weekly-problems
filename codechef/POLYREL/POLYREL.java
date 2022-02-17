
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class POLYREL {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases = Integer.parseInt(br.readLine());
		for(int i=0; i<cases; i++) {
			int vertices = Integer.parseInt(br.readLine());
			int answer = vertices;
			for(int j=0; j<vertices; j++) 
				br.readLine();
			while(vertices >= 6) {
				vertices = (int)Math.floor(vertices/2);
				answer += vertices;
			}
			System.out.println(answer);
		}
	}
}
