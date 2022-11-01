package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val lines = In.readLine().toInt()
    var s = ""
    var s2 = ""
    var a = 0
    var b = 0
    for(i in 1..lines) {
        val team = In.readLine()
        if(s.equals("") or s.equals(team) ) {
            s = team
            a++
        }  else {
            s2 = team
            b++
        }
    }
    if (a > b)
        print(s)
    else
        print(s2)
}