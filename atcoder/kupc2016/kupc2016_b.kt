package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val params = In.readLine()!!.split(" ").map { it.toInt()}
    val n = params[0]
    val k = params[1]

    val problems = mutableMapOf<Int, Int>()
    for(i in 0 until n) {
        val name = In.readLine()!!.toCharArray()[0].toInt()
        val prev = problems.getOrDefault(name-65, 0)
        problems.put(name-65, prev+1)
    }

    if(problems.size < k)
        println(0)
    else {
        var count = 0
        var possible = true
        var group  = k
        var ordered = problems.values.sortedDescending().toMutableList()
        while(possible) {
           // possible = false
            ordered = problems.values.sortedDescending().toMutableList()
            var seen = 0
            for(i in ordered.size-1 downTo 0) {
                if(ordered[i] > 0)
                    ordered[i] --
                seen ++
            }
            possible = (seen == k)
            if(possible) count ++
        }
        println(count)
    }
}

