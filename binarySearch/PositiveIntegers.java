import java.util.ArrayList;
import java.util.Scanner;

public class PositiveIntegers {
    boolean check(int mid,int n, int k,ArrayList<Integer> lst2){
        int sum = 0;
        int h = k - 1;
        ArrayList<Integer> lst3 = new ArrayList<>();
        lst3 = lst2;
        lst3.add(0);
        for(int i = 0;i <= n;i++){
            if(sum + lst2.get(i) <= mid){
                sum += lst2.get(i);
            }
            else{
                sum = lst2.get(i);
                h --;
            }
        }
        return h >= 0;
    }
    int Positive(){
        Scanner sc = new Scanner(System.in);
        String init = sc.nextLine();
        ArrayList<Integer> lst = new ArrayList<Integer>();
        for(String a:init.split(" ",2)){
            lst.add(Integer.parseInt(a));
        }
        ArrayList<Integer> lst2 = new ArrayList<Integer>();
        int low = 0;
        int high= 0;
        for(int i = 0;i < lst.get(0);i++){
            int a = sc.nextInt();
            lst2.add(a);
            high += a;
            if(a >= low){
                low = a;
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
        PositiveIntegers s = new PositiveIntegers();
        System.out.println(s.Positive());
    }
}
