/**
 * Author: Valentina Chacon Buitrago
 * Problem Link: https://www.codechef.com/problems/TOTR
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;


public class TOTR {

	public static void main(String[] args) throws IOException, NumberFormatException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] info = br.readLine().split(" ");
		//Read Input
		int numberWords  = Integer.parseInt(info[0]);
		char[] alphabetByte = info[1].toCharArray();
		char[] english = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
				'p','q','r','s','t','u','v','w','x','y','z'};

		//Process input to keep the Bytelandian and English alphabet
		//LinkedHashMap keeps the order in which items are inserted
		HashMap<String, String> alphabet = new HashMap<>();
		alphabet.put("_", " ");

		for (int i = 0; i < english.length; i++){
			//In the hashMap the key is the Bytelandian letter and the value is English
			String lowerEnglish = ""+english[i];
			String upperEnglish = ""+Character.toUpperCase(english[i]);

			String lowerByte = ""+alphabetByte[i];
			String upperByte = ""+Character.toUpperCase(alphabetByte[i]);

			//Put lower case
			alphabet.put(lowerEnglish, lowerByte);			
			//put upper case
			alphabet.put(upperEnglish, upperByte);	

		}


		//Translate from Bytelandian to English
		int counter = 0;
		while(counter < numberWords) {

			String ans = "";
			char[] word = br.readLine().toCharArray();
			for (int i = 0; i < word.length; i++) {
				String oldLetter = ""+word[i];
				//There is a translation for the current word
				if(alphabet.containsKey(oldLetter)) {
					ans+=alphabet.get(oldLetter);
				}
				//Any punctuation that is not stored in the alphabet
				else {
					ans+=oldLetter;
				}	
			}
			System.out.println(ans);
			counter++;
		}
	}
}
