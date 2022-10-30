package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val nums = In.readLine().split(" ").map { it.toInt() }
    if (nums.reduce {acc, x -> x + acc} % 2 != 0)
        println("Impossible")
    else {
        val x = (nums[1] + nums[2] - nums[0])/2
        val y = (nums[2] + nums[0] - nums[1])/2
        val z = (nums[1] + nums[0] - nums[2])/2
        if((nums[1] + nums[0] >= nums[2]) and (nums[2] + nums[0] >= nums[1]) and (nums[1] + nums[2] >= nums[0]))
            println("$z $x $y")
        else
            println("Impossible")
    }
}