import java.util.*;

class Main {

	static void putnbr(int num) 
	{
		if (num == 0)
			return;
		putnbr(num/10);
		System.out.printf("%d\n", (num % 10));
	}
	public static void main(String[] args)
	{	
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter 1 number: ");
		int a = sc.nextInt();
		putnbr(a);
	}
}
