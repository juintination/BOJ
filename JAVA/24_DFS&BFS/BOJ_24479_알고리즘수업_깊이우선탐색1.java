import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Main {

    static int n, m, r, cnt = 1;
    static int[] sequence;
    static boolean[] visited;
    static ArrayList<Integer>[] list;

    public static void dfs(int value) {
        visited[value] = true; // 해당 정점 방문 여부 체크
        sequence[value] = cnt++; // 해당 정점의 방문 순서 체크
        for (int e : list[value]) { // 해당 정점의 리스트의 원소 e
            if (!visited[e]) { // 정점 e를 방문하지 않았다면
                dfs(e); // 정점 e로 이동
            }
        }
    }

    @SuppressWarnings("unchecked")
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken()); // 정점의 수
        m = Integer.parseInt(st.nextToken()); // 간선의 수
        r = Integer.parseInt(st.nextToken()); // 시작 정점
        visited = new boolean[n + 1]; // 방문 여부 확인 배열
        list = new ArrayList[n + 1]; // 1부터 n까지의 정점 리스트
        sequence = new int[n + 1]; // 각 정점의 방문 순서 배열
        Arrays.fill(sequence, 0); // sequence 배열 초기화
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<Integer>(); // 각 정점의 리스트 선언
        }
        while (m-- > 0) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            list[x].add(y); // x 리스트에 y 추가
            list[y].add(x); // y 리스트에 x 추가
        }
        for (int i = 1; i <= n; i++) {
            Collections.sort(list[i]); // 각 리스트의 원소 정렬
        }
        dfs(r); // 시작 정점 r 부터 dfs 실행
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            sb.append(sequence[i]).append("\n"); // 각 정점의 방문 순서 sb에 추가
        }
        System.out.print(sb); // sb 출력
    }
}