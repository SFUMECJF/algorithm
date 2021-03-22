import java.util.ArrayList;
import java.util.Scanner;

public class BinarySearch {
    void binary(){
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        ArrayList<Integer> numlist = new ArrayList<Integer>();
        for (int i = 0;i < number; i++) {
            numlist.add(sc.nextInt());
        }
        int number_q = sc.nextInt();
        System.out.println(number_q);
        for (int i = 0;i < number_q; i++){
            int m = sc.nextInt();
            if (search(numlist,number,m) == -1){
                System.out.println("no");
            }
            else{
                System.out.println("yes");
            }
        }

    }

    int search(ArrayList<Integer> list, int n, int key){

        int right = 0;
        int left = n - 1;
        while (left >= right){
            System.out.println((left - right) >> 1);//4-0 >> 1, 3-0 >> 1
            int mid = right + ((left - right) >> 1);//防止溢出
            if (list.get(mid) == key){
                return mid;
            }
            else if (list.get(mid) > key){
                left = mid - 1;
            }
            else {
                right = mid + 1;
            }
        }
        return -1;
    }

    public static void main(String[] args){

        System.out.println("begin!");
        BinarySearch bs = new BinarySearch();
        bs.binary();
    }
}
