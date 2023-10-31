import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.TreeSet;

public class Grains_A_Star {

	public static void main(String[] args) throws Exception{
		var br = new BufferedReader(new InputStreamReader(System.in));
		for(var caso = br.readLine().split(" "); !caso[0].equals("0") || !caso[1].equals("0"); caso = br.readLine().split(" ")) {
			var Silos = Integer.parseInt(caso[0]);
			var Cap = Integer.parseInt(caso[1]);
			var start = new Node(Silos, Cap);
			for(int e = Cap-1; e >= 0; e--) {
				var line = br.readLine().toCharArray();
				for(int i = 0; i < Silos; i++)
					start.Silos[i][e] = line[i]=='.'?0:line[i];
			}
			int min = Solve(start, Silos, Cap);
			if(min > -1)
				System.out.println(min);
			else
				System.out.println("Camelot Will Starve!");
		}
	}
	static int Solve(Node start, int S, int C) {
		var Visited = new HashSet<String>();
		var Q = new PriorityQueue<H>();
		var G = start.G();
		Visited.add(start.toString());
		Q.add(new H(start, G));
		while(!Q.isEmpty()) {
			var next = Q.poll().node;
			if(next.end(G)) {
				return next.Depth;
			}
			var tops = next.tops();
			for(int e = 0; e < S; e++)
				for(int i = 0; i < S; i++) 
				if(e!=i && tops[e] != 0 && tops[i] < C && (tops[i] == 0 || next.Silos[e][tops[e]-1] == next.Silos[i][tops[i]-1])){
					var Children = next.Clone();
					Children.Depth = next.Depth+1;
					Children.Silos[i][tops[i]] = Children.Silos[e][tops[e]-1];
					Children.Silos[e][tops[e]-1] = 0;
					var str = Children.toString();
					if(!Visited.contains(str)) {
						Visited.add(str);
						Q.add(new H(Children, G));
					}
				}
		}
		return -1;
	}
}
class H implements Comparable<H>{
	Node node;
	int f;
	
	public H(Node node, int G) {
		this.node = node;
		f = node.Depth + node.heuristica2(G);
	}

	@Override
	public int compareTo(H o) {
		return f - o.f;
	}
}
class Node {
	char[][] Silos;
	int Depth;
	public Node(char[][] silos) {
		Silos = silos;
	}
	public Node(int count, int cap) {
		this(new char[count][cap]);
	}
	public boolean end(int G) {
		int gs = 0;
		for(int e = 0; e < Silos.length;e++) {
			var bottom = Silos[e][0];
			if(bottom != 0)
				gs++;
			var top = 0;
			while(top < Silos[e].length && Silos[e][top] != 0 && bottom == Silos[e][top])
				top++;
			if(top < Silos[e].length && Silos[e][top] != 0)
				return false;
		}
		return gs == G;
	}
	public int[] tops() {
		var tops = new int[Silos.length];
		for(int e = 0; e < Silos.length;e++)
			while(tops[e] < Silos[e].length && Silos[e][tops[e]] != 0)
				tops[e]++;
		return tops;
	}
	public int heuristica1(int G) {
		int h = 0;
		int gs = 0;
		for(int e = 0; e < Silos.length;e++) {
			var bottom = Silos[e][0];
			if(bottom != 0)
				gs++;
			for(int i = 0; i < Silos[0].length && Silos[e][i] != 0; i++)
				if(Silos[e][i] != Silos[e][0])
					h++;
		}
		return h + Math.max(0, gs - G);
	}
	public int heuristica2(int G) {
		int h = 0;
		int gs = 0;
		for(int e = 0; e < Silos.length;e++) {
			var bottom = Silos[e][0];
			if(bottom != 0)
				gs++;

			var top = 0;
			while(top < Silos[e].length && Silos[e][top] != 0)
				top++;
			var stack = 0;
			while(stack < Silos[e].length && Silos[e][stack] != 0 && Silos[e][stack] == Silos[e][0])
				stack++;
			h+=top-stack;
		}
		return h + Math.max(0, gs - G);
	}
	@Override
	public String toString() {
		var s = "";
		for(int e = 0; e < Silos.length;e++) {
			for(int i = 0; i < Silos[0].length; i++)
				s+=Silos[e][i] == 0?'.':Silos[e][i];
			s+=System.lineSeparator();
		}
		return s.trim();
	}
	public Node Clone(){
		char[][] ret = new char[Silos.length][];
		for(int e = 0; e < ret.length; e++)
			ret[e] = Arrays.copyOf(Silos[e], Silos[e].length);
		return new Node(ret);
	}
	public int G() {
		var Set = new TreeSet<Character>();
		for(int e = 0; e < Silos.length;e++) {
			for(int i = 0; i < Silos[0].length; i++)
				if(Silos[e][i] != 0)
					Set.add(Silos[e][i]);
		}
		return Set.size();
	}
}