import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class santaClaus {

public static void main(String[] args) {
    BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    try {
        String line  = bf.readLine();
        int candies = Integer.parseInt(line);
        int maximo = (int) Math.pow(2*candies, 0.5)+1;
        boolean maximoSirve = false;
        while(!maximoSirve)
        {
            int prueba = (maximo*maximo) + maximo;
            if(prueba <= 2*candies){
            maximoSirve = true;
            }
            else{maximo--;}
        }
        //este es el maximo
        String resp = "";
        for(int i=1;i<= maximo;i++)
        {
            if(i!=maximo)
            {
            resp+=i+" ";
            candies -= i;
            }
            else
            {
            resp+=candies;
            }
        }
        System.out.println(maximo+"\n"+resp);
    } catch (IOException e) {
        e.printStackTrace();
    }
  }
}

