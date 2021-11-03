//package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader


fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    In.readLine()
    val array = In.readLine()!!.split(" ").map { it.toInt() }
    var count = MutableList<Int>(1000001){0}
    var left = MutableList<Int>(1000001){-1}
    var right = MutableList<Int>(1000001){-1}
    for(i in array.indices) {
        var elem = array[i]
        count[elem] += 1
        if(left[elem] == -1)  left[elem] = i
        right[elem] = i
    }
    var max = 0
    for(i in count.indices) {
        if(count[i] > count[max] || (count[i] == count[max] && right[i] - left[i] < right[max] - left[max]))
            max = i
    }
    println("${left[max] +1} ${right[max] + 1}")
}