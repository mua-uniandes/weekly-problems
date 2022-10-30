//package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    In.readLine()!!
    val ints = In.readLine()!!.split(" ").map {it.toInt()}
    var count = 1
    var maxcount = -1
    for(i in 1 until ints.size) {
        if (ints[i] >= ints[i - 1]) {
            count += 1
            if (maxcount <= count)
                maxcount = count
    }   else {
            if(maxcount <= count)
                maxcount = count
            count = 1
        }
    }

    println(maxcount)
}