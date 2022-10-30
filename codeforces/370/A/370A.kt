package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader


fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val nums = In.readLine().split(" ").map { it.toInt() }
    val r1 = nums[0]
    val c1 = nums[1]
    val r2 = nums[2]
    val c2 = nums[3]
    val rook = if (r1 == r2 || c1 == c2) 1 else 2

    val bishop = if ((r1 + c1) % 2 != (r2 + c2) % 2)  0 else {
        if (r1 + c1 == r2 + c2 || r1 - c1 == r2 - c2) 1 else  2
    }
    val king = Math.max(Math.abs(r1 - r2), Math.abs(c1 - c2))
    println("$rook $bishop $king")
}