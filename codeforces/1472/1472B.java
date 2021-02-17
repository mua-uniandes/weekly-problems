import java.util.Scanner;
public class Main{
    public static Scanner in = new Scanner(System.in);

    public static void main(String[] args) {
        int t = Integer.parseInt(in.nextLine());
        String[] res = new String[t];
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(in.nextLine());
            String entrada = in.nextLine();
            int[] dulces = new int[n];
            String[] nums = entrada.split(" ");

            for (int j = 0; j < n; j++) {
                int a = Integer.parseInt(nums[j]);
                dulces[j] = a;
            }
            res[i] = problema(dulces);
        }
        for(String r : res)
            System.out.println(r);
    }

    public static String problema(int[] dulces){
        int suma1 = 0;
        int suma2 = 0;
        for (int i: dulces) {
            if(i==1)    suma1 += 1;
            if(i==2)    suma2 += 1;
        }
        
        if(suma1 % 2 == 0 && suma2 % 2 == 0)
            return "YES";
        if(suma2 % 2 == 1 && suma1 % 2 == 0 && suma1 > 0){
            int temp = suma1-(suma2*2); 
            if(temp % 2 == 0)
                return "YES";
        }
        return "NO"; 
    }
}