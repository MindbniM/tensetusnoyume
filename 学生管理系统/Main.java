// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Student[] arr=new Student[100];
        Initialize(arr);
        int a=1;
        while(a!=0) {
            Screen();
            a=sc.nextInt();
            switch (a) {
                case 0:{
                    System.out.println("退出");
                    break;
                }
                case 1: {
                    AddStudent(arr);
                    break;
                }
                case 2:{
                    PutStudent(arr);
                    break;
                }
            }
        }
    }
    public static void Screen(){
        System.out.println("1.添加学生信息");
        System.out.println("2.打印所以学生信息");
        System.out.println("3.删除学生信息");
        System.out.println("4.查询学生信息");
        System.out.println("0.退出系统");
    }
    public static boolean Repeat(Student arr[],String id){
        for(int i=0;i<arr.length;i++){
            Student s=arr[i];
            if((s.getId()).equals(id)){
                System.out.println("学生id重复");
                return false;
            }
        }
        return true;
    }
    public static void AddStudent(Student arr[]){
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<arr.length;i++){
            if(ValinS(arr[i].getId())){
                Student s=new Student();
                System.out.println("输入学生信息:id,name,age");
                s.Students(sc.next(), sc.next(),sc.nextInt());
                if(Repeat(arr,s.getId())) {
                    arr[i] = s;
                    System.out.println("添加成功");
                    break;
                }
                else{
                    System.out.println("id重复,添加失败");
                }
            }
        }
    }
    public static void Initialize(Student arr[]){
        for(int i=0;i<arr.length;i++){
            Student s=new Student("0","0",0);
            arr[i]=s;
        }
    }
    public static void PutStudent(Student[] arr){
        for(int i=0;i<arr.length;i++){
            Student s=arr[i];
            if(!ValinS(s.getId())){
                System.out.println(s.getId());
                System.out.println(s.getName());
                System.out.println(s.getAge());
            }
            else {
                break;
            }
        }
    }
    public static boolean ValinS(String id){
        if(id.equals("0")){
            return true;
        }
        else{
            return false;
        }
    }
}