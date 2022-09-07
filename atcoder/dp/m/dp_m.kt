package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 1_000_000_007L;

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val data = In.readLine()!!.split(" ").map {it.toInt()}
    val children = In.readLine()!!.split(" ").map {it.toInt()}
    val res = Array(data[0]+1){LongArray(data[1]+1)}
    val sums = Array(data[0]+1){LongArray(data[1]+1)}
    res[0][0] = 1L
    for(i in 0..data[1]) sums[0][i] = 1L

    for(i in 1..data[0])
        for(j in 0..data[1]) {
            res[i][j] = (sums[i-1][j] - sums[i-1].getOrElse(j - children[i-1] - 1){0L}) % MOD
            sums[i][j] = sums[i].getOrElse(j-1){0L} + res[i][j]
        }

    println(res[data[0]][data[1]])
}