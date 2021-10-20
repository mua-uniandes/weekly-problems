package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val s = In.readLine()!!
    var ws = 0.0
    var os = 0.0
    var count = 0.0
    for (i in s.indices) {
        if (s[i] == 'o') {
            os += ws
        } else if (i > 0 && s[i - 1] == 'v') {
            ws++
            count += os
        }
    }
    println(count)
}