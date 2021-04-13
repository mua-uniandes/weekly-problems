package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val input = In.readLine().split(" ").map{ it.toInt()}
    fun g1(n : String) : Int {
        var array = n.toCharArray()
        array.sortDescending()
        return array.joinToString("").toInt()
    }
    fun g2(n : String) : Int {
        var array = n.toCharArray()
        array.sort()
        return array.joinToString("").toInt()
    }
    fun f(number : String) : Int {
        return g1(number) - g2(number)
    }
    val a = IntArray(input[1]+1)
    a[0] = input[0]
    for(i in 1..input[1]) {
        a[i] = f(a[i-1].toString())
    }
    println(a[input[1]])
}