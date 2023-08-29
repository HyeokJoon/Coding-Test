import java.util.*;

public class reverse {
    public ArrayList<String> solution(int n, String[] str) {
        ArrayList<String> answer = new ArrayList<>();

        for (String x : str) {
            char[] s = x.toCharArray();
            int lt = 0;
            int rt = x.length() - 1;
            char tmp;
            while (lt < rt) {
                tmp = s[rt];
                s[rt] = s[lt];
                s[lt] = tmp;
                lt++;
                rt--;
            }
            answer.add(String.valueOf(s));
        }

        /*
         * StringBuilder 이용방법
         * for (String x : str) {
         * String tmp = new StringBuilder(x).reverse().toString();
         * answer.add(tmp);
         * }
         */

        return answer;
    }

    public static void main(String[] args) {
        reverse T = new reverse();
        Scanner kb = new Scanner(System.in);
        int n = kb.nextInt();
        String[] str = new String[n];
        for (int i = 0; i < n; i++) {
            str[i] = kb.next();
        }
        for (String x : T.solution(n, str)) {
            System.out.println(x);
        }
    }
}
