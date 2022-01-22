import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class student implements Comparable<student> {
    String name;
    int k, e, m;

    public student(String name, int k, int e, int m) {
        this.name = name;
        this.k = k;
        this.e = e;
        this.m = m;
    }

    @Override
    public int compareTo(student o) {
        if (k != o.k) {
            return o.k - k;
        } else {
            if (e != o.e) {
                return e - o.e;
            } else {
                if (m != o.m) {
                    return o.m - m;
                } else {
                    return name.compareTo(o.name);
                }
            }
        }
    }
}

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        student[] arr = new student[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            arr[i] = new student("", 0, 0, 0);
            arr[i].name = st.nextToken();
            arr[i].k = Integer.parseInt(st.nextToken());
            arr[i].e = Integer.parseInt(st.nextToken());
            arr[i].m = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(arr);
        StringBuilder sb = new StringBuilder();
        for (student s : arr) {
            sb.append(s.name).append("\n");
        }
        System.out.print(sb);
    }
}