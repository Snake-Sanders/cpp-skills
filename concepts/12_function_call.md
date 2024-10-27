## The function call and return process 

These are the common events on the stack during a function call in a standard 
calling convention, such as **cdecl** 
(the default calling convention for many C++ compilers on x86 architectures). 

The process might vary depending on the calling convention and architecture, 
but this overview covers the common approach:

### 1. **Preparing the Stack for the Function Call**

   - **Push Arguments**: The caller pushes arguments onto the stack for the callee. In many conventions, arguments are pushed right-to-left (last argument is pushed first) so that the first argument is at the top of the stack.
   - **Push Return Address**: The CPU pushes the return address (the address where the function call instruction is located in the caller) onto the stack. This is the address to which the CPU will return after the function finishes executing.
   - **Jump to Function**: The CPU jumps to the function’s entry point, transferring control to the callee.

### 2. **Inside the Callee Function**

   - **Push Frame Pointer**: The function often pushes the current frame pointer (`EBP` on x86) onto the stack to keep track of the caller’s stack frame. The frame pointer allows the function to access its own parameters and local variables relative to a fixed point.
   - **Set up Stack Frame**: The callee adjusts the stack pointer (`ESP` on x86) to reserve space for its local variables.
   - **Execute Function Code**: The function executes, using its parameters from the stack and storing local variables within the stack frame.

### 3. **Returning from the Function**

   - **Store Return Value**: If the function returns a value, it is typically placed in a register (e.g., `EAX` on x86 for integral values) or, if large, in memory reserved by the caller.
   - **Clean Up Stack Frame**: The callee restores the frame pointer and stack pointer to their previous values, effectively "popping" its stack frame.
   - **Return to Caller**: The function pops the return address from the stack, places it in the instruction pointer (`EIP` on x86), and jumps back to the caller’s instruction following the call.

### 4. **Cleanup in Caller**

   - **Pop Arguments (if needed)**: Depending on the calling convention, either the caller or callee is responsible for popping the arguments off the stack. In **cdecl**, for example, the caller cleans up the arguments by adjusting the stack pointer.

### Example Walkthrough

Here’s how it would look with a function call `int add(int a, int b);` from a function `main`:

```cpp
int main() {
    int result = add(3, 4);
}
```

1. **In `main` (Caller)**:
   - Push `4` (argument `b`) onto the stack.
   - Push `3` (argument `a`) onto the stack.
   - Push the return address onto the stack.
   - Jump to `add`.

2. **In `add` (Callee)**:
   - Push the frame pointer (`EBP`).
   - Set up a new frame by adjusting the stack pointer for local variables (if any).
   - Execute the addition: `int sum = a + b;`.
   - Store `sum` in `EAX` (assuming it's an integer).
   - Restore the frame pointer.
   - Pop the return address into `EIP` and jump back to `main`.

3. **In `main` after `add` returns**:
   - Retrieve the result from `EAX` (or other designated register).
   - Clean up the arguments by adjusting the stack pointer.

This process ensures that both arguments and return values are correctly managed on the stack, with stack frames keeping function execution isolated. Different conventions, such as **fastcall** or **stdcall**, may alter details like who cleans up the stack or which registers are used, but the overall pattern remains consistent.
