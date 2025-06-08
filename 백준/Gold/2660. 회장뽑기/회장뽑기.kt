import kotlin.math.min

fun main() {
    val br = System.`in`.bufferedReader()
    val sb = StringBuilder()
    val n = br.readLine().toInt()
    val dist = Array(n) { IntArray(n) { 123_456_789 } }
    while (true) {
        val (a, b) = br.readLine().split(" ").map { it.toInt() }
        if (a == -1 && b == -1) {
            break
        }
        dist[a - 1][b - 1] = 1
        dist[b - 1][a - 1] = 1
    }
    floyd(n, dist)
    val scoreArr = IntArray(n) { i -> dist[i].maxOf { it } }
    val minScore = scoreArr.minOf { it }
    val cnt = scoreArr.count { it == minScore }
    sb.append(minScore).append(" ").append(cnt).append("\n")
    for (i in scoreArr.indices) {
        if (scoreArr[i] == minScore) {
            sb.append(i + 1).append(" ")
        }
    }
    println(sb)
}

private fun floyd(n: Int, dist: Array<IntArray>) {
    for (k in 0 until n) {
        dist[k][k] = 0
        for (i in 0 until n) {
            for (j in 0 until n) {
                if (i == k || k == j || i == j) {
                    continue
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
            }
        }
    }
}