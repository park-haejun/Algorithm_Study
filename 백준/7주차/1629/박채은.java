import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();

        System.out.println(pow(A,B,C));
    }

    static long pow(int a, int b, int mod){
        if(b==0) return 1;

        long result = pow(a ,b/2, mod);
        if(b%2 == 1){ // 홀수
            return (result * result % mod) * a % mod;
            // return (result * result % mod) * (a % mod)
            // 위처럼 괄호를 쳤다가 틀렸다.
        }
        else{ // 짝수
            return (result * result % mod);
        }
    }
}