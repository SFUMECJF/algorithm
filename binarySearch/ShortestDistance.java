import java.util.ArrayList;
import java.util.Scanner;

public class ShortestDistance {
    boolean check(int mid, int n, int k, ArrayList<Integer> lst2){
        int sum = lst2.get(0);
        int h = k - 1;
        int i = 0;
        while(i < n-1){
            i++;
            if(lst2.get(i) - sum > mid){
                i--;
                sum = lst2.get(i);
                h --;
            }

        }
        return h >= 0;
    }
    int Distance(){
        Scanner sc = new Scanner(System.in);
        String init = sc.nextLine();
        ArrayList<Integer> lst = new ArrayList<Integer>();
        for(String a:init.split(" ",2)){
            lst.add(Integer.parseInt(a));
        }
        ArrayList<Integer> lst2 = new ArrayList<Integer>();
        int low = 1;
        int high= 0;
        for(int i = 0;i < lst.get(0);i++){
            int a = sc.nextInt();
            lst2.add(a);
            if(a >= high){
                high = a;
            }
        }
        high *= 2;
        int res = 0;
        while(low <= high){
            int mid = (low + high)>>1;
            if(check(mid,lst.get(0),lst.get(1),lst2)){
                high = mid - 1;
                res = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return res;

    }
    public static void main(String args[]){
        ShortestDistance s = new ShortestDistance();
        System.out.println(s.Distance());
    }
}
