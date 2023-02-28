a = int(input('enter no 1 : '))
b = int(input('enter no 2 : '))
i = min(a,b)
for i in range(i,0,-1):
	if not(a%i) and not(b%i):
		print('gcd old : ',i)
		break
#print(i)

#if a%i:
#	print('gcd old : 1')
while(a!=b):
	if a>b:
		a-=b
	else:
		b-=a

print('gcd is ',a)