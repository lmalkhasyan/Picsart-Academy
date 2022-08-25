import java.util.*;

class Main {

	static int mul(int num1, int num2, int num3) 
	{
			return num1 * num2 * num3;
	}
	public static void main(String[] args)
	{	
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter 1 number: ");
		int a = sc.nextInt();
		System.out.print("Enter 2 number: ");
		int b = sc.nextInt();
		System.out.print("Enter 3 number: ");
		int c = sc.nextInt();

		System.out.printf("num1*num2*num3 = %d\n", mul(a,b,c));
	}
}
