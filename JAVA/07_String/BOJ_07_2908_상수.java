import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str1 = br.readLine();
        String str2 = br.readLine();
        StringBuffer sb1 = new StringBuffer(str1);
        StringBuffer sb2 = new StringBuffer(str2);
        str1 = sb1.reverse().toString();
        str2 = sb2.reverse().toString();
        int n1 = Integer.parseInt(str1);
        int n2 = Integer.parseInt(str2);
        if (n1 > n2) System.out.println(n1);
        else System.out.println(n2);
    }
}