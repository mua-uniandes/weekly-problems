import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef {
    public static  void shortest_distance(int[][] matrix) {
        int length = matrix.length;
        for(int i = 0; i<length ; i++)
            for(int j = 0; j<length ; j++) {
                if(j!=i)
                for(int k = 0; k<length ; k++) {
                    if(k!=i)
                    if(matrix[j][k]>(matrix[j][i]+matrix[i][k]))
                        matrix[j][k]=matrix[j][i]+matrix[i][k];
                }
            }
        }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	public static void main (String[] args) throws java.lang.Exception {
		int val = Integer.parseInt(br.readLine());
		while(val-->0)
		dos();
	}
	
	public static void dos()throws java.lang.Exception {
		int val = Integer.parseInt(br.readLine());
        int arr[][] = new int[val][val];
        for(int ars[] : arr) Arrays.fill(ars,(int)100);
        
        for(int i = 0 ; i < val ; i++){
            for(String k : br.readLine().split(" "))
                arr[i][Integer.parseInt(k)-1]=1;
            arr[i][i]=0;
        }
        shortest_distance(arr);
        int ind = -1;
        Double min = Double.MAX_VALUE;
        for(int i = 0 ; i < val ; i++) {
            int sum=0;
            for(int j : arr[i])
                sum+=j;
            if((double)sum/val<min){
                min=(double)sum/val;
                ind=i;
            }
        }
        System.out.println((ind+1)+" "+(String.format("%.6f",min)));
	}
}