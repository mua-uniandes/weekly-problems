package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    var s = In.readLine()!!.toMutableList()
    val nums = In.readLine()!!.split(" ").map { it.toInt() }
    val temp = s[nums[0]-1]
    s[nums[0]-1] = s[nums[1]-1]
    s[nums[1]-1] = temp
    println(s)
}

