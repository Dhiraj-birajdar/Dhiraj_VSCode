from scipy.interpolate import interp1d
x = [1,3,4,8,10]
y = [8,15,19,32,40]
ix = 5
fx=interp1d(x,y)
print(fx(ix))














# x=[1,2,3,4,6,7]
# y=[2,4,8,16,64,128]
# ix=5
# yinterp=interp1d(x,y)
# format(ix)
# print(yinterp(ix))
# x=[5,6,9,11]
# y=[12,13,14,16]
# ix=10
# yinterp=interp1d(x,y)
# # format(ix)
# print(yinterp(ix))

# X = [150,152,154,155] # random x values
# Y = [12.247,12.329,12.410,12.490] # random y values
# interpolate_x = 153
# y_interp = interp1d(X, Y)
# print("Value of Y at x = {} is".format(interpolate_x), y_interp(interpolate_x))

# X = [654,658,659,661] # random x values
# Y = [2.8156,2.8182,2.8189,2.8202] # random y values
# i_x = 656
# y_interp = interp1d(X, Y)
# print(y_interp)
# print(interp1d(X,Y))
# print(format(i_x))
# print("Value of Y at x = {} is".format(i_x), y_interp(i_x))
