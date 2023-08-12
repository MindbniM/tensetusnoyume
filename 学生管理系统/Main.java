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
                case 3:{
                    DeleteS(arr);
                    break;
                }
                case 4:{
                    FindB(arr);
                }
                case 5:{
                    SetS(arr);
                    break;
                }
                default:{
                    System.out.println("输入错误,重新输入");
                    break;
                }
            }
        }
    }
    public static void Screen(){
        System.out.println("1.添加学生信息");
        System.out.println("2.打印所有学生信息");
        System.out.println("3.删除学生信息");
        System.out.println("4.查询学生信息");
        System.out.println("5.修改学生信息");
        System.out.println("0.退出系统");
    }
    public static boolean Repeat(Student[] arr, String id){
        for(int i=0;!ValinS(arr[i].getId());i++){
            Student s=arr[i];
            if((s.getId()).equals(id)){
                System.out.println("学生id重复");
                return false;
            }
        }
        return true;
    }
    public static void AddStudent(Student[] arr){
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
                    break;
                }
            }
        }
    }
    public static void Initialize(Student[] arr){
        for(int i=0;i<arr.length;i++){
            Student s=new Student("0","0",0);
            arr[i]=s;
        }
    }
    public static void PutStudent(Student[] arr){
        for (Student s : arr) {
            if (!ValinS(s.getId())) {
                s.putStudent();
            } else {
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
    public static void FindB(Student[] arr){
        Scanner sc=new Scanner(System.in);
        int b=1;
        while(b!=0) {
            System.out.println("输入查找方式");
            System.out.println("1.id查找");
            System.out.println("2.姓名查找");
            System.out.println("0.退出查找");
            b=sc.nextInt();
            switch(b){
                case 1:{
                    FindId(arr);
                    break;
                }
                case 2:{
                    FindName(arr);
                    break;
                }
                case 3:{
                    System.out.println("退出查找");
                    break;
                }
                default:{
                    System.out.println("输入错误,重新输入");
                    break;
                }
            }

        }
    }
    public static void FindId(Student[] arr){
        Scanner sc=new Scanner(System.in);
        System.out.println("输入要查找的id");
        String s=sc.next();
        int couts=0;
        for(int i=0;!ValinS(arr[i].getId());i++){
            if(s.equals(arr[i].getId())){
                Student S=arr[i];
                S.putStudent();
                couts++;
                break;
            }
        }
        System.out.printf("找到%d个结果\n",couts);
    }
    public static void FindName(Student[] arr){
        Scanner sc=new Scanner(System.in);
        System.out.println("输入要查找的name");
        String s=sc.next();
        int couts=0;
        for(int i=0;!ValinS(arr[i].getId());i++){
            if(s.equals(arr[i].getName())){
                Student S=arr[i];
                S.putStudent();
                couts++;
            }
        }
        System.out.printf("找到%d个结果\n",couts);
    }
    public static void DeleteS(Student[] arr){
        Scanner sc=new Scanner(System.in);
        System.out.println("输入要删除的学生id");
        String s=sc.next();
        int i=0,j=0,couts=0;
        for(i=0;!ValinS(arr[i].getId());i++){
            if(!s.equals(arr[i].getId())){
                Student s1=new Student();
                s1.setId(arr[i].getId());
                s1.setName(arr[i].getName());
                s1.setAge(arr[i].getAge());
                arr[j++]=s1;
                couts++;
            }
        }
        if(couts==i){
            System.out.println("没找到该学生,删除失败");
        }
        else {
            arr[j].setId("0");
            System.out.println("删除成功");
        }
    }
    public static void SetS(Student[] arr){
        Scanner sc=new Scanner(System.in);
        System.out.println("输入要修改的学生id");
        String s=sc.next();
        for(int i=0;!ValinS(arr[i].getId());i++){
            if(s.equals(arr[i].getId())){
                arr[i].putStudent();
                int a=1;
                while(a!=0) {
                    System.out.println("选择修改内容");
                    System.out.println("1.id");
                    System.out.println("2.name");
                    System.out.println("3.age");
                    System.out.println("0.退出");
                    a=sc.nextInt();
                    switch (a) {
                        case 1:{
                            System.out.println("输入新id");
                            s=sc.next();
                            arr[i].setId(s);
                            System.out.println("已修改");
                            break;
                        }
                        case 2:{
                            System.out.println("输入新name");
                            s=sc.next();
                            arr[i].setName(s);
                            System.out.println("已修改");
                            break;
                        }
                        case 3:{
                            System.out.println("输入新age");
                            int S=sc.nextInt();
                            arr[i].setAge(S);
                            System.out.println("已修改");
                            break;
                        }
                        case 0:{
                            System.out.println("退出修改");
                            break;
                        }
                        default:{
                            System.out.println("输入错误,重新输入");
                            break;
                        }
                    }
                }
            }
        }
    }
}