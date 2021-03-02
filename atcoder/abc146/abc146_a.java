import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

class Main {

	public static void main(String[] args) throws Exception {
		
		InputStreamReader is= new InputStreamReader(System.in);
		BufferedReader br = new BufferedReader(is);
			
		String day = br.readLine();
		
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		map.put("MON", 6);
		map.put("TUE", 5);
		map.put("WED", 4);
		map.put("THU", 3);
		map.put("FRI", 2);
		map.put("SAT", 1);
		map.put("SUN", 7);
		
		System.out.println(map.get(day));
			
	}
	
}