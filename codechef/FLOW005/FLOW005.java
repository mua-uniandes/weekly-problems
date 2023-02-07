import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        try{
            int numberTestCases = Integer.parseInt(bf.readLine().strip());
            int currentNumber;

            int cantidad;
            for (int i=0;i<numberTestCases;i++){
                int max = 100;
                currentNumber = Integer.parseInt(bf.readLine());
                cantidad=0;
                while(currentNumber!=0){

                        if (currentNumber-max>=0){
                            currentNumber-=max;
                            cantidad++;
                        }
                        else {
                            switch (max){
                                case(100)->max=50;
                                case(50)->max=10;
                                case(10)->max=5;
                                case(5)->max=2;
                                default -> max=1;
                            }
                        }
                }
                System.out.println(cantidad);
            }
        }catch(IOException e){
            e.printStackTrace();
        }

    }
}