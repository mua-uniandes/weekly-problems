import java.util.Scanner;

public class Main {

    public static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        String rta = in.nextLine();
        int n = Integer.parseInt(rta);
        int[] a = new int[n];
        int[] f = new int[n];
        rta = in.nextLine();
        String[] ar = rta.split(" ");
        for (int i = 0; i < ar.length; i++) {
            a[i] = Integer.parseInt(ar[i]);
        }
        int v = 0;
        for (int i = 0; i+1 < a.length; i++) {
            int x = i==0? 0 : f[i-1];
            if(2*a[i] >= a[i+1]){
                f[i]=x+1;
                if(v<x+1)
                    v = x+1;
            }
            else
                f[i]=0;
        }
        System.out.println(v+1);
        in.close();
    }
}