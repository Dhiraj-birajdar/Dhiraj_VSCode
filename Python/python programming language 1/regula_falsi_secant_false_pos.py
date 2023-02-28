def regula(f,x0,x1,itr=10):
    if f(x0)*f(x1) >= 0:
        print('regula falsi method fails')
        return None
    fx0=f(x0)
    fx1=f(x1)
    for i in range(itr):
        x0 = (x0*fx1-x1*fx0)/(fx1-fx0)
        fx0 = f(x0)
    return x0

ans = regula(lambda x:x**3-2*x-5,2,2.5,4)
print(ans)











print(regula(lambda x:x**3-x**2-1,1,2,20))
print(regula(lambda x:x**3-18,2.5,2.8))
print(regula(lambda x:x**2-x-1,1,2,25))
print('required root is %f ,%f'% (regula(lambda x:x**2-x-1,1,2,25),10))













def bisection(f,x0,x1,itr=10):
    if f(x0)*f(x1) >= 0:
        print('regula falsi method fails')
        return None
    fx0=f(x0)
    fx1=f(x1)
    for i in range(itr):
        x0 = (x0*fx1-x1*fx0)/(fx1-fx0)
        fx0 = f(x0)
    return x0