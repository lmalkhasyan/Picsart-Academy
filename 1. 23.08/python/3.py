def min(a,b):
    if a <= b:
        return a;
    else :
        return b;

num1 = int(input("Enter 1 number: "))
num2 = int(input("Enter 2 number: "))
num3 = int(input("Enter 3 number: "))
num4 = int(input("Enter 4 number: "))

if num1+num2+num3+num4 == 0:
    print("Minimum is: ",min(num1,min(num2,min(num3,num4))));
else :
    print("Sum is not 0");
