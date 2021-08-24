package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val x = In.readLine()!!
    val y = In.readLine()!!
    for(i in 0 until x.length) {
        if(x[i] < y[i]) {
            println(-1)
            System.exit(0)
        }
    }
    print(y)
}