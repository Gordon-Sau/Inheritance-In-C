# Inheritance in C
implementing inheritance in C with multiple approaches

The approaches are:
multiple vtables and store the vptr in the object (used in c++), stored all the vtables in the class, the object point to class and find the vtables in runtime (used in java), and using a fat pointer where the vptr is store next to the object pointer (used in Go and Rust).

# Reference
The following link is where I learn these appraoches and it explains the approaches quite clearly
https://lukasatkinson.de/2018/interface-dispatch/

# compile and run
For each directory, cd to the directory and run the following commands.
```
gcc *.c -o main
./main
```

# pros and cons
TODO
