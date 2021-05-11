import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(i in 1..cases) {
        val n = In.readLine()!!.toInt()
        val numbers = In.readLine()!!.split(" ").map { it.toInt() }
        val odd = numbers.filter { elem -> elem % 2 == 1 }
        val even = numbers.filter { elem -> elem % 2 == 0 }
        if(even.size > 0) {
           println(1)
           println(numbers.indexOf(even[0])+1)
        } else if(odd.size > 1) {
            println(2)
            println("${numbers.indexOf(odd[0])+1} ${numbers.lastIndexOf(odd[1])+1}")
        } else
            println(-1)
    }
}