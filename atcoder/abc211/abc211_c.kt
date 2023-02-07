package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.*

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val mod = 1e9 + 7
    val s = In.readLine()!!
    val t = "chokudai"
    val dp = Array(s.length){Array(t.length){0.0}}
    for(i in s.indices) {
        for(j in t.indices) {
            if(j==0)
                dp[i][j] = 1.0
            if(i==0 && j>=1 && j<=8)
                dp[i][j] = 0.0
            if(i>=1 && i <= s.length && j>=1 && j<=8 && s[i] != t[j])
                dp[i][j] = dp[i-1][j]
            if(i>=1 && i <= s.length && j>=1 && j<=8 && s[i] == t[j])
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
        }
    }
    println(dp[s.length-1][t.length-1] % mod)
}