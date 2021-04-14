import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
            int coins = Integer.parseInt(bf.readLine());
            System.out.println(100-(coins % 100));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}