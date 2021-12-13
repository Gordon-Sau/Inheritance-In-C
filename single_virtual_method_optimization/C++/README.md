Remove an indirection when the vtable only contains one function.
This can be done as the size of a vptr is the same as a function pointer.
