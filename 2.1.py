def significant_digits(x):
    count=0
    zero=0
    f=0
    s=''
    ss=''
    for i in x:
        if(i=='.'):
            s+=i
            continue
        if i>'0' and i<='9' and f==0:
            f=1
            count+=1
            s+=i
            continue
        if i>'0' and i<='9' and f==1:
            count+=zero+1
            zero=0  
            s+=ss+i
            ss='' 
        if i=='0' and f==1:
            zero+=1
            ss+='0'
    return count,s

num=input("Enter a number: ")
a=significant_digits( num )
print("you entered: ",num)

print("Significant digits: ",a[0])
print("Significant digits: ",a[1])

x=int(input("Enter the number of decimal places you want to round off: "))
# x=2
print("Rounding off: ",a[1])

j=0
ans=''
numm=a[1]
for i in numm:
    if i!='.':
        j+=1
        # print(i)
        ans+=i
        
        if j==x:
            break
print("Rounding off: ",ans)
