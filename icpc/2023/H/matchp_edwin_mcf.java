import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class matchp_edwin_mcf {

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringBuffer buf = new StringBuffer();
    static StringTokenizer st;
    static int N;
    static int[] x, y, u, v;
    static double[][] D;

    static void calc_dist() {
        D = new double[N][N];
        for (int i = 0; i < N; i++) 
            for (int j = 0; j < N; j++) 
                D[i][j] = Math.sqrt((x[i]-u[j])*(x[i]-u[j]) + (y[i]-v[j])*(y[i]-v[j]));
    }

    static double solve() {
        int n = N*2 + 2;
        double[][] F = new double[n][n];
        int s = n-2, t = n-1;
        double cost = 0;
        while (true) {
            double[] dist = new double[n];
            Arrays.fill(dist, Double.POSITIVE_INFINITY);
            int[] pred = new int[n];
            Arrays.fill(pred, -1);
            boolean[] vis = new boolean[n];
            Queue<Integer> Q = new LinkedList<>();
            dist[s] = 0;
            Q.offer(s);
            while (!Q.isEmpty()) {
                int v = Q.poll();
                vis[v] = false;
                if (v == s) {
                    for (int i = 0; i < N; ++i)
                        if (F[s][i] == 0) {
                            dist[i] = 0;
                            pred[i] = s;
                            vis[i] = true;
                            Q.offer(i);
                        }
                } else {
                    if (v < N) {
                        for (int j = N; j < N + N; ++j)
                            if (F[v][j] < 1 && dist[j] > dist[v] + D[v][j - N]) {
                                dist[j] = dist[v] + D[v][j - N];
                                pred[j] = v;
                                if (!vis[j]) {
                                    Q.offer(j);
                                    vis[j] = true;
                                }
                            }
                    } else {
                        for (int j = 0; j < N; ++j)
                            if (F[v][j] < 0 && dist[j] > dist[v] - D[j][v - N]) {
                                dist[j] = dist[v] - D[j][v - N];
                                pred[j] = v;
                                if (!vis[j]) {
                                    Q.offer(j);
                                    vis[j] = true;
                                }
                            }
                    }
                }
            }
            double curcost = Double.POSITIVE_INFINITY;
            for (int i = N; i < N + N; ++i) {
                if (F[i][t] == 0 && dist[i] < curcost) {
                    curcost = dist[i];
                    pred[t] = i;
                }
            }
            if (Double.isInfinite(curcost))
                break;
            cost += curcost;
            for (int cur = t; cur != -1; cur = pred[cur]) {
                int prev = pred[cur];
                if (prev != -1)
                    F[cur][prev] = -(F[prev][cur] = 1);
            }
        }
        return cost;
    }

    public static void main(String[] args) throws Exception {
        while (true) {
            N = Integer.parseInt(in.readLine());
            if (N==0) break;
            x = new int[N];
            y = new int[N];
            u = new int[N];
            v = new int[N];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < N; i++) {
                x[i] = Integer.parseInt(st.nextToken());
                y[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < N; i++) {
                u[i] = Integer.parseInt(st.nextToken());
                v[i] = Integer.parseInt(st.nextToken());
            }
            calc_dist();
            System.out.printf("%.3f\n", solve());
        }
    }
}