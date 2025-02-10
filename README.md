# Project

The project receives an amount of random numbers, store it in a stack and sort it in ascending order with a bunch of limited operations.

### Operations:

**sa (Swap A):** swap the first two elements at the top of stack A.<br>
Do nothing if there is only one or none elements.

**sb (Swap B):** swap the first two elements at the top of stack B.<br>
Do nothing if there is only one or none elements.

**ss (Swap A and B):** swap the first two elements at the top of stack A and B at the same time.<br>
Do nothing if there is only one or none elements.

**pa (Push A):** Take the first element at the top of stack B and put it at the top of stack A.<br>
Do nothing if stack B is empty.

**pb (Push B):** Take the first element at the top of stack A and put it at the top of stack B.<br>
Do nothing if stack A is empty.

**ra (Rotate A):** Shift up all elements of stack A by one.<br>
The first element becomes the last one.

**rb (Rotate B):** Shift up all elements of stack B by one.<br>
The first element becomes the last one.

**rr (Rotate A and B):** Shift up all elements of stack A and B by one at the same time by one.<br>
The first element of both stacks becomes the last one.

**rra (Reverse Rotate A):** Shift down all elements of stack A by one.<br>
The last element becomes the first one.

**rrb (Reverse Rotate B):** Shift down all elements of stack B by one.<br>
The last element becomes the first one.

**rrr (Reverse Rotate A and B):** Shift down all elements of stack A and B at the same time by one.<br>
The last element of both stacks becomes the last one.

### Algorithm:

For this project I used the Mia Algorithm. It goes as follows:

The Mia Algorithm is an optimized strategy for solving push_swap, based on division and efficient movement of elements between stacks A and B.

    Indexing – Each number is assigned an index corresponding to its sorted position, making tracking easier.
    Stack Division – All elements except three are moved to B, keeping the largest ones in A for a quick initial sort.
    Cost Calculation – Each element in B has a calculated cost to be correctly reinserted into A, minimizing movements.
    Move Optimization – Combined operations (RR, RRR) reduce the total number of actions.
    Final Adjustment – After sorting, A is adjusted to ensure the smallest index is at the top.

This method reduces problem complexity by dividing and sorting in smaller, more efficient steps.

# How to use it?

Clone this repository:

```shell
git clone https://github.com/victorcploureiro/push_swap_project.git push_swap
```

Then compile the files as following:

#### Mandatory:

Sorts a quantity of numbers informed as parameters and prints the moves in the standard output.

```shell
make
```
