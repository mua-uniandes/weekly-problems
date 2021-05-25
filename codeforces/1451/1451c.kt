

import java.io.BufferedReader
import java.io.InputStreamReader


fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val t = br.readLine().toInt()
    for (cases in 0 until t) {
        val params = br.readLine().split(" ").map { it.toInt() }
        val n = params[0]
        val k = params[1]
        val a = br.readLine()
        val b = br.readLine()
        val have = IntArray(26)
        val need = IntArray(26)
        for (i in 0 until n) {
            have[a[i] - 'a']++
            need[b[i] - 'a']++
        }
        var bad = false
        for (j in 24 downTo 0) {
            have[j] += have[j + 1]
            need[j] += need[j + 1]
            if (have[j] > need[j] || (need[j] - have[j]) % k != 0) bad = true
        }
        if (bad) println("No") else println("Yes")
    }
}
