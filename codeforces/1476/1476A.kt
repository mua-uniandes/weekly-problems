package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.floor

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(i in 1 .. cases) {
        val line = In.readLine()!!.split(" ").map { it.toDouble() }
        val n = line[0]
        val k = line[1]
        val maxDivisible = floor((n+k-1)/k)
        println(floor((maxDivisible*k + n - 1)/n))
    }
}