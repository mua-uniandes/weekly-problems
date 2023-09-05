fun main() {
    var f = Array(31, ){_ -> 0}

    f[0]=1
    f[1]=0
    f[2]=3
    f[3]=0

    for(i in 4 until f.size) {
        f[i] = f[i-2] * 4 - f[i-4]
    }

    val In = BufferedReader(InputStreamReader(System.`in`))
    var n = In.readLine().toInt()
    while(n != -1) {
        println(f[n])
        n = In.readLine().toInt()
    }
}