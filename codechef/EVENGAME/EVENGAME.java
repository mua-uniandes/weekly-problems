import java.util.Scanner;

public class Main {

    public static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int T = Integer.parseInt(in.nextLine());
        for (int i = 0; i < T; i++) {
            int N = Integer.parseInt(in.nextLine());
            int[] A = new int[N];
            String[] arr = in.nextLine().split(" ");
           int res = 0;
            for (int j = 0; j < N; j++) {
                A[j] = Integer.parseInt(arr[j]);
                res+=A[j];
            }
            if(res%2 == 0){
                System.out.println("1");
            }
            else
            {
                System.out.println("2");
            }
        }
    }
}