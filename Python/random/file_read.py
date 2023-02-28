try:
    with open(r'X:\Dhiraj_VSCode\Python\random\test.txt') as file:
        print(file.read())
except FileNotFoundError:
    print('file not found')
       