import numpy as np
def sim3_8(f,x0,x,u):
    h = (x-x0)/u
    y = f(np.linspace(x0,x,u+1))
    i1 = (3*h)/8
    i2 = y[0]+y[len(y)-1]
    i3=i4=0
    for n in range(1,len(y)-1):
        if n%3:
            i3 += y[n]
        else:
            i4 += y[n] 
    return i1 *(i2 + 3*i3 + 2*i4)

ans = sim3_8(np.log,4,5.2,6)
print(ans)
print(sim3_8(lambda a:1/(1+a),0,1,6))