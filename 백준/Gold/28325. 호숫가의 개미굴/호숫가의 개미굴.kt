import kotlin.math.max

val br = System.`in`.bufferedReader()
val sb = StringBuilder()

fun main() {
    val N = br.readLine().toInt()
    val arr = br.readLine().split(" ").map { it.toLong() }.toLongArray()
    val dp = Array(N + 1) { LongArray(2) }
    dp[1][0] = 1L
    dp[1][1] = arr[0]
    for (i in 2..N) {
        dp[i][0] = dp[i - 1][1] + 1
        if (arr[i - 1] != 0L) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i - 1]
        } else {
            dp[i][1] = dp[i][0] - 1
        }
    }
    println(max(dp[N][0], dp[N][1]))
}