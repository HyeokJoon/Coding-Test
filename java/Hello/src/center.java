import java.util.*;

public class center {
    public String solution(String s) {
        var answer = "";
        int l = s.length();
        // System.out.println(l);
        char[] c = s.toCharArray();
        int lt = 0;
        int rt = l - 1;
        while (lt < rt) {
            lt++;
            rt--;
        }
        answer = s.substring(rt, lt + 1);

        return answer;
    }

    public static void main(String[] args) {
        center T = new center();
        Scanner kb = new Scanner(System.in);
        String str = kb.next();
        System.out.println(T.solution(str));
    }
}
