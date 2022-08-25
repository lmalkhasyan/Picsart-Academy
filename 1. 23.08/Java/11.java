class House{
	public static void main(String[] args)
	{
		for(int i=1, space=2, c=1;i  < 8; ++i)
		{
			for(int b = 0; b < space; ++b)
				System.out.print(' ');
			for(int b = 0; b < c; ++b)
				System.out.print('*');
			System.out.print('\n');
			if (space > 0)
				--space;
			if (c < 5)
				c += 2;
		}
    }
}
