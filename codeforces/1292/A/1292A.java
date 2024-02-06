import java.io.*;
import java.util.*;

public class Akisolution {
	public static Scanner sc = new Scanner(System.in);
	public static PrintWriter out = new PrintWriter(System.out, true);
	public static int n, q;
	public static int[][] lava;

	public static void Input() {
		n = sc.nextInt(); q = sc.nextInt();
		lava = new int[2][n];
	}

	public static void Solve() {
		int blockedPair = 0;
		while (q-- > 0) {
			int x = sc.nextInt() - 1, y = sc.nextInt() - 1;
			int delta = (lava[x][y] == 0) ? +1 : -1;

			lava[x][y] = 1 - lava[x][y];
			for (int dy=-1; dy<=1; dy++) {
				if (y+dy < 0 || y+dy >= n) continue;

				if (lava[1-x][y+dy] == 1) blockedPair += delta;
			}

			if (blockedPair == 0) out.println("Yes");
			else out.println("No");
		}
	}

	public static void main(String[] args) {
		Input(); Solve();
	}
}