package atcoder

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val s = In.readLine().toCharArray()
    var difficult = true
    var i = 0
    while(i < s.size && difficult) {
        if(i%2 == 1) {
            if (s[i] > 'Z')
                difficult = false
        } else {
            if (s[i] < 'a')
                difficult = false
        }
        i += 1
    }
    if(difficult)
        println("Yes")
    else
        println("No")
}