a = int(input("Enter Num1: "));
b = int(input("Enter Num2: "));
c = int(input("Enter Num3: "));

if a >= b and a >= c:
    print("Maximum is: ",a);
elif b >= a and b >= c:
    print("Maximum is:", b);
else :
    print("Maximum is:",c);

if a <= b and a <= c:
    print("Minimum is:",a);
elif b <= a and b <= c:
    print("Minimum is:",b);
else :
    print("Minimum is:",c);

