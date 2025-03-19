import java.io.BufferedReader
import java.io.InputStreamReader


fun main(args: Array<String>) {

    val br = BufferedReader(InputStreamReader(System.`in`))
    val N = br.readLine().toInt()

    if (N % 2 != 0) {
        println(0)
        return
    }

    val dp = IntArray(N + 1)
    dp[0] = 1;
    dp[2] = 3;
    for (i in 4..N step 2) {
        dp[i] = dp[i - 2] * 3
        for (j in 4..N step 2) {
            if (i - j >= 0) {
                dp[i] += (dp[i - j] * 2)
            }
        }
    }

    println(dp[N])
}