package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main(){
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine().toInt()
    for(c in 1..cases) {
        var daughters = In.readLine().toInt()
        var d_married = IntArray(daughters + 1)
        var married = IntArray(daughters + 1)
        d_married[0] = 1
        married[0] = 1
        for(d in 1 ..daughters) {
            val princes = In.readLine().split(" ").map { it.toInt() }
            for (i in 1 until princes.size) {
                if (married[princes[i]] == 0) {
                    d_married[d] = 1
                    married[princes[i]] = 1
                    break
                }
            }
        }
            val s = d_married.indexOf(0)
            val m = married.indexOf(0)
            if(s == -1)
                println("OPTIMAL")
            else {
                println("IMPROVE")
                println("$s $m")
            }
        }
    }