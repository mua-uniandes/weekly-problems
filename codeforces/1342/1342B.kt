package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(i in 1..cases) {
        val t = In.readLine()!!.toCharArray()
        val s = t.distinct().joinToString("").repeat(t.size)
        println(s)
    }
}