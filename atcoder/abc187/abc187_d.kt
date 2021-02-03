import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    var totalSum : Double = 0.0
    val inc = DoubleArray(cases) {-1.0}
    for (i in 0 until cases) {
        val city = In.readLine()!!.split(" ").map {it.toDouble()}
        totalSum -= city[0]
        inc[i] = 2 * city[0] + city[1]
    }
    inc.sortDescending()
    for(i in 0 until cases) {
        totalSum += inc[i]
        if(totalSum > 0 ) {
            print(i + 1)
            break
        }
    }
}
