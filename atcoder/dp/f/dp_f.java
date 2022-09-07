import java.io.*;
import java.util.*;
// note the class name and the public identifier may differ from one online judge to the other.
public class Main {
private static String solucion(String plinea1, String plinea2){
        String linea1=plinea1.trim();
        String linea2=plinea2.trim();
        String respuesta="";
        if (linea1.length()==1 && linea2.length()==1 && 
        !linea1.equals(linea2)){
            return respuesta;
        }
        int [][] matrizdp = new int[3001][3001];
        for(int i=0;i<linea1.length();i++){
            for(int j=0;j<linea2.length();j++){
                if(linea1.charAt(i)==linea2.charAt(j)){
                    matrizdp[i+1][j+1]=matrizdp[i][j]+1;
                }
                else{
                    matrizdp[i+1][j+1]=Math.max(matrizdp[i][j+1], matrizdp[i+1][j]);
                    }

            }
        }
        int contadorext=linea1.length();
        int contadorint=linea2.length();
        while (contadorext>0){
            while(contadorint>0){
                if (matrizdp[contadorext][contadorint]>matrizdp[contadorext-1][contadorint]
                && matrizdp[contadorext][contadorint]>matrizdp[contadorext][contadorint-1]){
                    respuesta=linea1.charAt(contadorext-1)+respuesta;
                    contadorext-=1;
                    contadorint-=1;
                }
                else if(matrizdp[contadorext-1][contadorint]>matrizdp[contadorext][contadorint-1]){
                    contadorext-=1;
                }
                else if(matrizdp[contadorext-1][contadorint]<=matrizdp[contadorext][contadorint-1]){
                    contadorint-=1;
                }
                if (contadorext==0 ||contadorint==0){
                    break;
                }
            }
            break;
        }
        return respuesta;
    }
public static void main(String [] argv) throws Exception{
BufferedReader bf = new BufferedReader(new
        InputStreamReader(System.in));
         try {
        String linea1="";
        String linea2="";
        for (int i=0;i<2;i++){
            String line = bf.readLine();
            if(i==0){
                linea1=line;
            }else{
                linea2=line;
            }
        }
         String respuesta=solucion(linea1,linea2);
         System.out.println(respuesta);
         } catch (IOException e) {
            e.printStackTrace();
         }
}
}
