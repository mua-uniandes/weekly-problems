import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(t in 1..cases) {
        val N = In.readLine()!!.toInt()
        val arr = In.readLine()!!.split(" ").map { it.toDouble() }
        val max = DoubleArray(N) { 0.0 }
        for(i in N-1 downTo 0 ) {
            max[i] = arr[i]
            var j = i + arr[i]
            if(j < N)
                max[i] +=  max[j.toInt()]
        }
        max.sortDescending()
        println(max[0].toInt())
    }
}