import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
    
    public static void main(String[] args) {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try {
            String line = bf.readLine();
            for(int i = 0; i < line.length(); i++){
                if((i+1)%2 == 0 && !Character.isUpperCase(line.charAt(i))){
                    System.out.println("No");
                    return;
                }
                else if((i+1)%2 != 0 && Character.isUpperCase(line.charAt(i))){
                    System.out.println("No");
                    return;
                }
            }
            System.out.println("Yes");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}