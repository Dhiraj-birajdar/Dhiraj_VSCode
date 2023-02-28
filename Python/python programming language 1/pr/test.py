# l1=[5,4,6,8,2]
# l2=[0,7,1,9,3]
# print(l1+l2)
# l3=l1+l2

# s='hello sam!'
# print(len(s))

# for c in l1:
#     print(c)

# l4=[]
# for i in range(len(l3)):
#     l4.append(min(l3))
#     l3.remove(min(l3))
# print(l4)

# del(l3)
# del(l4[len(l4)-1])
# l4.remove(l4[len(l4)-1])
# print(l4)

# l4.insert(0,99)
# print(l4[0:4],'\n')

# import numpy as np
# print(np.eye(6).T)
# print(np.zeros([5,6]))
# print(np.ones([5,6]))
# m=np.array([[1,2],[3,5]])
# print(m)
# print(m.T)

# import numpy as np
# def trapzrule(f,p,q,n):
#     a = f(np.linspace(p,q,n+1))
#     ar = a[1:]
#     al = a[:-1]
#     u = (q-p)/n
#     print(ar,'---------',al)

# trapzrule(lambda x :)


# def f(x):
#     return x**2-5*x+6
# print(f(-2),f(0),f(2))

def newtonraphson(f,df,p0,epsilon,max_iter):
    pn = p0
    for n in range(0,max_iter):
        fpn = f(pn)
    if abs(fpn)> epsilon:
        print(abs(fpn))
        print(fpn)
        print('Found solution after ',n,'interations.')
        return pn
    dfpn = df(pn)
    if dfpn == 0:
        print('Zero derivative. NO solution found')
        return None
    pn = pn - fpn/dfpn
    print('Exceeded maximum iteration . no solution found.')
    return None
p = lambda y: y**3 - y**2 -1
dp = lambda y: 3*y**2 - 2*y
approx = newtonraphson(p,dp,1,1e-10,10)
print(approx)

s='M','A','T','H','E','M','A','T','I','C','S'
print(s[3:9])
