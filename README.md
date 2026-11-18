# push_swap

A 42 Beirut project written in C: sort a list of integers using two stacks and a limited set of operations, in as few moves as possible.

The program takes a list of numbers and prints the shortest sequence of instructions it can find to sort them.

## The rules

There are two stacks, **A** and **B**. All the numbers start in A, and B is empty. When the program finishes, A must be sorted (smallest on top) and B must be empty.

These are the only allowed operations:

| Instruction | Effect |
|-------------|--------|
| `sa` / `sb` / `ss` | Swap the first two elements of A / B / both |
| `pa` / `pb` | Push the top of B onto A / the top of A onto B |
| `ra` / `rb` / `rr` | Rotate A / B / both up (the first element becomes the last) |
| `rra` / `rrb` / `rrr` | Reverse-rotate A / B / both (the last element becomes the first) |

## The algorithm

I used a cost-based greedy approach, often called the "Turk" algorithm:

1. **Push two numbers from A to B** to get started.
2. **Compute a target for every number in A.** The target is the closest smaller number in B, or B's maximum if there isn't one. This keeps B in descending order.
3. **Compute the cost** of bringing each number and its target to the top of their stacks. The cost depends on whether each one sits above or below the median of its stack, which decides between rotating and reverse-rotating.
4. **Push the cheapest number.** When both stacks need to turn the same way, `rr` / `rrr` rotate them together to save moves.
5. **Sort the last three numbers in A** with a hard-coded `sort_three`, which takes at most 2 moves.
6. **Push everything back from B to A.** Each number is placed in front of the closest bigger number in A, or A's minimum.
7. **Rotate the smallest number to the top** to finish.

Inputs of 2 or 3 numbers are handled directly without this process.

## Project structure

```
inc/push_swap.h        stack node struct and prototypes
srcs/operations/       swap, push, rotate, reverse rotate
srcs/algorithms/       sort_three and the main cost-based sort
srcs/push_swap/        parsing, stack setup, target/cost calculation, cleanup
libft/                 my own C library (libft + ft_printf + get_next_line)
```

## Build and run

```bash
make
./push_swap 3 2 5 1 4
./push_swap "3 2 5 1 4"
```

Invalid input (non-integers, values outside the int range, or duplicates) prints `Error` to stderr.

To check the result and count the moves, use the checker program provided by 42 (not included in this repo):

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

## Author

**Mohamad Harajly**, 42 Beirut

## License

[MIT](LICENSE)
