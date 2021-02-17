import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(t in 1..cases) {
        val tiles = In.readLine()!!.split(" ").map{it.toInt()}
        val tileTypes = mutableListOf<List<List<Int>>>()
        for(n in 0 until tiles[0] ) {
            val tile1 = In.readLine()!!.split(" ").map { it.toInt() }
            val tile2 = In.readLine()!!.split(" ").map { it.toInt() }
            tileTypes.add(n, listOf(tile1, tile2))
        }
        var covered = false
        if(tiles[1] % 2 == 1)
            println("NO")
        else {
            for (i in 0 until tiles[0]) {
                if (tileTypes[i][0][1] == tileTypes[i][1][0])
                    covered = true
            }
            if (covered)
                println("YES")
            else
                println("NO")
        }
    }

}