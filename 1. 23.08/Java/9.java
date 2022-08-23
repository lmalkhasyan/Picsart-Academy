import java.util.*;

class Main {

	public static void main(String[] args)
	{	
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter number: ");
		int a = sc.nextInt();
		int sum = 0;
		while(a != 0)
		{
			sum += a%10;
			a /= 10;
		}
		System.out.printf("Sum is: %d\n", sum);
	}
}
