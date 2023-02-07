import java.io.*;


public class Main {
public static void main(String [] argv) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String cantidad = br.readLine();
        String [] solucion= new String[Integer.parseInt(cantidad)];
        for(int i=0;i<Integer.parseInt(cantidad);i++){
            String cantidadfor = br.readLine();
            int cantidadelementos=Integer.parseInt(cantidadfor);
            String [] elementosS =br.readLine().split(" ");
            int[] elementos=new int[cantidadelementos];
            for(int j=0;j<elementosS.length;j++){
                elementos[j]=Integer.parseInt(elementosS[j]);
            }
            for(int j=0;j<cantidadelementos;j++){
                boolean centinela=false;
                for(int k=cantidadelementos-1;k>=0;k--){
                    if(elementos[j]==elementos[k] && k-j>=2){
                        solucion[i]="YES";
                        break;
                    } 
                }
                if(centinela) break;
                
            }
        
                
        }
        for(int i=0;i<solucion.length;i++){
            if(solucion[i]==null){
                solucion[i]="NO";
            }
        }
        for(int i=0;i<solucion.length;i++){
        System.out.println(solucion[i]);
        }
    }
}