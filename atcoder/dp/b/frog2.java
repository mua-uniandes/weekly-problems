import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] jumps = new int[n];
        int k = sc.nextInt();
        for (int i = 0; i < n; i++) {
            jumps[i] = sc.nextInt();
        }
        int[] bottomUp = new int[n];
        bottomUp[0] = 0;
        for (int i = 1; i < n; i++) {
            int ans = 1000000000;
            for (int j = Math.max(0, i - k); j < i; j++) {
                ans = Math.min(bottomUp[j] + Math.abs(jumps[i] - jumps[j]), ans);
            }
            bottomUp[i] = ans;
        }
        System.out.println(bottomUp[n - 1]);
        sc.close();
    }
}