/**
 * Author: Valentina Chacon Buitrago
 * Problem Link: https://www.codechef.com/problems/SPCANDY
 */
import java.util.Scanner;


public class SPCANDY{

	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);

		int testCases = sc.nextInt();
		int counter = 0;

		while(counter < testCases) {

			long numberCandies = sc.nextLong();
			long numberStudents = sc.nextLong();
			long candiesForTeacher = 0;
			long candiesForStudents = 0;

			if(numberCandies == 0) {
				candiesForTeacher = 0;
				candiesForStudents = 0;
			}
			else if(numberStudents == 0) {
				candiesForTeacher = numberCandies;
				candiesForStudents = 0;
			}
			else {
				candiesForTeacher = numberCandies % numberStudents;
				candiesForStudents = (numberCandies - candiesForTeacher)/numberStudents;

			}
			System.out.println(candiesForStudents+ " " + candiesForTeacher);
			counter++;	
		}
	}

}
