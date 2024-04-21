import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] num = new int[n];
        for(int i=0;i<n;i++){
            num[i] = Integer.parseInt(st.nextToken());
        }

        // 재료 정렬
        Arrays.sort(num);

        int cnt=0;
        int left = 0;
        int right = n-1;
        while(left < right){
            if(num[left] + num[right] == m){
                cnt+=1;
                left +=1;
                right-=1;
            }
            else if(num[left] + num[right] < m){
                left+=1;
            }
            else if(num[left] + num[right] > m){
                right-=1;
            }
        }

        System.out.println(cnt);
        br.close();
    }
}