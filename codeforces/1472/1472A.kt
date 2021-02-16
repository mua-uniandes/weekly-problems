import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val cases = In.readLine()!!.toInt()
    for(i in 1..cases) {
        val vals = In.readLine()!!.split(" ").map { it.toInt()}
        tailrec fun postcard(w : Int, h: Int, it: Double, count: Double) : Boolean {
            if(count >= vals[2])
                return true
            else if(w % 2 == 0)
                return postcard(w/2, h, it + 1, count + Math.pow(2.0, it-1))
            else if(h % 2 == 0)
                return postcard(w, h/2, it + 1, count + Math.pow(2.0, it-1))
            else
                return false
        }
        val ans = postcard(vals[0], vals[1], 1.0, 1.0)
        if(ans)
            println("YES")
        else
            println("NO")
    }
}