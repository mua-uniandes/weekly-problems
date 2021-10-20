package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader


fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val dims = In.readLine()!!.split(" ").map { it.toInt() }
    val graph = MutableList(dims[0]){ List(dims[1]){"."} }
    val plus  = List(dims[0]){ MutableList(dims[1]){false} }
    for(i in 0 until dims[0]) {
        graph[i] = In.readLine()!!.split("")
    }
    for(i in 1 until dims[0] -1) {
        for(j in 1 until dims[1] - 1) {
            if(graph[i][j] == "*" && graph[i-1][j] == "*" && graph[i+1][j] == "*" && graph[i][j+1] == "*" && graph[i][j-1] == "*") {
                var upend = i
                var downend = i
                var leftend = j
                var rightend = j
                while(upend >= 0 && graph[upend][j] == "*") plus[upend--][j]= true;
                while(downend < dims[0] && graph[downend][j] == "*") plus[downend++][j] = true;
                while(leftend >= 0 && graph[i][leftend] == "*") plus[i][leftend--] = true;
                while(rightend < dims[1] && graph[i][rightend] == "*") plus[i][rightend++] = true;

                for (i2 in 0 until dims[0])
                    for (j2 in 0 until dims[1]) {
                    if (plus[i2][j2] != (graph[i2][j2] == "*")) {
                        println("NO")
                        System.exit(0)
                    }
                }
                println("YES")
                System.exit(0)
            }
        }
    }
}