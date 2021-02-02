/*
    @author: Nicolas Cardozo
    @complexity: O(1) for each test case
    @time:
    @memory: 
 */

import java.io.BufferedReader
import java.io.InputStreamReader

fun main(args : Array<String>) {
    val In = BufferedReader(InputStreamReader(System.`in`))
    while(true) {
        val lengths = In.readLine().split(" ").map{x -> x.toInt()}.toMutableList()
        if(lengths[0] == 0 && lengths[1] == 0 && lengths[2]==0) {
            break
        } else {
            lengths.sort()
            if(lengths[0]*lengths[0] + lengths[1]*lengths[1] == lengths[2]*lengths[2]) {
                println("right")
            } else {
                println("wrong")
            }
        }
    }
}