package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val graph = In.readLine()!!.split(" ").map {it.toInt()}
    val n = graph[0]
    val m = graph[1]
    val arr = List(n){0}.toMutableList()
    for( i in 0..m) {
        val edges = In.readLine()!!.split(" ").map {it.toInt()}
        arr[edges[0]] += 1
        arr[edges[1]] += 1
    }
    arr.sortedDescending()
    if(arr[0] > 2 && arr[1] == 1 && arr[n-1] == 1)
        println("star topology")
    else if(arr[0] == 2 && arr[n-1] == 1)
        println("bus topology")
    else if(arr[0] == 2 && arr[n-1] == 2)
        println("ring topology")
    else
        println("unknown topology")
}