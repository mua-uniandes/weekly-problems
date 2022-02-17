package codechef

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()


    (1..cases).forEach {
        val nodes = In.readLine()!!.toInt()
        tailrec fun child(nodes : Int, children : Int) : Int {
            if(nodes <= 6)
                return children
            else {
                val possible = Math.floorDiv(nodes, 2)
                return child(Math.floorDiv(nodes, 2), children + Math.floorDiv(nodes, 2))
            }
        }
        (1..nodes).forEach { In.readLine() }
        println(child(nodes, nodes))
    }
}
