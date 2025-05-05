 // Daniel Felipe Diaz Moreno
fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val arr = readLine()!!.split(" ").map { it.toInt() }.sortedDescending().toMutableList()
        var score = 0

        for (i in 0 until k) {
            score += arr[i + k] / arr[i]
        }
        for (i in 2 * k until arr.size) {
            score += arr[i]
        }
        println(score)
    }
}