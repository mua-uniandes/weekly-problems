import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class extravaganza_edwin_AC {

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuffer buf = new StringBuffer();

    public static void main(String[] args) throws Exception {
        int N;
        char[] S;
        String ln = in.readLine();
        int tcnt=Integer.parseInt(ln);
        while (tcnt!=0) {
        // while (ln!=null && !ln.trim().equals("")) {
            ln = in.readLine();
            st = new StringTokenizer(ln);
            N = Integer.parseInt(st.nextToken());
            S = st.nextToken().toCharArray();
            int open=0, sol=0;
            for(int i=0; i<S.length;i++)
                if (S[i]=='(') open++;
                else if (open>0) {
                    open--;
                    sol+=2;
                }
            buf.append(sol+"\n");
            tcnt--;
        }
        System.out.print(buf);
    }
}
