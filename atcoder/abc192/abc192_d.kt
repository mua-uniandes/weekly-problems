package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.*

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val x = In.readLine()!!
    val m = In.readLine()!!.toDouble()
    val arr = x.toCharArray()
    fun f(base: Double): Double {
        var res = 0.0
        val length = x.length
        for (i in 0 until length) {
            val value = arr[i] - '0'
            res += value * base.pow(length - 1 - i.toDouble())
        }
        return res
    }
    val d = x.toList().map { it.toString().toInt() }.reduce { acc, i -> max(i, acc) }
    if (x.length == 1 || m < d.toDouble())
        println(0)
    else {
        var low = d + 1.0
        var high = m + 1 
        var mid: Double
        while (high - low > 1) {
            mid = low + (high - low) / 2
            if (f(mid) <= m)
                low = mid
            else
                high = mid
        }
        println(low - d)
    }
}
