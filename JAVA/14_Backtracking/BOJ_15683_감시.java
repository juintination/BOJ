import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.StringTokenizer;

class cctv {
    int x, y, num;

    public cctv(int x, int y, int num) {
        this.x = x;
        this.y = y;
        this.num = num;
    }
}

public class Main {

    static int n, m, min;
    static int[] directed;
    static int[][] arr, tmp;
    static ArrayList<cctv> list;
    public static int[] dx = { -1, 0, 1, 0 };
    public static int[] dy = { 0, -1, 0, 1 };

    public static void searched(cctv cam, int i) {
        Queue<cctv> queue = new LinkedList<>();
        queue.offer(cam);
        while (!queue.isEmpty()) {
            cctv c = queue.poll();
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (tmp[nx][ny] == 0) {
                    tmp[nx][ny] = -1;
                    queue.offer(new cctv(nx, ny, cam.num));
                } else if (tmp[nx][ny] != 6) {
                    queue.offer(new cctv(nx, ny, cam.num));
                }
            }
        }
    }

    public static void observed(cctv cam, int d) {
        if (cam.num == 1) {
            searched(cam, d);
        } else if (cam.num == 2) {
            if (d == 0) {
                searched(cam, 0);
                searched(cam, 2);
            } else if (d == 2) {
                searched(cam, 1);
                searched(cam, 3);
            }
        } else if (cam.num == 3) {
            searched(cam, d);
            searched(cam, (d + 1) % 4);
        } else if (cam.num == 4) {
            searched(cam, d);
            searched(cam, (d + 1) % 4);
            searched(cam, (d + 2) % 4);
        } else if (cam.num == 5) {
            for (int i = 0; i <= 3; i++) {
                searched(cam, i);
            }
        }
    }

    public static void dfs(int dpth) {
        if (dpth == list.size()) {
            for (int i = 0; i < n; i++) {
                tmp[i] = arr[i].clone();
            }
            for (int i = 0; i < list.size(); i++) {
                observed(list.get(i), directed[i]);
            }
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (tmp[i][j] == 0) {
                        cnt++;
                    }
                }
            }
            min = Math.min(min, cnt);
            return;
        }
        int camNum = list.get(dpth).num;
        for (int i = 0; i < 4; i++) {
            directed[dpth] = i;
            dfs(dpth + 1);
            if (camNum == 2) {
                i++;
            } else if (camNum == 5) {
                break;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n][m];
        tmp = new int[n][m];
        list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] != 0 && arr[i][j] != 6) {
                    list.add(new cctv(i, j, arr[i][j]));
                }
            }
        }
        directed = new int[list.size()];
        min = Integer.MAX_VALUE;
        dfs(0);
        System.out.println(min);
    }
}