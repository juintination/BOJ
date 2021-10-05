import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static int fibo(int num) throws IOException {
        if (num == 0) return 0;
        else if (num == 1) return 1;
        else return fibo(num - 1) + fibo(num - 2);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        System.out.print(fibo(n));
    }
}