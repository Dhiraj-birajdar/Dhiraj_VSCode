l=['1','|','2','|','3','4','|','5','|','6','7','|','8','|','9']

def display():
    print()
    for i in range(15):
        print(l[i],end='')
        if not (i+1)%5:
            print()
    print()

display()

while 1:
    l[l.index(input('Player 1 (#): '))]='#'
    display()
    if ((l[0] == l[2] and l[2] == l[4]) or (l[5] == l[7] and l[7] == l[9]) or (l[10] == l[12] and l[12] == l[14]) or (l[0] == l[5] and l[5] == l[10]) or (l[2] == l[7] and l[7] == l[12]) or (l[4] == l[9] and l[9] == l[14]) or (l[0] == l[7] and l[7] == l[14]) or (l[4] == l[7] and l[7] == l[10])):
        print("\n -----|| player 1 (#) won! ||-----\n")
        break
    l[l.index(input('Player 2 (*): '))]='*'
    display()
    if ((l[0] == l[2] and l[2] == l[4]) or (l[5] == l[7] and l[7] == l[9]) or (l[10] == l[12] and l[12] == l[14]) or (l[0] == l[5] and l[5] == l[10]) or (l[2] == l[7] and l[7] == l[12]) or (l[4] == l[9] and l[9] == l[14]) or (l[0] == l[7] and l[7] == l[14]) or (l[4] == l[7] and l[7] == l[10])):
        print("\n -----|| player 2 (*) won! ||-----\n")
        break
        
# while 1:
#     p1 = input('Player 1 (o): ')
#     l[l.index(p1)]='o'
#     display()
#     # if l[0]==l[2]==l[4]=='o':
#     #     print('player 1 won! ')
#     p2 = input('Player 2 (*): ')
#     l[l.index(p2)]='*'
#     # try:
#     #     l[l.index(p2)]='*'
#     # except:
#     #     if ValueError:
#     #         print('cannot enter value')
#     display()

