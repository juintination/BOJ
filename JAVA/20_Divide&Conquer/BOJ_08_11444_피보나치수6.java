import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    final static int mod = 1000000007;

    public static long[][] matrixMult(long[][] o1, long[][] o2) {
        long[][] mat = new long[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    mat[i][j] += o1[i][k] * o2[k][j];
                    mat[i][j] %= mod;
                }
            }
        }
        return mat;
    }

    public static long[][] matrixPow(long[][] A, long exp) {
        if (exp == 1 || exp == 0) {
            return A;
        }
        long[][] mat = matrixPow(A, exp / 2);
        mat = matrixMult(mat, mat);
        if (exp % 2 == 1) {
            mat = matrixMult(mat, A);
        }
        return mat;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        long[][] A = { { 1, 1 }, { 1, 0 } };
        System.out.println(matrixPow(A, n - 1)[0][0]);
    }
}