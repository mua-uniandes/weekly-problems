import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(i in 1..cases) {
        var n = In.readLine()!!.toInt()
        val weights = In.readLine()!!.split(" ").map {it.toInt()}
        val ones = weights.filter { it == 1 }.size
        val twos = n - ones
        if(twos % 2 == 0 && ones % 2 == 0)
                println("YES")
        else if(twos % 2 == 1 && ones - 2 >= 0 && (ones - 2) % 2 == 0)
                println("YES")
        else
            println("NO")
    }
}