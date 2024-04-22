import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(sc.hasNextInt()){
            int n = sc.nextInt();
            int k = 1;
            int cnt = 1;
            while(true){
                if(k%n == 0){
                    System.out.println(cnt);
                    break;
                }
                k = (k*10) + 1;
                k %= n;
                cnt+=1;
            }
        }
    }
}