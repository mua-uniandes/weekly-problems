
import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val n = In.readLine()!!.toInt()
    val points= MutableList(n) {listOf(-1,-1)}
    for(i in 1..n) {
        points.add(i, In.readLine()!!.split(" ").map { it.toInt() })
    }
    var answer = 0
    for(i in 1..n) {
        for(j in i+1..n) {
            if(abs(points[i][1] - points[j][1]) <= abs(points[i][0] - points[j][0]))
                answer += 1
        }
    }
    println(answer)
}