package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val N = In.readLine()!!.toInt()
    val a = In.readLine()!!.split(" ").map {it.toLong()}
    val dp = Array(N+1){0L}
    dp[0] = 0L
    var first = 0
    var last = N-1
    for(i in 1..N)
         if(i % 2 == 0) {
             if(a[first] == min(dp[i - 1] - a[first], dp[i-1] - a[last])) {
                 dp[i] = dp[i - 1] - a[first]
                 first += 1
             } else {
                     dp[i] = dp[i - 1] - a[last]
                     last -= 1
             }
         } else {
             if(a[first] == Math.max(dp[i - 1] - a[first], dp[i-1] - a[last])) {
                 dp[i] = dp[i - 1] + a[first]
                 first += 1
             } else {
                 dp[i] = dp[i - 1] + a[last]
                 last -= 1
             }
         }

    println(Math.abs(dp[N]))
}