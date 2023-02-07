package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val word = In.readLine()
    if (word.contains("h.*e.*l.*l.*o.*".toRegex()))
        println("YES")
    else
        println("NO")
}