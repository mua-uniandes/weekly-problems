import java.io.BufferedReader
import java.io.InputStreamReader

import java.awt.geom.Line2D;

data class Vector(val x : Double, val y : Double) {
    val norm = Math.sqrt(x*x + y*y)

}

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val pizzas = In.readLine()!!.split(" ").map{x -> x.toInt()}
    val cases = In.readLine()!!.toInt()
    var crust = 0
    for(i in 1..cases) {
        val circ = In.readLine()!!.split(" ").map{x -> x.toDouble()}
        val v = Vector(circ[0], circ[1])
        if(v.norm - pizzas[0] + pizzas[1] >= circ[2] && circ[2] + v.norm  <= pizzas[0]) {
            crust ++
        }

    }
    println(crust)
}