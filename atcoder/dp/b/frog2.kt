import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.*

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val input = In.readLine()!!.split(" ").map { it.toInt() }
    val n = input[0]
    val k = input[1]
    val arr = In.readLine()!!.split(" ").map { it.toInt() }
    val mins = IntArray(n){ Int.MAX_VALUE}
    var pos = n-1
    mins[pos] = 0
    while(pos > 0) {
        val root = arr[pos]
        var x = pos - 1
        while(x >= 0 && x >= pos - k) {
            mins[x] = min(mins[x], mins[pos] + abs(arr[x] - root))
            x --
        }
        pos--
    }
    println(mins[0])
}
