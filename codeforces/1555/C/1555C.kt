// Daniel Felipe Diaz Moreno
fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        val mat = mutableListOf<List<Int>>()
        mat.add(readLine()!!.split(" ").map { it.toInt() })
        mat.add(readLine()!!.split(" ").map { it.toInt() })

        val row1 = mutableListOf<Int>()
        val row2 = mutableListOf(0)

        var sm = 0
        for (i in 0 until n - 1) {
            sm += mat[1][i]
            row2.add(sm)
        }

        sm = 0
        for (i in (n - 1) downTo 1) {
            sm += mat[0][i]
            row1.add(sm)
        }
        row1.reverse()
        row1.add(0)

        var res = Int.MAX_VALUE
        for (i in 0 until n) {
            res = minOf(res, maxOf(row1[i], row2[i]))
        }
        println(res)
    }
}