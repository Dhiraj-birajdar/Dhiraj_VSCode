import numpy as n
def sim1_3(f,x0,x,u):
    if u%2:
        raise ValueError('u must be even integer')
    y = f(n.linspace(x0,x,u+1))
    h = (x-x0)/u
    return (h/3)*((y[0]+y[len(y)-1])+4*(n.sum(y[1:-1:2]))+2*(n.sum(y[2:-1:2]))) 
ans = sim1_3(lambda a: a**2,0,1,10)
print(ans)
print(sim1_3(lambda a: 1/(1+a),0,1,6))























# a = n.linspace(0, 10, 11)
# print(a)
# print(a[0:-1:])
# print(a[1:-1:2])
# print(a[2::2])

