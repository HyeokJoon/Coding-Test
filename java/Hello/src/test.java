import java.util.*;

public class test {
    public int solution(String str, char t) {
        int answer = 0;
        str = str.toUpperCase();
        t = Character.toUpperCase(t);
        // System.out.println(str + " " + t);
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == t) {
                answer++;
            }
        }
        return answer;
    }

    public static void main(String[] args) throws Exception {
        test T = new test();
        Scanner kb = new Scanner(System.in);
        String str = kb.next();
        char c = kb.next().charAt(0);

        System.out.print(T.solution(str, c));
    }
}
