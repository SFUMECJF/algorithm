import java.util.ArrayList;
import java.util.Scanner;

public class ShortestInterval {
    int Short(){
        Scanner sc = new Scanner(System.in);
        String number = sc.nextLine();
        ArrayList<Integer> num = new ArrayList<Integer>();
        for (String s:number.split(" ",2)){
            num.add(Integer.parseInt(s));
        }
        String ls = sc.nextLine();
        ArrayList<Integer> mylist = new ArrayList<Integer>();
        for (String s:ls.split(" ",num.get(1))){
            mylist.add(Integer.parseInt(s));
        }
        System.out.println(mylist.stream().mapToInt(x -> x).sum());
        if(mylist.stream().mapToInt(x -> x).sum() < num.get(0)){
            return 0;
        }
        for(int i = 0;i < mylist.size();i++){
            for(int j = 0;j < mylist.size() - i;j++){
                int sum1 = 0 ;
                for(int x = 0;x <= i;x++){
                    sum1 += mylist.get((j+x));
                }
                System.out.println(sum1);
                if(sum1 >= num.get(0)){
                    return i+1;
                }
            }
        }
        return 0;
    }
    public static void main(String[] args){
        ShortestInterval si = new ShortestInterval();
        System.out.println(si.Short());
    }
}
