import java.util.*;

class Main {

	public static void main(String[] args)
	{	
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter 1 number: ");
		int a = sc.nextInt();
		System.out.print("Enter 2 number: ");
		int b = sc.nextInt();
		System.out.print("Enter Operation: ");
		char op = sc.next().charAt(0);
		if (op == '+')
			System.out.printf("%d\n", a+b);
		else if (op == '-')
			System.out.printf("%d\n", a-b);
		else if (op == '*')
			System.out.printf("%d\n", a*b);
		else if (op == '/')
			System.out.printf("%d\n", a/b);	
		else if (op == '%')
			System.out.printf("%d\n", a%b);
	}
}
