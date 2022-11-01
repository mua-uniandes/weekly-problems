package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val test = In.readLine().toInt()

    tailrec fun sol(l : List<Char>, count : Int, ans : Int) : Int  {
        if(l.isEmpty())
            return ans
        else {
            val h = l.first()
            if (h == '(')
                return sol(l.drop(1), count + 1, ans)
            else {
                if (count - 1 == -1)
                   return sol(l.drop(1), 0, ans + 1)
                else
                   return  sol(l.drop(1), count - 1, ans)
            }
        }
    }

    for(i in 1..test) {
        In.readLine()
        val paren = In.readLine().toList()
        println(sol(paren, 0, 0))
    }
}