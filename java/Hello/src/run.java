import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = {};
        HashMap<String, Integer> point = new HashMap<>();

        for (int i = 0; i < name.length; i++) {
            point.put(name[i], yearning[i]);
        }

        for (int i = 0; i < photo.length; i++) {
            int sum = 0;
            for (int j = 0; j < photo[i].length; j++) {
                sum += point.get(photo[i][j]);
            }
            answer[i] = sum;
        }

        return answer;
    }
}

public class run {
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        HashMap<String, Integer> hm_rank = new HashMap<>();
        HashMap<Integer, String> hm_p = new HashMap<>();
        for (int i = 1; i <= players.length; i++) {
            hm_rank.put(players[i - 1], i);
            hm_p.put(i, players[i - 1]);
        }
        for (int i = 0; i < callings.length; i++) {
            String tmp = callings[i];
            int rank = hm_rank.get(tmp);
            String p = hm_p.get(rank - 1);
            hm_rank.remove(tmp);
            hm_rank.remove(p);
            hm_p.remove(rank);
            hm_p.remove(rank - 1);

            hm_rank.put(tmp, rank - 1);
            hm_rank.put(p, rank);
            hm_p.put(rank - 1, tmp);
            hm_p.put(rank, p);
        }
        for (int i = 0; i < players.length; i++) {
            answer[i] = hm_p.get(i + 1);
        }
        return answer;
    }

    public static void main(String[] args) {
        run T = new run();
        Scanner kb = new Scanner(System.in);
        String[] players = {};
        String[] callings = {};
        for (int i = 0; i < 5; i++) {
            players[i] = kb.next();
        }
        for (int i = 0; i < 5; i++) {
            callings[i] = kb.next();
        }
        System.out.println(T.solution(players, callings));
    }
}
