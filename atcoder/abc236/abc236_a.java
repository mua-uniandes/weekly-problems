package atcoder;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    //problem abc236_a
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader());
        char[] s = br.readLine().toCharArray();
        String[] nums = br.readLine().split(" ");
        int a = Integer.parseInt(nums[0]);
        int b = Integer.parseInt(nums[1]);
        char temp = s[a-1];

        s[a-1] = s[b-1];
        s[b-1] = temp;
        System.out.println(s.toString());
    }
}
