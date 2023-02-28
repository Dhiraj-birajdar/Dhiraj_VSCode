def newtonRaphson(f,df,x,n):
    for n in range(n):
        h = f(x) / df(x)
        x = x - h
    return x

ans = newtonRaphson(lambda x : x**2+ 5*x +1,lambda x : 5*x**4+5*x+1,-1,5)
print(ans)

print(newtonRaphson(lambda x : x**2-10,lambda x : 2*x,3.1,5))