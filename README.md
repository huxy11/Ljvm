# Ljvm

- ## Backgournd

  It is frustrating when I code in Java not knowing how exactly the variables and methods are stored in memory and in what kind of organized structure. Therefore I am about to build an own jvm under the rules of official guide *The Java Virtual Machine Specification*. A rudimentary one of course.

- ## Introduction

- ### Phase 1:

  Implementing the very fundament, loading a class file with main function and execute it correctly. No other classes involed, no GC.

  To do that, we need only
  	- A generator to generates arbitrary java code and compiles it into .class file.
  	- A loader to parse .class file and load necessary bytes properly.
  	- A executor to fetch and execute instructions, a Turing Machine.

- 
