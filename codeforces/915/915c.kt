//package codeforces


import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.system.exitProcess

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val first: MutableList<Int> = In.readLine()!!.toCharArray().map { Character.getNumericValue(it) }.toMutableList()
    val b = In.readLine()!!.toCharArray().map { Character.getNumericValue(it) }
    val a: MutableList<Int> = first.sortedDescending().toMutableList()
    val countA = IntArray(10) { 0 }
    if (b.size > first.size) {
        for (i in a)
            print(i)
        println()
    } else {
        for(i in a) countA[i] ++
        val res = mutableListOf<Int>()
        fun find(step : Int, found : Boolean): Unit {
            if(step == b.size) {
                for (i in res)
                    print(i)
                println()
                exitProcess(0)
            } else {
                var start = if(!found) b[step] else 9
                for (j in start downTo 0)
                    if (countA[j] > 0) {
                        res.add(j)
                        countA[j]--
                        find(step+1, found or (j < b[step]))
                        countA[j] ++
                        res.removeAt(res.size-1)
                    }
            }
        }
        find(0, false)
    }
}
