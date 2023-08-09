// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到
import java.sql.SQLOutput;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        role s1=new role();
        role s2=new role("兴佳",500,20,10,30,10,100);
        System.out.println("请选择职业");
        System.out.println("*****1.战士******");
        System.out.println("*****2.法师******");
        System.out.println("*****3.射手******");
        int a=sc.nextInt();
        switch(a){
            case 1:{
                s1.setrole("焕杰",500,10,5,30,15,100);
                break;
            }
            case 2:{
                s1.setrole("焕杰",300,40,5,50,5,300);
                break;
            }
            case 3:{
                s1.setrole("焕杰",300,50,30,50,5,100);
                break;
            }
        }
        while(true){
            s1.attack(s2);
            if(win(s2.getblood())) {
                System.out.println(s1.getname() + "win");
                break;
            }
            s2.attack(s1);
            if(win(s1.getblood())) {
                System.out.println(s2.getname() + "win");
                break;
            }
        }
    }
    public static boolean win(int blood){
        if(blood==0)
            return true;
        return false;
    }

}