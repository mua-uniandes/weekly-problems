import java.io.*;
public class Main {
private static double solucion(int n,double[] probabilidades, double[][] matrizdp){
    double respuesta=0;
    matrizdp[0][0] = 1;
	for(int i = 1;i<=n;i++) {
		for(int j = 0;j<=i;j++) {
            if(j>0){
				matrizdp[i][j] = matrizdp[i-1][j]*(1-probabilidades[i])+matrizdp[i-1][j-1]*probabilidades[i];
			}
			else{
				matrizdp[i][j] = matrizdp[i-1][j]*(1-probabilidades[i]);			
			}
		}
	}
    for(int i = n/2+1;i<=n;i++){
        respuesta+=matrizdp[n][i];
    }
    return respuesta;
        
    }
public static void main(String [] argv) throws Exception{
        BufferedReader bf = new BufferedReader(new
        InputStreamReader(System.in));
         try {
        int n=Integer.parseInt(bf.readLine());
        double probabilidades[]= new double[n+1];
        double matrizdp[][]= new double[n+1][n+1];
        String linea[]=bf.readLine().split(" ");
        for (int i=1;i<=n;i++){
             probabilidades[i] = Double.parseDouble(linea[i-1]);
           
        }
         double respuesta=solucion(n,probabilidades,matrizdp);
         System.out.println(respuesta);
         } catch (IOException e) {
            e.printStackTrace();
         }
}
}