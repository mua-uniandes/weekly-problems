// Codigo: Rodrigo Cardoso
// Dado: N : Tamanio de alfabeto
// Encontrar resp, la longitud máxima de una asp 
//   Una cadena es una asp ssi (1) no tiene 2 símbolos seguidos iguales
//                             (2) no tiene 2 subcadenas de 2 símbolos iguales
// Se puede demostrar que: resp = N*(N-1)+1
// Este algoritmo es la implementación O(1) de esta idea

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Asp {
	public static int N;

	public static void main(String[] args) throws IOException {
//		long startTime = System.nanoTime();
		
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in),1024);
		StringTokenizer tokenizer;
		tokenizer = new StringTokenizer(reader.readLine()," ");
		N = Integer.parseInt(tokenizer.nextToken());
		while (N != 0) {
			int resp;
			resp = N*(N-1)+1;
			System.out.println(resp);
			tokenizer = new StringTokenizer(reader.readLine()," ");
			N = Integer.parseInt(tokenizer.nextToken());
		}
		
//		long estimatedTime = System.nanoTime() - startTime;
//		System.out.println("Tiempo: " + estimatedTime/1000000000);
	}
}