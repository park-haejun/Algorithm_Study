import java.io.*;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int cnt = 0;

        for(int i=0;i<n;i++){
            String s = br.readLine();
            Stack<Character> st = new Stack<>();

            for(int j=0;j<s.length();j++){
                if(st.size() == 0 || st.peek() != s.charAt(j)){
                    st.push(s.charAt(j));
                }
                else if(st.peek() == s.charAt(j)){
                    st.pop();
                }
            }
            // stack이 빈 경우 = 좋은 단어
            if(st.size() == 0){
                cnt+=1;
            }
        }

        System.out.println(cnt);
    }
}