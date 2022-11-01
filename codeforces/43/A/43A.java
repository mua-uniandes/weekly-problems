import java.io.*;
import java.util.*;
// note the class name and the public identifier may differ from one online judge to the other.
public class Main {
public static void main(String [] argv) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cantidad = Integer.parseInt(br.readLine());
        HashMap<String,Integer> mapa= new HashMap<>(2);
        String[] equipos= new String[2];
        int contador=0;
        for(int i=0;i<cantidad;i++){
            String nombreEquipo=br.readLine();
            if(mapa.containsKey(nombreEquipo)){
                mapa.put(nombreEquipo, mapa.get(nombreEquipo)+1);
            }else{
                mapa.put(nombreEquipo, 1);
                equipos[contador]=nombreEquipo;
                contador++;
            }
            
        }
        if(contador==2){
            String respuesta="";
            int mayor=0;
            for(int i=0;i<2;i++){
                 if(mapa.get(equipos[i])>mayor){
                    mayor=mapa.get(equipos[i]);
                    respuesta=equipos[i];
                }
            }
        System.out.println(respuesta);
        }
        else{
            System.out.println(equipos[0]);
        }
        
    }
}

