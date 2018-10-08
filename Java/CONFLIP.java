/**
 * Author: Valentina Chacon Buitrago
 * Problem Link: https://www.codechef.com/problems/CONFLIP
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CONFLIP{

	public static void main(String[] args) throws NumberFormatException, IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(br.readLine());
		int counter = 0;

		while(counter < testCases){

			int numberGames = Integer.parseInt(br.readLine());
			int counter2 = 0;

			while(counter2 < numberGames){

				//Input
				String[] numbers  = br.readLine().split(" ");
				int initialStateCoin = Integer.parseInt(numbers[0]);
				int numberCoins = Integer.parseInt(numbers[1]);
				int resultType = Integer.parseInt(numbers[2]);

				//Process input
				int numberHeads = 0;
				int numberTails = 0;

				//Initially all coins are showing head
				if(initialStateCoin == 1){
					numberHeads = numberCoins/2;
					numberTails = numberCoins - numberHeads;

				}
				//Initially all coins are showing tails
				else{
					numberTails = numberCoins/2;
					numberHeads = numberCoins - numberTails;
				}

				//Print results
				if(resultType == 1){
					System.out.println(numberHeads);
				}
				else{
					System.out.println(numberTails);
				}
				counter2++;
			}
			counter++;
		}

	}
}

