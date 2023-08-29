import java.util.*;

public class Sqrt {
    public long solution(int r1, int r2) {
        long answer = 0;
        int count = 0;
        Sqrt T = new Sqrt();
        for (int x = 1; x < r2; x++) {
            double dy = T.calc(r1, r2, x);
            count += dy;
        }
        count += 2;
        answer = 4 * count;
        return answer;
    }
    element

    public double calc(int r1, int r2, int x) {
        double y1 = Math.sqrt((r1 * r1) - (x * x));
        if (y1 < 0)
            y1 = 0;
        double y2 = Math.sqrt((r2 * r2) - (x * x));
        return y2 - y1;
    }

    public static void main(String[] args) {
        Sqrt T = new Sqrt();
        Scanner kb = new Scanner(System.in);
        int r1 = Integer.valueOf(kb.next());
        int r2 = Integer.valueOf(kb.next());
        System.out.println(T.solution(r1, r2));
    }

}
