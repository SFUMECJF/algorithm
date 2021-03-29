import java.util.ArrayList;
import java.util.Scanner;

public class CutWood {
    boolean check(int mid,int n, int k , ArrayList<Integer> lst2){
        int sum = 0;
        for(int i = 0; i < n;i++){
            sum += lst2.get(i)/mid;
        }
        return sum >= k;
    }

    int wood(){
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
            if(a >= high){
                high = a;
            }
        }
        int res = 0;
        while(low < high){
            int mid = (low + high) >> 1;
            if(check(mid,lst.get(0),lst.get(1),lst2)){
                low = mid + 1;
                res = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return res;
    }
    public static void main(String args[]){
        CutWood c = new CutWood();
        System.out.println(c.wood());
    }

}
