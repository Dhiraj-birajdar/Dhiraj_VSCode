import matplotlib.pyplot as plt 
left = [1,2,3,4,5]
height = [65,30,54,10,20]
tick_label=['Cricket','Football','Hockey','Chess','Tennis']
plt.bar (left,height,tick_label = tick_label,width = 0.7 ,color = ['orange','green'])
plt.xlabel('Games')
plt.ylabel('No.Of Student')
plt. show()
