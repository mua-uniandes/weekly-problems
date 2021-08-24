package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.ceil


fun main() {
        val In = BufferedReader(InputStreamReader(System.`in`))
        val cases = In.readLine()!!.toInt()
        for(i in 1..cases) {
            val ints = In.readLine()!!.split(" ").map {it.toDouble()}
            val a = ints[0]
            val b = ints[1]
            val c = ints[2]
            val d = ints[3]
            if(b >= a) println(b.toInt())
            else if(c-d <= 0) println(-1)
            else println((b + c*ceil((a-b)/(c-d))).toInt())
        }
}