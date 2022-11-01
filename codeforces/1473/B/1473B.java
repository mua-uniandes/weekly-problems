import java.io.*;
// note the class name and the public identifier may differ from one online judge to the other.
public class Main {
    public static int mcd(int num1, int num2) {
 
        int a = Math.max(num1, num2);
        int b = Math.min(num1, num2);
 
        int resultado = 0;
        do {
            resultado = b;
            b = a % b;
            a = resultado;
 
        } while (b != 0);
 
        return resultado;
 
    }

    public static int mcm(int num1, int num2) {
        int a = Math.max(num1, num2);
        int b = Math.min(num1, num2);
     
        int resultado = (a / mcd(num1, num2)) * b;
         
        return resultado;
     
    }
    public static String solucion(String[]palabras){
        String solucion="";
        String palabra1=palabras[0];
        String palabra2=palabras[1];
        String revisar1="";
        String revisar2="";
        String palabramayor="";
        String palabramenor="";
        if(palabra1.length()>palabra2.length()){
            palabramayor=palabra1;
            palabramenor=palabra2;
        }else{
            palabramayor=palabra2;
            palabramenor=palabra1;
        }
        for(int i=0;i<palabra1.length();i++){
            revisar2+=palabra2;
        }
        for(int i=0;i<palabra2.length();i++){
            revisar1+=palabra1;
        }
        if(!revisar1.equals(revisar2)){
            solucion=""+-1;
        }else{
            int tamaniocantidad=mcm(palabramayor.length(),palabramenor.length());
            if(palabramayor.length()<tamaniocantidad){
                for(int i=0;i<tamaniocantidad/palabramayor.length();i++){
                    solucion+=palabramayor;
                }
            }else if(palabramayor.length()==tamaniocantidad){
                solucion=palabramayor;
            }
        }
        return solucion;
    }
public static void main(String [] argv) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cantidad = Integer.parseInt(br.readLine());
        String[] solucion= new String[cantidad];
        for(int i=0;i<cantidad;i++){
            String [] palabras= new String[2];
            for(int j=0;j<2;j++){
                palabras[j]=br.readLine();
            }
            solucion[i]=solucion(palabras);

        }
        for(int i=0;i<solucion.length;i++){
            System.out.println(solucion[i]);
        }
        
    }
}