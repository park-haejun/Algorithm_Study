import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String name = br.readLine();
        int[] alpha = new int[26];
        int len = name.length();

        for(int i=0; i<len; i++) {
            alpha[name.charAt(i)-'A']+=1;
        }

        int check =0;
        for(int i=0; i<26; i++) {
            if(alpha[i] %2 !=0) check+=1;
        }

        if((len%2 == 0 && check>=1) || (len%2 == 1 && check>1)){
            System.out.println("I'm Sorry Hansoo");
            return;
        }

        String answer ="";
        String mid = "";
        StringBuilder sb = new StringBuilder();

        for(int i=0; i<26; i++) {
            if(alpha[i]%2 == 1){
                mid = String.valueOf((char)('A'+i));
            }
            for(int j=0; j<alpha[i]/2; j++) {
                sb.append((char)(i+65));
            }
        }
        answer += sb.toString();
        String rev = sb.reverse().toString();

        if(mid.equals("")){
            answer += rev;
        }
        else{
            answer += mid +rev;
        }
        System.out.println(answer);
    }
}