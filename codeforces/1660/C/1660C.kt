// Daniel Felipe Diaz Moreno
fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val s = readLine()!!
        val visited = mutableSetOf<Char>()
        var res = 0
        for (c in s) {
            if (c in visited) {
                visited.clear()
                res += 2
            } else {
                visited.add(c)
            }
        }
        res = s.length - res
        println(res)
    }
}