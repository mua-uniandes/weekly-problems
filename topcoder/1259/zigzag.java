public class ZigZag {
    public int longestZigZag(int[] sequence) {
        int n = sequence.length;

        int[][] z = new int[n][2];
        z[0][0] = z[0][1] = 1;

        int best = 1;

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (sequence[j] < sequence[i])
                    z[i][0] = Math.max(z[j][1] + 1, z[i][0]);
                else if (sequence[j] > sequence[i])
                    z[i][1] = Math.max(z[j][0] + 1, z[i][1]);
            }
            best = Math.max(best, Math.max(z[i][0], z[i][1]));
        }
        return best;
    }
}
