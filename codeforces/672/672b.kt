package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val see = br.readLine()
    if(n > 26)
        println("-1")
    else {
        val letters = IntArray(26) {0}
        for (let in see){
            ++letters[let - 'a'];
        }
        var ans = 0
        for (i in 0 until 26)
            ans += Math.max(letters[i] - 1, 0)

        println(ans)
    }
}