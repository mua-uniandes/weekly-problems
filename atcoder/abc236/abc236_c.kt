package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    In.readLine()!!
    val stations = In.readLine()!!.split(" ")
    val express = In.readLine()!!.split(" ").toSet()
    for(s in stations) {
        if (express.contains(s) )
            println("Yes")
        else
            println("No")
    }
}
