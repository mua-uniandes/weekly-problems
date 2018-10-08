/**
 * Author: Valentina Chacon Buitrago
 * Problem Link: https://www.codechef.com/problems/TACHSTCK
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class TACHSTCK {
	
	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//Read Input
		String[] numbers = br.readLine().split(" ");
		int numberChopsticks = Integer.parseInt(numbers[0]);
		long maxDifference = Long.parseLong(numbers[1]);
		long[] chopsticks = new long[numberChopsticks];
		
		for (int i = 0; i < numberChopsticks; i++){
			long currentChop = Long.parseLong(br.readLine());
			chopsticks[i] = currentChop;	
		}		
		Arrays.sort(chopsticks);	
		//Process Input
		int possibleCombinations = 0;
		for (int i = 1; i < chopsticks.length; i++) {
			long dif = chopsticks[i] - chopsticks[i-1];
			if(chopsticks[i] != 0 && chopsticks[i-1] != 0 && dif <= maxDifference){
				possibleCombinations++;
				//Mark current Chopstick as cero to show that it has been used
				chopsticks[i] = 0;
				chopsticks[i-1] = 0;
			}			
		}		
		System.out.println(possibleCombinations);	
	}
}
