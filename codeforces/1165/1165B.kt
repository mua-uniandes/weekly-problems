package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    In.readLine()
    val problems = In.readLine()!!.split(" ").map {it.toInt()}
    val sorted = problems.sortedBy{it}
    var pos = 1
    for(i in 1 until sorted.size) {
        if(sorted[i] >= i+1)
            pos += 1
    }
    println(pos)
}