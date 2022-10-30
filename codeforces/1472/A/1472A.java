import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int cant = Integer.parseInt(bf.readLine());
        ArrayList<String> arr = new ArrayList<>();

        for (int i = 0; i < cant; i++) {
            String[] str = bf.readLine().split(" ");
            int w = Integer.parseInt(str[0]);
            int h = Integer.parseInt(str[1]);
            int n = Integer.parseInt(str[2]);

            int cantSum = 1;
            while(w % 2 == 0)
            {
                w /= 2;
                cantSum *= 2;
            }

            int cantSum2 = 1;
            while(h % 2 == 0)
            {
                h /= 2;
                cantSum2 *= 2;
            }

            cantSum *= cantSum2;

            if(cantSum >= n)
                arr.add("YES");
            else
                arr.add("NO");
        }

        for (String s :
                arr) {
            System.out.println(s);
        }
    }
}