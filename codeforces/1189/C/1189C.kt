import kotlin.math.*

fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!.split(" ").map { it.toInt() }.toIntArray()

    val dp = Array(25) { mutableListOf<Pair<Int, Int>>() }

    for (i in 0 until n) {
        dp[0].add(Pair(s[i], 0))
    }

    var lng = 1
    for (i in 1 until 20) {
        lng *= 2
        for (j in 0 until n - lng + 1) {
            val dulces1 = dp[i - 1][j].second
            val dulces2 = dp[i - 1][j + lng / 2].second
            val digito1 = dp[i - 1][j].first
            val digito2 = dp[i - 1][j + lng / 2].first

            val res = dulces1 + dulces2 + ((digito1 + digito2) / 10)
            val digito = (digito1 + digito2) % 10
            dp[i].add(Pair(digito, res))
        }
    }

    val q = readLine()!!.toInt()
    for (i in 0 until q) {
        val (l, r) = readLine()!!.split(" ").map { it.toInt() }
        var lng = r - l + 1
        var deg = 0
        while (lng % 2 == 0) {
            deg++
            lng /= 2
        }

        println(dp[deg][l - 1].second)
    }
}
