import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class stacks_edwin_dp_n2_AC {

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuffer buf = new StringBuffer();

    static int N;
    static long[] A, S;
    static long[][] M;
    static int[][] opt; 
    static final long INF = 1000000000000L;

    static long cost(int i, int j) {
        if (i==0) return S[j];
        return S[j]-S[i-1];
    }

    static void solve() {
        M = new long[N][N];
        opt = new int[N][N];
        for (int i = 0; i < N; i++) M[i][i] = 0;
        for (int i = 0; i < N; i++) opt[i][i] = i;
        for (int l = 1; l < N; l++){
            for (int i = 0; i < N-l; i++) {
                int j = i+l;
                long res = INF;
                for (int k = opt[i][j-1]; k < Math.min(j, opt[i+1][j] + 1); k++) {
                    if (res > M[i][k] + M[k+1][j]) {
                        res = M[i][k] + M[k+1][j];
                        opt[i][j] = k;
                    }
                    M[i][j] = res + cost(i, j);
                }
            }
        }
        buf.append(M[0][N-1] + "\n");
    }
    public static void main(String[] args) throws Exception {
        while (true) {
            N = Integer.parseInt(in.readLine());
            if (N==0) break;
            A = new long[N];
            S = new long[N];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < N; i++) 
                A[i] = Integer.parseInt(st.nextToken());
            S[0] = A[0];
            for (int i = 1; i < N; i++) 
                S[i] = S[i-1]+A[i];
            solve();
        }    
        System.out.print(buf);
    }

}
