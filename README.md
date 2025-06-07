# handmade-grep
### a small grep clone written in C++, a fun project to learn C++ and regex

### inital implementation
- [x] read file
- [x] read file line by line
- [x] regex search
- [x] print results
- [x] command line arguments
- [x] support for multiple files
- [x] support for multiple regex patterns
- [x] support for case insensitive search
- [x] support for whole word search
- [x] support for line number output

Compile the soruce code with:

- for single file:
```
./build/handmade-grep.exe "hello" test.txt
```

- for multiple files:
```
./build/handmade-grep.exe "hello" test.txt test2.txt
```

- for multiple patterns:
```
./build/handmade-grep.exe "hello" "world" test.txt
```

- use with pipe:
```
cat test.txt | ./build/handmade-grep.exe "hello"
```