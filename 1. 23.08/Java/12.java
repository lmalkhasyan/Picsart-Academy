class Triangle{
	public static void main(String[] args)
	{
     	for(int c = 1, space = 5; c < 11; c+=2)
		{
			for(int i = 0; i < space ; ++i)
				System.out.print(' ');
			for(int i = 0; i < c; ++i)
				System.out.print('*');
			System.out.print('\n');
		--space;
		}
    }
}
