import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        
        System.out.println(py(a));
    }
    public static String py(int num)
    {
        String[] arr ={"零","壹","贰","叁","肆","伍","陆","柒","捌","玖","拾","伯","仟","万","拾","伯"};
        String str ="";
        int b=6;
        int[] arr1=new int[7];
        for(int i=0;i<7;i++) {
            int n = num % 10;
            num/= 10;
            arr1[b] = n;
            b--;
        }
        for(int i=0;i<7;i++)
        {
            if(i==6)
            {
                str=str+arr[arr1[i]];
            }
            else
                str=str+arr[arr1[i]]+arr[arr.length-1-i];
        }
        return str;
    }
}