package codechef

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In =  BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(i in 1..cases) {
        var count = 0
        val nums = In.readLine()!!.split(" ").map { it.toInt() }
        for(num in nums[0]..nums[1]) {
            if(num % 10 == 2 || num%10 == 3 || num%10 == 9) {
                count++
            }
        }
        println(count)
    }
}