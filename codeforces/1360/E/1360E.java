import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    
    private static int[][] matrix;
    
    public static void main(String[] args) throws Exception {
        Main problem = new Main();
        problem.solveProblems();
    }

    public void solveProblems() throws IOException, Exception {
        try (InputStreamReader is = new InputStreamReader(System.in);
                 BufferedReader br = new BufferedReader(is)) {

                String line = br.readLine();
                int totalCases = Integer.parseInt(line);
                
                for (int cases = 0; cases < totalCases; cases++) {
                    line = br.readLine();
                    int size = Integer.parseInt(line);
                    matrix = new int[size][size];
                    for (int i = 0; i < size; i++) {
                        line = br.readLine();
                        for(int j = 0; j < size; j++){
                            if('1' == line.charAt(j)) matrix[i][j] = 1;
                            else matrix[i][j] = 0;
                        }
                    }
                    solveD(size);
                    
                }
            }
    }

    public void solveD(int size) throws Exception {
        
        boolean possible = true;
        
        outerloop:
        for(int i = size - 1; i >= 0; i--){
            for(int j = size - 1; j >= 0; j--){
                if(matrix[i][j] == 1 && !(i + 1 >= size || j + 1 >= size || matrix[i + 1][j] == 1 || matrix[i][j + 1] == 1)){
                    possible = false;
                    System.out.println("NO");
                    break outerloop;
                }
            }
        }

        if(possible) System.out.println("YES");
    
    }
}