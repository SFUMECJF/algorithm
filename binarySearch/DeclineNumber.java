import java.util.Scanner;

public class DeclineNumber {
    int decline(){
        Scanner sc = new Scanner(System.in);
        int number = sc.nextInt();
        for(int i = number;i >= 0 ; i--){
            int num = i;
            int x = num % 10;
            num = (int)(num /10);
            int flag = 0;
            while(num != 0){
                System.out.println(num);
                if(x < num%10){
                    flag = 1;
                    break;
                }
                x = num % 10;
                num = (int)(num /10);
            }
            if(flag == 0){
                return i;
            }
        }
        return 0;
    }
    public static void main(String[] args){
        DeclineNumber dl = new DeclineNumber();
        System.out.println(dl.decline());
    }
}
