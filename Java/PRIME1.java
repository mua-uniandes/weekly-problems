/**
 * Author: Valentina Chacon Buitrago
 * Problem Link: https://www.codechef.com/problems/PRIME1
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PRIME1{ 

	public static  void main(String[] args)throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int testCases = Integer.parseInt(br.readLine());
		int counter = 0;
		while(counter < testCases){

			//Read Input
			String[] numbers = br.readLine().split(" ");
			int m = Integer.parseInt(numbers[0]);
			int n = Integer.parseInt(numbers[1]);


			//Process input and print the results
			for(int i = m; i <= n; i++){

				boolean ans = true;
				for(int j = 2; j*j <= i; j++){
					if(i%j == 0) {
						ans = false;
						break;
					}
				}
				if(ans && i != 1){
					System.out.println(i);	
				}	
			}
			counter++;
		}

	}

}
