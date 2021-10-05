import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        char chess[][] = new char[n][m];
        for (int i = 0; i < n; i++) {
            String str = br.readLine();
            for (int j = 0; j < m; j++) {
                chess[i][j] = str.charAt(j);
            }
        }
        int cnt = 0, cnt2 = 64, min = 64;
        for (int i = 0; i <= n - 8; i++) {
            for (int j = 0; j <= m - 8; j++) {
                if (chess[i][j] == 'W') {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (k % 2 != l % 2) {
                                if (chess[i + k][j + l] != 'B') {
                                    cnt++;
                                }
                            } else if (k % 2 == l % 2) {
                                if (chess[i + k][j + l] != 'W') {
                                    cnt++;
                                }
                            }
                        }
                    }
                    cnt2 = 64 - cnt;
                    cnt = Math.min(cnt, cnt2);
                    min = Math.min(min, cnt);
                    cnt = 0;
                } else if (chess[i][j] == 'B') {
                    for (int k = 0; k < 8; k++) {
                        for (int l = 0; l < 8; l++) {
                            if (k % 2 != l % 2) {
                                if (chess[i + k][j + l] != 'W') {
                                    cnt++;
                                }
                            } else if (k % 2 == l % 2) {
                                if (chess[i + k][j + l] != 'B') {
                                    cnt++;
                                }
                            }
                        }
                    }
                    cnt2 = 64 - cnt;
                    cnt = Math.min(cnt, cnt2);
                    min = Math.min(min, cnt);
                    cnt = 0;
                }
            }
        }
        bw.write(min + "");
        bw.flush();
        bw.close();
    }
}