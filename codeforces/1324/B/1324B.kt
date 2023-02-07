package codeforces

import java.io.BufferedReader
import java.io.InputStreamReader

tailrec fun palindrome(head : String , tail : List<String>) : Boolean {
    return if(tail.isEmpty())
        return false;
    else if(tail.first() == head)
        true;
    else
        palindrome(head, tail.drop(1))
}

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val t = In.readLine().toInt()
    for( i in 1..t) {
       In.readLine()
       var res = "NO"
       val s = In.readLine().split(" ").toList()
       for(c in s){
           if(palindrome(c, s.drop(2)))
               res = "YES"
               break
       }
       println(res)
    }
}