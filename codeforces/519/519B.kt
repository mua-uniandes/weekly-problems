
import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    In.readLine()
    val initialSum = In.readLine()!!.split(" ").map { it.toDouble() }.reduce { acc, v -> acc + v }
    val errorA = In.readLine()!!.split(" ").map { it.toDouble() }.reduce{ acc, v -> acc + v}
    val errorB = In.readLine()!!.split(" ").map { it.toDouble() }.reduce{ acc, v -> acc + v}
    println((initialSum - errorA).toInt())
    println((errorA - errorB).toInt())
}