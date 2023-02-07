import java.util.Scanner;

public class Main {

    public static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        String rta = in.nextLine();
        int n = Integer.parseInt(rta.split(" ")[0]);
        int k = Integer.parseInt(rta.split(" ")[1]);
        rta = in.nextLine();
        String t = "";
        int j = 1;
        int x = 0;
        while(j!=n){
            String b = rta.substring(0, j);
            String a = rta.substring(n-j);
            if(rta.substring(0, j).equals(rta.substring(n-j))){
                x = j;
                
            }
            j++;
        }
        t = rta;
        for (int i = 0; i < k-1; i++) {
            t = t + rta.substring(x);
        }
        System.out.println(t);
        in.close();
    }
}