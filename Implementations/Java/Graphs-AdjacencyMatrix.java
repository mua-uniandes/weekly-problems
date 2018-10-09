/**
 * Author: Valentina Chacon Buitrago
 * Topic: Graph Implementations
 * 
 * Instructions: Create a Graph using an adjacency matrix. Determine the edges 
 * that exist in the graph.
 * 
 * Input:
 * 5   --Represents the number of nodes in the graph
 * 7   --Represents the number of edges in the graph
 * 2 3 --Edge from node 2 to node 3
 * 5 4 --Edge from node 5 to node 4
 * 1 3 --Edge from node 1 to node 3
 * 2 5 --Edge from node 2 to node 5
 * 5 2 --Edge from node 5 to node 2
 * 4 1 --Edge from node 4 to node 1
 * 3 4 --Edge from node 3 to node 4
 * 
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class AdjacencyMatrix {

	//Initialize the matrix
	public boolean[][] getAdjacencyMatrix(int pLength){
		boolean[][] adjacencyMatrix = new boolean[pLength][pLength];

		for (int i = 0; i < pLength; i++) {
			adjacencyMatrix[i][i] = false;
		}
		return adjacencyMatrix;
	}

	public static void main(String[] args) throws IOException, NumberFormatException{

		//Input
		BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
		int nodes = Integer.parseInt(br.readLine());
		int edges = Integer.parseInt(br.readLine());

		AdjacencyMatrix m = new AdjacencyMatrix();
		
		//ignore row and column 0
		boolean[][] matrix = m.getAdjacencyMatrix(nodes + 1);

		//Process Information
		int counter = 0;
		while(counter < edges) {
			String[] currentNodes = br.readLine().split(" ");
			int from = Integer.parseInt(currentNodes[0]);
			int to = Integer.parseInt(currentNodes[1]);

			matrix[from][to] = true;
			counter++;
		}

		//Check the edges in the graph
		for (int i = 0; i < nodes+1; i++) {
			for(int j = 0; j < nodes+1; j++) {
				boolean ans = matrix[i][j];
				if(ans) {
					System.out.println("There is an edge between nodes: " + i + " and " + j);
				}
			}
		}
	}
}
