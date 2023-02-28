import os

def main():
    folder = r"F:\F.Y. B.Sc(C.S.)\CERTIFICATES\Boot camp"

    for count, filename in enumerate(os.listdir(folder)):
        #dst = f"img {str(count+1)}.py"
        src = f"{folder}/{filename}"
        # dst =f"{folder}/{dst}"
        dst = f"{folder}/{filename.removeprefix('Certificate for ')}"
        print(dst)
        os.rename(src, dst)

# Driver Code
if __name__ == '__main__':
    print(__name__)
    main()
