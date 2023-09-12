// 按两次 Shift 打开“随处搜索”对话框并输入 `show whitespaces`，
// 然后按 Enter 键。现在，您可以在代码中看到空格字符。
import java.util.Random;
import java.util.Scanner;
import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        ArrayList<Student> SList=new ArrayList<>();
        ArrayList<Teacher> TList=new ArrayList<>();
        Studentfaces(SList);
    }
    public static void Studentfaces(ArrayList List){
        loop:while(true) {
            Scanner sc=new Scanner(System.in);
            Screen();
            int a=sc.nextInt();
            switch (a) {
                case 0:{
                    System.out.println("退出");
                    break loop;
                }
                case 1: {
                    AddStudent(List);
                    break;
                }
                case 2:{
                    PutStudent(List);
                    break;
                }
                case 3:{
                    DeleteS(List);
                    break;
                }
                case 4:{
                    FindB(List);
                    break;
                }
                case 5:{
                    SetS(List);
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
    public static Boolean isvalib(String Id){
        for(int i=0;i<Id.length();i++){
            if(Id.charAt(i)<'0'||Id.charAt(i)>'9'){
                return false;
            }
        }
        return true;
    }
    public static void AddStudent(ArrayList<Student> List){
        Scanner sc=new Scanner(System.in);
        Student s=new Student();
        System.out.println("输入学生信息:Id,name,age");
        s.Students(sc.next(),sc.next(),sc.nextInt());
        s.setId("2023"+s.getId());
        if(isvalib(s.getId())) {
            List.add(s);
            System.out.println("添加成功");
        }
        else{
            System.out.println("Id无效");
        }

    }
    public static void PutStudent(ArrayList<Student> List){
        for (int i = 0; i < List.size(); i++) {
            List.get(i).putStudent();
        }
    }
    public static void FindB(ArrayList<Student> List){
        Scanner sc=new Scanner(System.in);
        int b=1;
        while(b!=0) {
            System.out.println("输入查找方式");
            System.out.println("1.id查找");
            System.out.println("2.姓名查找");
            System.out.println("0.退出查找");
            b=sc.nextInt();
            switch(b){
                case 1:
                    int i=FindId(List);
                    Printf(List,i);
                    break;
                case 2:
                    FindName(List);
                    break;
                case 0:{
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
    public static int FindId(ArrayList<Student> List) {
        Scanner sc = new Scanner(System.in);
        System.out.println("输入要查找的id");
        String s = sc.next();
        for (int i = 0; i < List.size(); i++) {
            if (s.equals(List.get(i).getId())) {
                return i;
            }
        }
        return -1;
    }
    public static void FindName(ArrayList<Student> List){
        Scanner sc=new Scanner(System.in);
        System.out.println("输入要查找的name");
        String s=sc.next();
        int count=0;
        for(int i=0;i<List.size();i++){
            if(s.equals(List.get(i).getName())){
                List.get(i).putStudent();
                count++;
            }
        }
        System.out.println("找到"+count+"个结果");
    }
    public static void DeleteS(ArrayList<Student> List){
        int i=FindId(List);
        if(i!=-1)
        {
            List.remove(i);
            System.out.println("删除成功");
        }
        else
            System.out.println("没找到");
    }
    public static void SetS(ArrayList<Student> List){
        Scanner sc=new Scanner(System.in);
        System.out.println("输入要修改的学生id");
        String s=sc.next();
        for(int i=0;i<List.size();i++){
            if(s.equals(List.get(i).getId())){
                Printf(List,i);
                int a=1;
                while(a!=0) {
                    System.out.println("选择修改内容");
                    System.out.println("1.ID");
                    System.out.println("2.name");
                    System.out.println("3.age");
                    System.out.println("0.退出");
                    a=sc.nextInt();
                    switch (a) {
                        case 1:{
                            System.out.println("输入新id");
                            s=sc.next();
                            if(isvalib(s)) {
                                List.get(i).setId(s);
                                System.out.println("已修改");
                            }
                            else{
                                System.out.println("Id重复");
                            }
                            break;
                        }
                        case 2:{
                            System.out.println("输入新name");
                            s=sc.next();
                            List.get(i).setName(s);
                            System.out.println("已修改");
                            break;
                        }
                        case 3:{
                            System.out.println("输入新age");
                            int S=sc.nextInt();
                            List.get(i).setAge(S);
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
    public static void Printf(ArrayList<Student> List,int i){
        if(i!=-1) {
            List.get(i).putStudent();
            System.out.println("找到了");
        }
        else
            System.out.println("没找到");

    }
}