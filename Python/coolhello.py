import time

def hello():
    s = "hello dhiraj birajdar"
    for i in range(len(s)):
        for j in range(ord('\0'), ord('z')+1):
            if s[i] == ' ':
                print(' ', end='')
                break
            elif s[i] == chr(j):
                print(chr(j), end='')
                break
            else:
                print(chr(j), end='')
                time.sleep(0.05)
                print('\b', end='')

hello()