package Easy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Problem link: https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/algorithm/monk-at-the-graph-factory/description/
 * @author Valentina Chacon Buitrago
 */
public class MonkAtTheGraphFactory {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader  br =  new BufferedReader(new InputStreamReader(System.in));
		
		/*
		 * A Tree is an undirected graph in which any two vertices are connected by only one path. 
		 * A tree is an acyclic graph and has N - 1 edges where N is the number of vertices.
		 */
		
		int numberOfNodes = Integer.parseInt(br.readLine());

		String[] degrees = br.readLine().split(" ");	
		
		int numberOfEdges = 0;
		for (int i = 0; i < degrees.length; i++) {
			numberOfEdges+= Integer.parseInt(degrees[i]);
		}
		/*
		 * If we take the sum of all the degrees, each edge will be counted twice
		 */
		if(numberOfEdges == 2*(numberOfNodes - 1)) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}

}
