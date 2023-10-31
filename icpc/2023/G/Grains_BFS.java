import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Collections;

class SiloState {

    private ArrayList<String> silos;
    private ArrayList<String> sorted;
    public Integer d;
    private int c;
    protected int hash;
    protected long longhash;

    public SiloState(ArrayList<String> silos, Integer d, int c) {
        this.silos = new ArrayList<>(silos);
        this.d = d; // distance from the initial state
        this.c = c;
        // So permutations have same hash
        this.sorted = new ArrayList<>(this.silos);
        Collections.sort(sorted);
        this.hash = this.sorted.hashCode();
    }

    boolean oneChar(String str) {
        char c = str.charAt(0);
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) != c)
                return false;
        }
        return true;
    }

    /**
     * Check if the silos are sorted
     */
    public boolean isSorted(HashMap<Character, Integer> grainCount) {
        for (var silo : this.silos) {
            // empty
            if (silo.length() == 0)
                continue;
            // only one grain and all the grains from that type
            if (!oneChar(silo))
                return false;
            if (silo.length() != grainCount.get(silo.charAt(0)))
                return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        return this.hash;
    }

    public long longHashCode() {
        return this.longhash;
    }

    public boolean equals(Object o) {
        return this.hash == ((SiloState) o).hash &&
        // TODO slow comparison
                this.sorted.equals(((SiloState) o).sorted);
    }

    public String toString() {
        var b = new StringBuilder();
        // s = "-"*len(self.silos) + "\n"
        b.append(" = ").append(this.d).append("\n");
        // for h in range(self.c -1, -1, -1):
        for (int h = this.c - 1; h >= 0; h--) {
            for (var silo : this.silos) {
                b.append(h < silo.length() ? silo.charAt(h) : '.');
            }
            b.append("\n");
        }
        return b.toString();
    }

    /**
     * """Get a list of all adjacent states"""
     */
    public ArrayList<SiloState> adjacentStates() {
        ArrayList<SiloState> states = new ArrayList<>();
        for (int i = 0; i < this.silos.size(); i++) {
            for (int j = 0; j < this.silos.size(); j++) {
                var origin = this.silos.get(i);
                var dest = this.silos.get(j);
                if (i == j)
                    continue;
                // # try moving a grain lot from silo i to silo j
                // # j has to have space for the grain
                // # i has to be non-empty, j has to be empty or have the same grain in the top
                if (origin.length() > 0 && dest.length() < this.c &&
                        (dest.length() == 0 || origin.charAt(origin.length() - 1) == dest.charAt(dest.length() - 1))) {
                    // # Create a new state
                    var newSilos = new ArrayList<String>(this.silos);
                    // # move from i to j
                    newSilos.set(i, origin.substring(0, origin.length() - 1));
                    newSilos.set(j, dest + origin.charAt(origin.length() - 1));
                    // # increment distance
                    var newState = new SiloState(newSilos, this.d + 1, this.c);
                    states.add(newState);
                }
            }
        }
        return states;
    }
}

public class Grains_BFS {
    /**
     * """Process the silos to sort them"""
     */
    public static int sortSilos(ArrayList<String> silos, HashMap<Character, Integer> grainCount, int c) {
        var initial = new SiloState(silos, 0, c);
        var queue = new LinkedList<SiloState>();
        var is_in_queue = new HashSet<SiloState>();
        var visited = new HashSet<>();
        queue.push(initial);
        is_in_queue.add(initial);
        int n = 0;
        // # BFS
        while (!queue.isEmpty()) {
            n++;
            var state = queue.removeFirst();
            is_in_queue.remove(state);
            visited.add(state);
            if (state.isSorted(grainCount)) {
                return state.d;
            }
            // # traverse all adjacent states
            for (var state2 : state.adjacentStates()) {
                if (!is_in_queue.contains(state2) && !visited.contains(state2)) {
                    queue.add(state2);
                    is_in_queue.add(state2);
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in), 1024);

        // # Read input
        int s, c, r;
        long t;
        String[] parts = br.readLine().split(" ");
        s = Integer.parseInt(parts[0]);
        c = Integer.parseInt(parts[1]);
        while (s != 0 && c != 0) {
            ArrayList<String> silos = new ArrayList<>(s);
            for (int i = 0; i < s; i++)
                silos.add("");
            HashMap<Character, Integer> grainCount = new HashMap<>();
            // # Read c lines
            for (var l = 0; l < c; l++) {
                var line = br.readLine();
                for (int i = 0; i < s; i++) {
                    var g = line.charAt(i);
                    if (g != '.') {
                        // count each type of grain
                        grainCount.put(g, (grainCount.containsKey(g) ? grainCount.get(g) : 0) + 1);
                        // prepend
                        silos.set(i, g + silos.get(i));
                    }
                }
            }
            t = System.currentTimeMillis();
            r = sortSilos(silos, grainCount, c);
            System.out.println(r != -1 ? r : "Camelot Will Starve!");
            // measure time
            if (args.length > 0 && args[0].equals("-m"))
                System.out.println("\t" + s + "\t" + c + "\t" + (System.currentTimeMillis() - t)/1000.0);
            parts = br.readLine().split(" ");
            s = Integer.parseInt(parts[0]);
            c = Integer.parseInt(parts[1]);
        }
    }
}