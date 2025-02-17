import java.util.*;

public class Raspberry {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int times = scanner.nextInt();

        for (int i = 0; i < times; i++) {
            int k = scanner.nextInt();
            int n = scanner.nextInt();
            
            int[] lista = new int[k];
            for (int j = 0; j < k; j++) {
                lista[j] = scanner.nextInt();
            }
            
            raspberry(k, n, lista);
        }
        scanner.close();
    }

    public static void raspberry(int k, int n, int[] lista) {
        if (n == 2 || n == 3 || n == 5) {
            List<Integer> newList = new ArrayList<>();
            for (int i = 0; i < k; i++) {
                if (lista[i] % n != 0) {
                    newList.add(Math.abs(lista[i] % n - n));
                } else {
                    newList.add(0);
                    break;
                }
            }
            System.out.println(Collections.min(newList));
        } else {
            List<Integer> newList = new ArrayList<>();
            int ceros = 0;
            int h = 1;
            for (int j = 0; j < k; j++) {
                if (lista[j] % 4 == 0) {
                    h = 0;
                    break;
                } else if (lista[j] % 2 == 0) {
                    ceros++;
                    if (ceros == 2) {
                        break;
                    }
                } else {
                    newList.add(Math.abs(lista[j] % 4 - 4));
                }
            }
            System.out.println(Math.min((2 - ceros) * h, newList.isEmpty() ? Integer.MAX_VALUE : Collections.min(newList)));
        }
    }
}