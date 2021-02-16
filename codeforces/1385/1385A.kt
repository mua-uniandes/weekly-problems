import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(i in 1..cases) {
        val line = In.readLine()!!.split(" ").map { it.toInt() }
        val nums = line.sorted()
        if(nums[1] != nums[2])
            println("NO")
        else {
            println("YES")
            println("${nums[0]} ${nums[0]} ${nums[2]}")
        }
    }
}