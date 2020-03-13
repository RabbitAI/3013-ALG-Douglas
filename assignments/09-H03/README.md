## Homework - Data Structures and Complexity
#### Due: 03-13-2020 (Friday @ 3:30 p.m.)

- Given a collection of algorithms that runs on **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!)**, order the algorithms from fastest to slowest.
- Suppose that the complexity of an algorithm is O(n<sup>2</sup>). Suppose that the program that uses the algorithm run in 10 seconds for a data set of size n. If the data size is doubled, how long will it take (approximately) to run the program? 


- Complexities : **O(1), O(n log n), O(n), O(n<sup>2</sup>), O(log n), O(n!) , O(h)**
- 1) Finding the max element in an unordered stack would require operations? O(n)
- 2) Finding the min element in an unordered queue would require ____O(n)_____ operations?
- 3) Finding some element in some Binary Search Tree would require ___O(n)___ operations?
- 4) Finding some element in a balanced Binary Search Tree would require ___O(log n)_____ operations?
- 5) Finding some element in an ordered linked list would require ____O(n)_____ operations (worst case)?
- 6) Finding some element in an ordered linked list would require _____O(n/2)_____operations (average case)?
- 7) Finding some element in an unordered linked list would require _____O(n)____ operations (worst case)?


- 8) For each of the following, count the number of operations where some_statement is executed based on the loops

- 8A) n^2
```cpp
//A
for (int I = 0; I < n; I++)
    for (int j = 1; j < n; j++)
        {some_statement;}
```
- 8B) n/2
```cpp
//B
for (int I = 0; I < n; I +=2)
    for (int j = 1; j < n; j++)
        {some_statement;}
```

- 8C) n log n
```cpp
//C
for (int j = 1 ; j < n ; j *= 2)
    for (int I = 1; i<n; i++)
        {some_statement;} 
```

At most, how many comparisons are required to search a sorted vector of 1023 elements using the binary
search algorithm? 10 comparisons would happen because 2 to the power of 10 is equal to 1023.

In each of the following examples, please choose the best data structure(s).
- 9) Options are: **Array, Linked Lists, Stack, Queues, Trees, Graphs, Sets, Hash Tables**. 
- 10) Note that there may not be one clear answer.

- 10) You have to store social network “feeds”. You do not know the size, and things may need to be dynamically added.
	 Stack because it puts the most recent post at the top.
- 11) You need to store undo/redo operations in a word processor.
	 Stack because you can pop off the most recent page to go back to the page before it.
- 12) You need to evaluate an expression (i.e., parse). 
	 Queue, using a priority queue the algorithm would evaluation the expression based on precendence.
- 13) You need to store the friendship information on a social networking site. I.e., who is friends with who.
	 Graph, shows the relationship of a person's friends and also the friends that they have in common as well.
- 14) You need to store an image (1000 by 1000 pixels) as a bitmap. 
	 Array, a 2d array can be used to store the size of the bitmap.
- 15) To implement printer spooler so that jobs can be printed in the order of their arrival. 
	 Queue, uses first in first out to maintain the order of arrival for the print jobs.
- 16) To implement back functionality in the internet browser.
	 Stack, pops off the most recent page and makes the page below it the current page.
- 17) To store the possible moves in a chess game.
	Linked list, it is dynamic and can fix its size and can hold all possible moves of each piece in its own node. 
- 18) To store a set of fixed key words which are referenced very frequently.
	 Queue, using a priority queue a value could be assigned based on how frequently a word is used.
- 19) To store the customer order information in a drive-in burger place. (Customers keep on coming and they have to get their correct food at the payment/food collection window.)
	 Queue, the orders are given based on the arrival of the customer.
- 20) To store the genealogy information of biological species.
	 Tree, a binary tree would work to show the relationship of decendence from the leaf to the root.
- 21) To store an alphabetized list of names in order to look up quickly. 
	 Array, any node can be accessed with O(1) and search has a O(n).

## Deliverables

- Edit this file and add your answers using markdown!
- Create a folder called `H03` in your assignments folder.
- Put a copy of your markdown file in this folder, and call it README.md.
- Upload to github sometime close to the due date.
- Print out your banner ON ITS OWN PAGE

```
H03
3013
LASTNAME
```

- Print out a hard copy of the file as well. Do not print directly from github. Either use `gitprint` or make it a pdf and print it.
- Make sure you answer thoroughly using complexities where appropriate and/or explaining your choices etc.
