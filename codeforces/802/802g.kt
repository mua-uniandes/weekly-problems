
import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val In = BufferedReader(InputStreamReader(System.`in`))
    val word = In.readLine()
    tailrec fun subsq(length : Int, reminder : List<Char>) : Boolean {
        if(reminder.isEmpty())
            return true
        else if(length == word.length)
            return false
        else {
            if(word[length] == reminder.first())
                return subsq(length + 1, reminder.drop(1))
            else
                return subsq(length + 1, reminder)
        }
    }
    if(subsq(0,"heidi".toList()))
        println("YES")
    else
        println("NO")
}
