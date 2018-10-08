/**
 * Author: Valentina Chacon Buitrago
 * Problem Link: https://www.codechef.com/problems/POTATOES
 */
import java.io.*;

public class POTATOES {

	public boolean isPrime(int n) {
		for(int i=2; i*i <= n  ;i++){
			if(n%i == 0) {
				return false;
			}
		}
		return true;
	}

	public static void main(String[] args) throws IOException, NumberFormatException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		POTATOES p =  new POTATOES();

		int testCases = Integer.parseInt(br.readLine());
		int counter = 0;

		while(counter < testCases) {

			//Read input
			String[] numbers = br.readLine().split(" ");
			int firstCrop = Integer.parseInt(numbers[0]);
			int secondCrop = Integer.parseInt(numbers[1]);

			//Process input
			int totalPotatoes = firstCrop + secondCrop;
			int extraPotatoes = 0;
			boolean notPrimeFound = true;
			while(notPrimeFound){
		
				int numb = totalPotatoes + extraPotatoes;
				if(p.isPrime(numb) && numb!= totalPotatoes){
					System.out.println(extraPotatoes);
					notPrimeFound = false;
				}
				else {
					extraPotatoes++;
				}
			}
			counter++;
		}
	}
}
