# handmade-grep
### a small grep clone written in C++, a fun project to learn C++ and regex

## Features

### ✅ Implemented
- [x] Read file and process line by line
- [x] Literal character matching
- [x] Digit pattern matching (`\d`)
- [x] Command line arguments parsing
- [x] Support for multiple files
- [x] Standard input (stdin) support
- [x] Line number output with filename
- [x] Mixed pattern support (literal + regex)

### 🚧 Planned Features
- [ ] Multiple regex patterns in single search
- [ ] Case insensitive search (`-i` flag)
- [ ] Whole word search (`-w` flag)
- [ ] More regex patterns (`\w`, `\s`, `\n`, etc.)
- [ ] Character classes (`[abc]`, `[0-9]`)
- [ ] Quantifiers (`*`, `+`, `?`)
- [ ] Anchors (`^`, `$`)

## Supported Patterns

| Pattern | Description | Example |
|---------|-------------|---------|
| `literal` | Exact character matching | `hello` matches "hello world" |
| `\d` | Any digit (0-9) | `\d\d\d` matches "123" in "Order 123" |
| `mixed` | Combination of literal and patterns | `ID-\d` matches "ID-7" |

## Build Instructions

```bash
# Configure and build with CMake
cmake -B build -G "MinGW Makefiles"
cmake --build build
```

## Usage Examples

### Single file search:
```bash
./build/handmade-grep.exe "hello" test.txt
```

### Multiple files:
```bash
./build/handmade-grep.exe "hello" test.txt test2.txt
```

### Pattern matching with digits:
```bash
# Find any digit
./build/handmade-grep.exe "\d" test.txt

# Find 3 consecutive digits
./build/handmade-grep.exe "\d\d\d" test.txt

# Find mixed patterns
./build/handmade-grep.exe "Order \d" test.txt
./build/handmade-grep.exe "ID-\d" test.txt
```

### Use with pipe (stdin):
```bash
cat test.txt | ./build/handmade-grep.exe "hello"
echo "Test 123" | ./build/handmade-grep.exe "\d"
```

### Interactive mode:
```bash
./build/handmade-grep.exe "pattern"
```

## Sample Output

```bash
$ ./build/handmade-grep.exe "\d" test.txt
test.txt:2:Order 123
test.txt:3:Phone: 555-1234
test.txt:4:ID-7 is valid

$ ./build/handmade-grep.exe "hello" file1.txt file2.txt
file1.txt:1:hello world
file2.txt:3:say hello
```

## Project Structure

```
mygrep/
├── src/
│   ├── main.cpp      # Main program entry point
│   └── grep.cpp      # Core grep implementation
├── include/
│   └── grep.h        # Header file with class definition
├── CMakeLists.txt    # Build configuration
└── README.md         # This file
```