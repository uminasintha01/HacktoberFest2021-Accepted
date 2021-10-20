# a program to solve tower of Hanoi problem

def TowerOfHanoi(n,source,destination,auxillary):
    if n==1:
        print('Move disk 1 from source',source,"to destination",destination)
        return
    TowerOfHanoi(n-1,source,auxillary,destination)
    print("Move disk....",n,"from source.....",source,"to destination....",destination)
    TowerOfHanoi(n-1,auxillary,destination,source)


n=4
TowerOfHanoi(n,'A','B','C')


# output of the program 

# Move disk 1 from source A to destination C
# Move disk.... 2 from source..... A to destination.... B
# Move disk 1 from source C to destination B
# Move disk.... 3 from source..... A to destination.... C
# Move disk 1 from source B to destination A
# Move disk.... 2 from source..... B to destination.... C
# Move disk 1 from source A to destination C
# Move disk.... 4 from source..... A to destination.... B
# Move disk 1 from source C to destination B
# Move disk.... 2 from source..... C to destination.... A
# Move disk 1 from source B to destination A
# Move disk.... 3 from source..... C to destination.... B
# Move disk 1 from source A to destination C
# Move disk.... 2 from source..... A to destination.... B
# Move disk 1 from source C to destination B
