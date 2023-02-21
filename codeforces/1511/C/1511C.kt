//package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val q = In.readLine().split(" ").map { it.toInt() }[1]
    var pos = List(51){0}.toMutableList()
    val nums = In.readLine().split(" ").map {it.toInt()}
    for (i in 0 until nums.size) {
        val c = nums[i]
        if (pos[c] == 0)
            pos[c] = i + 1
    }
    val queries = In.readLine().split(" ").map {it.toInt()}
    for(t in queries) {
        print("${pos[t]} ")
        pos = pos.map {x : Int -> if(pos[t] < x || x == 0) x else x + 1}.toMutableList()
        pos[t] = 1
    }
}