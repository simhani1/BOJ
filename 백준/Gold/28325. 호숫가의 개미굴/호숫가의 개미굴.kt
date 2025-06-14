import java.util.*

val br = System.`in`.bufferedReader()
val sb = StringBuilder()

fun main() {
    val N = br.readLine().toInt()
    val arr = LongArray(N)
    val list = ArrayList<Int>()
    val st = StringTokenizer(br.readLine())
    var ans = 0L
    for (i in 0 until N) {
        arr[i] = st.nextToken().toLong()
        if (arr[i] > 0) {
            ans += arr[i]
            list.add(i)
        }
    }
    if (ans == 0L) {
        println(N / 2)
        return
    }
    for (i in 0 until list.size) {
        if (i == list.size - 1) {
            ans += (N - (list[i] - list[0])) / 2L
        } else {
            ans += (list[i + 1] - list[i]) / 2L
        }
    }
    println(ans)
}