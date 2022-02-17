package uvalive

import java.io.BufferedReader
import java.io.InputStreamReader


fun main(args: Array<String>) {
    val In = BufferedReader(InputStreamReader(System.`in`))
    var line = In.readLine()!!
    while (line != null) {
        val n = line.toInt()
        val nums = In.readLine()!!.split(" ").map { it.toInt() }
        println(getAns(nums, n))
        line = In.readLine()!!
    }
}

fun getAns(nums: List<Int>, n: Int): Int {
    // Base case
    if (n == 1) {
        return 1
    }
    // Count sequences
    val sums = ArrayList<Int>()
    var count = 1
    for (i in 1 until n) {
        if (nums[i - 1] <= nums[i]) {
            count += 1
        } else {
            sums.add(count)
            count = 1
        }
    }
    sums.add(count)
    // Get biggets 2-sum
    if (sums.size == 1) {
        return sums[0]
    }
    var ans = 0
    for (i in 0 until sums.size - 1) {
        ans = Math.max(sums[i] + sums[i + 1], ans)
    }
    return ans
}