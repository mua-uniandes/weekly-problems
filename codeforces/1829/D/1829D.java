import java.util.*;
/**
    @author: ddi4z
*/
public class Main {
    static Map<Long, Boolean> dp = new HashMap<>();
    static Set<Long> visited = new HashSet<>();

    static boolean solve(long n, long m) {
        if (n == m) return true;
        if (n < m) return false;

        if (visited.contains(n)) return dp.get(n);
        visited.add(n);
        dp.put(n, false);

        if (n % 3 == 0) {
            dp.put(n, dp.get(n) || solve(n / 3, m));
            dp.put(n, dp.get(n) || solve(2 * n / 3, m));
        }
        return dp.get(n);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        long t = sc.nextLong();
        while (t-- > 0) {
            long n = sc.nextLong();
            long m = sc.nextLong();
            dp.clear();
            visited.clear();

            if (solve(n, m)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        sc.close();
    }
}
