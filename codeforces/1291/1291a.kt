import java.io.BufferedReader
import java.io.InputStreamReader


fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(i in 1..cases) {
        In.readLine()
        var number = In.readLine()!!.map { Character.getNumericValue(it) }
        var odd = number.filter { it%2 != 0 }
        if (odd.size <= 1) {
            println(-1)
            continue
        }
        print(odd[0])
        print(odd[1])
        println()
    }
}