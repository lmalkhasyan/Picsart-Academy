def print_nbr(n):
    if n == 0:
        return;
    print_nbr(n // 10)
    print (n % 10,end="")
    print ("_",end="");
a = int(input("Enter Number: "));
print_nbr(a);
