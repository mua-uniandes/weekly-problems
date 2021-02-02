/**
 * Author: Valentina Chacon Buitrago
 * Problem Link: https://www.codechef.com/problems/PLZLYKME
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class PLZLYKME{
	
	public static void main(String[] args)throws IOException, NumberFormatException {
		BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(br.readLine());
		int counter = 0;
		
		while(counter < testCases) {
			
			//Read Input
			String[] data = br.readLine().split(" ");
			long numberLikes = Long.parseLong(data[0]);
			long amountOfDays = Long.parseLong(data[1]);
			long initialNumLikes = Long.parseLong(data[2]);
			long constantFactor = Long.parseLong(data[3]);
			
			//Process Input
			long currentLikes = 0;
			long pastLikes = initialNumLikes;
			int counter2 = 1;
			while(counter2 <= amountOfDays) {
				
				//For the first day there is no formula
				if(counter2 == 1) {
					currentLikes = pastLikes;
					if(currentLikes == numberLikes) {
						break;
					}
				}
				else {
					currentLikes = pastLikes + pastLikes*constantFactor;
					//System.out.println("Esta es la cantidad de likes: " + currentLikes);
					pastLikes = currentLikes;
					
					if(currentLikes >= numberLikes) {
						break;
					}
					
				}
				counter2++;
			}	
			//System.out.println("This is the current number of likes" + currentLikes);
			if(currentLikes >= numberLikes) {
				System.out.println("ALIVE AND KICKING");
			}
			else {
				System.out.println("DEAD AND ROTTING");
			}
			counter++;
		}
		
	}

}
