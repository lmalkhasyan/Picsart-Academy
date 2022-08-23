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
		System.out.print("Enter 4 number: ");
		int d = sc.nextInt();
		if (a+b+c+d == 0)
		{
			if(a <= b && a <= c && a <= d)
			{
				System.out.printf("Min is: %d \n",a);
			}
			else if(b <= a && b <= c && b <= d)
			{
				System.out.printf("Min is: %d \n",b);
			}
			else if(c <= a && c <= b && c <= d) 
			{
				System.out.printf("Min is: %d \n",c);
			}
			else
			{
				System.out.printf("Min is: %d \n",d);
			}

		}
	}
}
