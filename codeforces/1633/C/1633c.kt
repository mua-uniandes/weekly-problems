package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.ceil
import kotlin.math.floor

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(i in 1..cases) {
        val c = In.readLine()!!.split(" ").map { it.toDouble() }
        val m = In.readLine()!!.split(" ").map { it.toDouble() }
        val coins = In.readLine()!!.split(" ").map { it.toDouble() }
        var found = false
        for(j in 1..coins[0].toInt()) {
            if(ceil((m[1]/j*coins[2] + c[0])) >= ceil((c[1] + j*coins[1])/c[1])) {
                println("YES")
                found = true
                break
            }
        }
        if(!found) {
            print("NO")
        }
    }
}