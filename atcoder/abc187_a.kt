package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val line = In.readLine()!!.split(" ").map { it.toInt() }
    var sum1 = 0
    var sum2 = 0
    val num1 = line[0]
    val num2 = line[1]
    sum1 = num1/100 + num1/10 % 10 + num1 % 10
    sum2 = num2/100 + num2/10 % 10 + num2 % 10
    if(sum1 >= sum2)
        println(sum1)
    else
        println(sum2)
}

