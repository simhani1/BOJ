import java.util.*

val br = System.`in`.bufferedReader()
val sb = StringBuilder()
val map = HashMap<String, Int>()
val dx = arrayOf(0, 0, -1, 1)
val dy = arrayOf(-1, 1, 0, 0)
var goal = String()

fun main() {
    for (i in 0 until 3) {
        goal += br.readLine().replace(" ", "")
    }
    println(bfs("123456780"))
}

private fun bfs(start: String): Int {
    val q: Queue<String> = ArrayDeque()
    q.offer(start)
    map.put(start, 0)
    while (!q.isEmpty()) {
        val now = q.poll()
        val cnt = map[now]!!
        if (now.equals(goal)) {
            return cnt
        }
        val nowX = now.indexOf('0') / 3
        val nowY = now.indexOf('0') % 3
        for (i in 0 until 4) {
            val nextX = nowX + dx[i]
            val nextY = nowY + dy[i]
            if (!(0 <= nextX && nextX < 3 && 0 <= nextY && nextY < 3)) {
                continue
            }
            val tmp = now[nextX * 3 + nextY]
            var next = String()
            next = now.replace(tmp, 'X')
            next = next.replace('0', tmp)
            next = next.replace('X', '0')
            if (map.containsKey(next)) {
                continue
            }
            map.put(next, cnt + 1)
            q.offer(next)
        }
    }
    return -1;
}