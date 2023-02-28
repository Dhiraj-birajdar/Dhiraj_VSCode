# range1 = range(0, 10)


# # first number (start number) in range
# print(range1[0])


# # access 5th number in range
# print(range1[5])
# # Output 5

# # access last number
# print(range1[range1.stop - 1])
# # Output 9
for i in range(1,11,1):
    if(i%4==0):
        print(i, end=' ')
        break