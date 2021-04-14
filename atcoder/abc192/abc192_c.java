import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        String[] data = bf.readLine().split(" ");

        int k = Integer.parseInt(data[1]);
        for (int i = 0; i < k; i++) {
            String a = data[0];
            char[] chars = a.toCharArray();
            Arrays.sort(chars);
            a = new String(chars);
            StringBuilder b = new StringBuilder(new String(chars));
            b.reverse();

            data[0] = String.valueOf((Integer.parseInt(b.toString()) - Integer.parseInt(a)));
        }

        System.out.println(data[0]);
    }
}