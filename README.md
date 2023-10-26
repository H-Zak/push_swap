# Push Swap

[**Subject**](https://cdn.intra.42.fr/pdf/pdf/105453/fr.subject.pdf)

The purpose is to create a C program that prints a series of optimized instructions for sorting a random list of integers. For this project, we'll need to implement an efficient sorting algorithm while respecting the constraints imposed by the subject.

The algorithm we're going to build here is just one solution among several. It relies on a system of indexes and positions that makes it very efficient, but also very accessible.

# Push_Swap rules

The subject of push_swap has some fairly strict rules. Our program must be able to receive as arguments a series of random integers, both positive and negative. If there is a duplicate in this sequence of numbers, our push_swap must return an error. The same applies if a number exceeds the limits of an integer.

If the sequence of numbers is error-free, our program should print a series of instructions, each on a new line, to sort the numbers in ascending order.

We are allowed two stacks to sort our nombles, stack A and stack B:

- stack A initially contains all the numbers to be sorted. The first number in the sequence is at the top of the stack.
    
- stack B begins by being completely empty.

# Push_Swap Action

**Push** :

- pa (push A): Takes the first element at the top of B and puts it on A. Does nothing if B is empty.

- pb (push B): Takes the first element at the top of A and puts it on B. Does nothing if A is empty.

**Swap** :

- sa (swap A): Swaps the first 2 elements at the top of stack A. Does nothing if there is only one or none.

- sb (swap B): Swaps the first 2 elements at the top of stack B. Does nothing if there is only one or none.

- ss : sa and sb at the same time.

**Rotate** :

- ra (rotate A): Shifts all elements in stack A upwards by one position. The first element becomes the last.

- rb (rotate B): Shifts all elements in stack B upwards by one position. The first element becomes the last.

- rr : ra and rb at the same time.

**Reverse rotate** :

- rra (reverse rotate A): Shifts all elements in stack A down one position. The last element becomes the first.

- rrb (reverse rotate B): Shifts all elements in stack B down one position. The last element becomes the first.

- rrr : rra and rrb at the same time.
## Installation

**Building the program :**

```bash
  git clone https://github.com/Zheylkoss/push_swap.git
  cd push_swap && make
```

**Running the program :**

```bash
  ./push_swap  [put a list of number]
```
    
## Roadmap for the solution

- Send all numbers to stack B

- Sort the 3 remaining numbers in stack A

- **Calculer les positions** :

     Finding the position of each element in its stack, as well as the target position in stack A where an element from stack B should be, is a key step in our push_swap algorithm. With these positions, we can calculate the least costly sequence in terms of actions and choose which element to move first.

- Calculate the best travel cost in terms of number of shares :

        - calculate the cost of reaching the top of stack B

        - calculate the cost of achieving the right position in the stack A

- Execute the chosen sequence of actions
