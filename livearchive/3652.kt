package uvalive

import java.io.BufferedReader
import java.io.InputStreamReader

var can_jump : List<List<Boolean>> = mutableListOf()


fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val energy = arrayOf(
        arrayOf(7,6,5,6,7),
        arrayOf(6,3,2,3,6),
        arrayOf(5,2,0,2,5),
        arrayOf(6,3,2,3,6),
        arrayOf(7,6,5,6,7)
    )
    val lines = In.readLines()
    do {
        val dims = In.readLine()!!.split(" ").map { it.toInt() }
        if(dims == listOf(0,0))
            break
        else {
            val toads = In.readLine().split(" ").map {it.toInt()}
            val w = In.readLine().toInt()
            var coordinates = mutableListOf<List<Int>>()
            for(i in 1..w) {
                coordinates.add(In.readLine().split(" ").map {it.toInt()})
            }
        }
    } while(true)
}

fun dijkstra(sx : Int, sy : Int, ex : Int, ey : Int) : Int {
return 0
}

fun enque(x : Int, y:Int, cost:Int) {

}

fun valid(x : Int, y : Int, X : Int, Y: Int) : Boolean {
    return if(0 <= x && x < X && 0<= y && y < Y && can_jump[x][y])
        true
    else false
}