import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.Arrays;

public class Main {
    public static class people {
        int age;
        String name;

        public people(int age, String name) {
            this.age = age;
            this.name = name;
        }

        @Override // 메소드를 재정의(오버라이드)했다는 표식
        public String toString() { // 객체를 출력할 때 사용자의 임의로 출력하고자 하는 문자열을 지정할 수 있다
            return this.age + " " + this.name + "\n";
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());
        people[] p = new people[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            p[i] = new people(Integer.parseInt(st.nextToken()), st.nextToken());
        }
        Arrays.sort(p, new Comparator<people>() { // Comparator : 기본 정렬 기준 외에 다른 기준으로 정렬하고자 할 때 사용
            @Override // 메소드 재정의
            public int compare(Main.people p1, Main.people p2) {
                return p1.age - p2.age;
            }
        });// c의 qsort처럼 compare 함수를 이용하여 비교한다
           // 하지만 Arrays.sort는 버블정렬을 사용하기 때문에 시간이 오래 걸린다
        for (int i = 0; i < n; i++) {
            sb.append(p[i]);
        }
        System.out.println(sb.toString());
    }
}