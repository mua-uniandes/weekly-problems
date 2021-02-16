import java.io.BufferedReader
import java.io.InputStreamReader
 
fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
 
    In.readLine()!!.toInt()
    val planes = In.readLine()!!.split(" ").map {it.toInt() - 1}
    triangle(planes, 0)
}
 
fun triangle(nodes : List<Int>, count : Int) {
    if(count == nodes[nodes[nodes[count]]]) {
        println("YES")
        return
    } else if(count == nodes.size -1){
        println("NO")
        return
    } else {
        return triangle(nodes, count+1)
    }
}