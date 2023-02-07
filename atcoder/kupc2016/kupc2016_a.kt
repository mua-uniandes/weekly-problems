package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val params = In.readLine()!!.split(" ").map { it.toInt()}
    val timeSlots = mutableSetOf<Int>()
    for(i in 0 until params[0]) {
        timeSlots.add(In.readLine()!!.toInt())
    }
    var count = 0
    for(a in timeSlots) {
        if(a < params[1] || a >= params[2])
            count ++
    }
    println(count)
}