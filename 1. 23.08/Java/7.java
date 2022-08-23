import java.util.*;

class Main {
	public static void main(String[] args)
	{	
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter 1 number: ");
		int a = sc.nextInt();
		System.out.print("Enter 2 number: ");
		int b = sc.nextInt();
	
		int temp = a;
		a = b;
		b = temp;
		System.out.printf("Num 1 is: %d\n",a);
		System.out.printf("Num 2 is: %d\n",b);
	}
}
