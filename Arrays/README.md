# ARRAY OPERATIONS ALGORITHMS



## 1 - Traversal 



1. Initialize counter 


        Set counter = Lower Band
2. Repeat steps 3 and 4 while counter <= Upper Band

3. Visit element 


        Apply PROCESS to arr[counter]


4. Increase counter 


        Set counter = counter + 1
5. Exit




## 2 - Insertion 

*Note:*

N : number of items


K : positif integer while K <= N


ITEM: insert an element

1. Initalize Counter


        Set J = N
2. Repeat Steps 3 and 4 while J>=K
3. Move Jth element downward


        Set A[J+1] = A[J]
4. Decrease Counter 


        Set J = J - 1


        End of step 2 loop 
5. Insert element 
        

        Set A[K] = ITEM

6.Reset N
        

        Set N = N + 1

7.Exit




## 3 - Deletion 

*Note:*


K : positive integer such that K<=N


1. Set ITEM = A[K]
2. Repeat for J = K to N-1


        [Move J+1 element upward]


            Set A[J] = A[J+1]
    

        End of loop
3. Reset the number N of elements in A
        

        Set N = N - 1
4. Exit




