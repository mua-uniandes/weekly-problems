import java.io.*;
import java.util.*;
// note the class name and the public identifier may differ from one online judge to the other.
public class Main {
    public static String solucion(int cantidadParentesis, String[] Pparentesis){
        String answer="";
        Stack <String>pila= new Stack<String>();
        String [] parentesis=Pparentesis;
        for(int i=0;i<parentesis.length;i++){
            if(pila.isEmpty()){
                pila.push(parentesis[i]);
            }else{
                if(pila.peek().equals("(")&&parentesis[i].equals(")")){
                    pila.pop();
                }else{
                    pila.push(parentesis[i]);
                }
            }
        }
        if(pila.isEmpty()){
            answer=""+0;
        }else{
            answer=""+pila.size()/2;
        }
        return answer;
    }
public static void main(String [] argv) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cantidad= Integer.parseInt(br.readLine());
        String[] respuestas= new String[cantidad];
        for(int i=0;i<cantidad;i++){
            int cantidadParentesis= Integer.parseInt(br.readLine());
            String [] parentesis= br.readLine().split("");
            respuestas[i]= solucion(cantidadParentesis, parentesis);
        }
        for(int i=0;i<cantidad;i++){
            System.out.println(respuestas[i]);
        }
    }
}