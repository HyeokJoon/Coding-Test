
//문자열 공백으로 문자 구분하기 
import java.util.*;

public class tc {
    public String solution(String str) {
        String answer = "";
        int m = Integer.MIN_VALUE;
        int pos;
        while ((pos = str.indexOf(' ')) != -1) {
            String tmp = str.substring(0, pos);
            int len = tmp.length();
            if (len > m) {
                m = len;
                answer = tmp;
            }
            str = str.substring(pos + 1);
        }
        if (str.length() > m) {
            answer = str;
        }

        /*
         * str.split을 사용하는 방법
         * String[] s = str.split(" ");
         * for (String x : s) {
         * int len = x.length();
         * if (len > m) {
         * m = len;
         * answer = x;
         * }
         * }
         */
        return answer;
    }

    public static void main(String[] args) {
        tc T = new tc();
        Scanner kb = new Scanner(System.in);
        String str = kb.nextLine();
        System.out.print(T.solution(str));
    }
}
