def calculate_a(str):
    return str.count('a')

def main():
    marius = input()
    doctor = input()
    if calculate_a(marius) >= calculate_a(doctor):
        print("go")
    else:
        print("no")


main()