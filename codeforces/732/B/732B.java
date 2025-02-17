import java.util.Scanner;
import java.util.ArrayList;// Import the Scanner class
import java.util.Arrays;// Import the Scanner class
import java.util.List;// Import the Scanner class
import java.util.stream.Collectors;

public class MyClass {
  public static void main(String args[]) {
    Scanner myObj = new Scanner(System.in);
    String DaysAndWalks = myObj.nextLine();
    List<String> myLista = new ArrayList<String>(Arrays.asList(DaysAndWalks.split(" ")));
    List<Integer> sub = new ArrayList<Integer>();
    myLista.forEach(i -> {
        sub.add(Integer.parseInt(i));
    });

    
    DaysAndWalks = myObj.nextLine();
    List<String> myLista2 = new ArrayList<String>(Arrays.asList(DaysAndWalks.split(" ")));
    List<Integer> sub2 = new ArrayList<Integer>();
    myLista2.forEach(i -> {
        sub2.add(Integer.parseInt(i));
    });

    int sum = 0; 

    for (int i = 0; i < sub2.size() - 1; i++){
        if (sub2.get(i) + sub2.get(i+1) < sub.get(1)){
            int a = sub.get(1) - (sub2.get(i) + sub2.get(i+1));
            sub2.set(i+1, sub2.get(i+1) + a);
            sum += a;
        }
    }

   
    System.out.println(sum);
    
    // for (int num : sub2) {
    //     System.out.print(num + " ");
    // }
    List<String> res = new ArrayList<String>();
    sub2.forEach(s -> {
        res.add(Integer.toString(s));
    });
    System.out.println(String.join(" ", res));

        
  }
}