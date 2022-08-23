import java.util.*;

class Main {
	public static void main(String[] args)
	{
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter 1 number: ");
		int a = sc.nextInt();
		System.out.print("Enter 2 number: ");
		int b = sc.nextInt();
		System.out.print("Enter 3 number: ");
		int c = sc.nextInt();
		if(a >= b && a >= c)
		{
			System.out.printf("Maximum is: %d \n",a);
		}
		else if(b >= a && b >= c)
		{
			System.out.printf("Maximum is: %d \n",b);
		}
		else
		{
			System.out.printf("Maximum is: %d \n",c);
		}

		if(a <= b && a <= c)
		{
			System.out.printf("Minimum is: %d \n",a);
		}
		else if(b <= a && b <= c)
		{
			System.out.printf("Minimum is: %d \n",b);
		}
		else
		{
			System.out.printf("Minimum is: %d \n",c);
		}


	}
}

