

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*



fun main(args: Array<String>) {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val t = br.readLine().toInt()
    for (cases in 0 until t) {
        var st = StringTokenizer(br.readLine())
        st.nextToken()
        val q = st.nextToken().toInt()
        val s = br.readLine()
        val fi = IntArray(2)
        val la = IntArray(2)
        for (j in 0..1) {
            fi[j] = 2000000000
            la[j] = -1
        }
        for (i in 0 until s.length) {
            val cur = s[i] - '0'
            fi[cur] = Math.min(fi[cur], i)
            la[cur] = i
        }
        for (i in 0 until q) {
            st = StringTokenizer(br.readLine())
            val l = st.nextToken().toInt() - 1
            val r = st.nextToken().toInt() - 1
            val curl = s[l] - '0'
            val curr = s[r] - '0'
            if (fi[curl] < l || la[curr] > r) println("YES\n") else println("NO\n")
        }
    }
}

