
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Num239 {	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader In = new BufferedReader(new InputStreamReader(System.in));
	    int cases = Integer.parseInt(In.readLine());
	    for(int i=0; i<cases; i++) {
	        int count = 0;
	        String[] nums = In.readLine().split(" ");
	        for(int num=Integer.parseInt(nums[0]); num<=Integer.parseInt(nums[1]); num++) {
	            if(num % 10 == 2 || num%10 == 3 || num%10 == 9) {
	                count +=1;
	            }
	        }
	        System.out.println(count);
	    }
	}
}
