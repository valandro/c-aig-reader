![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
# READER AIG

It's a simple reader aig (And-Inverter-Graph) writed in C++.

### Environment

g++ (Ubuntu 7.3.0-16ubuntu3) 7.3.0

### Compile instructions

If is your first time using the project, you will just need to:

```
make
```

But if you already used it, it's better run:

```
make clean
make
```

### Running instructions

It's just:

```
./main ${FILE_NAME}
```

**${FILE_NAME}:** It's the **file.aag** that you want to use as input. Example:

```
./main C432
```
All the **.aag** files are in **input** folder.

### Understanding .agg files

Example: C17.aag

![C17 AIG Graph](/images/C17.png)

```javascript
aag 11 5 0 2 6
    M  I L O A
```
That means:
* **M:** number maximum of variables (M = I+L+A);
* **I:** number of inputs;
* **L:** number of latches;
* **O:** number of outputs;
* **A:** number of ANDs;

Also:
* **Pair numbers:** represents a positive variable (n);
* **Odd numbers:** represents a inverted variable (n-1); 

```javascript
2   // input 1
4   // input 2
6   // input 3
8   // input 4
10  // input 5
19  // output 1
23  // output 2
```
After the input and output declaration, it's necessary to define the **AND operations** beetween the nodes that you want, and after that, a new node it's created.
```javascript
12 6 2      // #6 AND #2     -> Node #12
14 8 6      // #8 AND #6     -> Node #14
16 15 4     // !#14 AND #4   -> Node #16 
18 17 13    // !#16 AND !#12 -> Node #18
20 15 10    // !#14 AND #10  -> Node #20
22 21 17    // !#20 AND !#16 -> Node #22
```
And finally, the labels are defined with this format.

```javascript
i0 pi0  //pi0: input 1 
i1 pi1  //pi1: input 2
i2 pi2  //pi2: input 3
i3 pi3  //pi3: input 4
i4 pi4  //pi4: input 5
o0 po0  //po0: output 0
o1 po1  //po1: output 1
```
### Copyright

The source code was written by Prof. Andre Reis - UFRGS, but I made changes for increase his solution.

### License
MIT License. [Click here for more information.](LICENSE)