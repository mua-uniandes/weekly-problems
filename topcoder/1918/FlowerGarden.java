public class FlowerGarden {
    public int[] getOrdering(int[] height, int[] bloom, int[] wilt) {
        int len = height.length;
        if (len == 0) return height; 
        int[] ret = new int[len];
        boolean[] used = new boolean[len];

        for (int i = 0; i < len; i++) {
            int mxH = 0;
            int pos = -1;

            for (int j = 0; j < len; j++) {
                if (used[j]) continue;
                boolean found = true;
                for (int k = 0; k < len; k++) {
                    if (used[k]) continue;
                    boolean blocking = !(bloom[j] > wilt[k] || bloom [k] > wilt[j]);
                    if (height[j] > height[k] && blocking) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    if (height[j] > mxH) {
                        mxH = height[j];
                        pos = j;
                    }
                }
            }
            ret[i] = height[pos];
            used[pos] = true;
        }
        return ret;
    }
}
