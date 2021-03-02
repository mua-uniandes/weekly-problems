import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line = br.readLine().split(" ");
		int n = Integer.parseInt(line[0]);
		int m = Integer.parseInt(line[1]);
		char[] inputS = br.readLine().toCharArray(); // len n+1
		boolean[] s = new boolean[n + 1];
		for(int i = 0; i < n; i++) {
			s[i] = inputS[i] == '1';
		}

		Deque<Integer> answer = new ArrayDeque<Integer>();

		int cur = n;
		int last = Integer.MAX_VALUE;
		outer:
			while(cur > 0) {
				for(int i = Math.max(0, cur - m); i < cur && i < last - m; i++) {
					if(!s[i]) {
						answer.addFirst(cur - i);
						last = cur;
						cur = i;
						continue outer;
					}
				}
				System.out.println(-1);
				return;
			}
		for (Iterator<Integer> it = answer.iterator(); 
				it.hasNext();) { 
			System.out.print(it.next() + " "); 
		} 
	}
}
