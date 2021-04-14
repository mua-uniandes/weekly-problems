import java.io.BufferedReader
import java.io.InputStreamReader

fun main()
{
    val In = BufferedReader(InputStreamReader(System.`in`))
    val numero = In.readLine()
    var decs = "0"
    decs = if(numero.toInt() >= 10)
    {
        numero[numero.length-2] + numero[numero.length-1].toString()
    }
    else {
        numero
    }
    println(100-decs.toInt())
}