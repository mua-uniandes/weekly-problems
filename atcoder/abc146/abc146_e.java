import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line = br.readLine().split(" ");
		int n = Integer.parseInt(line[0]);
		int k = Integer.parseInt(line[1]);
		int[] a = new int[n];
		String[] array = br.readLine().split(" ");
		for (int i = 0; i < n; i++)
		    a[i] = Integer.parseInt(array[i]) % k;
		long[] prefix = new long[n + 1];
		for (int i = 0; i < n; i++) {
		    prefix[i + 1] = prefix[i] + a[i];
		    
		}
		for (int i = 0; i <= n; i++) {
			prefix[i] = ((prefix[i] - i) % k + k) % k;
		}

		HashMap<Long, Integer> count = new HashMap<>();
		count.put(0L, 1);
		long answer = 0;
		for(int i = 1; i <= n; i++) {
		    if (i - k >= 0) {
		        count.merge(prefix[i - k], -1, Integer::sum);
		    }
		    answer += count.getOrDefault(prefix[i], 0);
		    count.merge(prefix[i], 1, Integer::sum);
		}
		System.out.println(answer);
	}
}
