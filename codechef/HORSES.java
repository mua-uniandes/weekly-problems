/**
 * Author: Valentina Chacon Buitrago
 * Problem Link: https://www.codechef.com/problems/HORSES
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class HORSES{

	public static void main(String[] args) throws NumberFormatException, IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCases  = Integer.parseInt(br.readLine());
		int counter = 0;

		while(counter < testCases){
			int numberHorses = Integer.parseInt(br.readLine());
			String[] horses = br.readLine().split(" ");
			int[] powers = new int[numberHorses];

			//Get the powers in an integer array
			for(int i = 0; i < numberHorses; i++) {
				int number = Integer.parseInt(horses[i]);
				powers[i] = number;
			}
			//Sort the powers
			Arrays.sort(powers);

			//Compare powers and find the minimum difference
			int minDifference = Integer.MAX_VALUE;
			for(int i = 1; i<numberHorses; i++) {
				int pow1 = powers[i];
				int pow2 = powers[i-1];
				int diff = pow1 - pow2;

				if(diff < minDifference) {
					minDifference = diff;
				}	
			}
			System.out.println(minDifference);

			counter++;
		}

	}

}
