import java.io.*;
import java.lang.Math;
// note the class name and the public identifier may differ from one online judge to the other.
public class Main {
    private static String solucion(int x1,int y1,int x2,int y2){
        String respuesta="";
        for(int i=0;i<3;i++){
            if(i==0){
                if(x1==x2||y1==y2){
                    respuesta=respuesta+""+1;
                }
                else{
                    respuesta=respuesta+""+2;
                }
            }
            else if(i==1){
                if(Math.abs(x1-x2)==Math.abs(y1-y2)){
                    respuesta=respuesta+" "+1;
                }
                else if((Math.abs(x1-x2)%2==0)&&(Math.abs(y1-y2)%2==1)){
                    respuesta=respuesta+" "+0;
                }
                else if((Math.abs(x1-x2)%2==1)&&(Math.abs(y1-y2)%2==0)){
                    respuesta=respuesta+" "+0;
                }
                else{
                    respuesta=respuesta+" "+2;
                }
            }
            else if(i==2){
                int restax=(Math.abs(x1-x2));
                int restay=(Math.abs(y1-y2));
                int resp=Math.max(restax, restay);
                respuesta=respuesta+" "+resp;
                
            }
        }
        return respuesta;
    }
public static void main(String [] argv) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] line = br.readLine().split(" ");
        int x1 = Integer.parseInt(line[0]);
        int y1 = Integer.parseInt(line[1]);
        int x2 = Integer.parseInt(line[2]);
        int y2 = Integer.parseInt(line[3]);
        String respuesta=solucion(x1, y1, x2, y2);
        System.out.println(respuesta);
        
    }
}
