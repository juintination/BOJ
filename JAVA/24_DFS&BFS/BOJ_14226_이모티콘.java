import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

class emoticon {
    int screen;
    int clipboard;
    int cnt;

    public emoticon(int screen, int clipboard, int cnt) {
        this.screen = screen;
        this.clipboard = clipboard;
        this.cnt = cnt;
    }
}

public class Main {

    static int s, result;
    static boolean[][] visited = new boolean[1001][1001];

    public static void bfs() {
        Queue<emoticon> queue = new LinkedList<emoticon>();
        queue.offer(new emoticon(1, 0, 0));
        visited[1][0] = true;
        while (!queue.isEmpty()) {
            emoticon e = queue.poll();
            if (e.screen == s) {
                result = e.cnt;
                return;
            }
            if (!visited[e.screen][e.screen]) { // copy
                queue.offer(new emoticon(e.screen, e.screen, e.cnt + 1));
                visited[e.screen][e.screen] = true;
            }
            if (e.clipboard != 0 && e.screen + e.clipboard <= 1000 && !visited[e.screen + e.clipboard][e.clipboard]) { // paste
                queue.offer(new emoticon(e.screen + e.clipboard, e.clipboard, e.cnt + 1));
                visited[e.screen + e.clipboard][e.clipboard] = true;
            }
            if (e.screen > 0 && !visited[e.screen - 1][e.clipboard]) { // delete
                queue.offer(new emoticon(e.screen - 1, e.clipboard, e.cnt + 1));
                visited[e.screen - 1][e.clipboard] = true;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        s = Integer.parseInt(br.readLine());
        bfs();
        System.out.println(result);
    }
}