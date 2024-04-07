# 42-malloc

This project provides a custom implementation of the `malloc`, `free`, and `realloc` functions in C. It's designed to be used as a shared library that can be preloaded to replace the standard library functions.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

- Docker
- Visual Studio Code with Remote - Containers extension

### Setup

1. Clone the repository:

```sh
git clone https://github.com/yourusername/42-malloc.git
cd 42-malloc
```

2. Open the project in Visual Studio Code.

3. When prompted to "Reopen in Container", click "Reopen in Container". This will start the Docker container and set up your development environment. This can take a few minutes the first time you do it.

If you're not prompted, you can also press `F1`, type "Remote-Containers: Reopen Folder in Container", and press `Enter`.

### Build

Once you're in the Docker container, you can build the project by running:

```sh
make
```

This will compile the C files and create a shared library `libft_malloc.so`.

### Usage

To use the custom `malloc`, `free`, and `realloc` functions, you need to preload the shared library. 
This can be done specifically for the program being executed as follows:
```sh
LD_PRELOAD=$(pwd)/libft_malloc.so ls
```

Alternatively, you can set the `LD_PRELOAD` environment variable for the entire terminal session like this:


```sh
export LD_PRELOAD=$(pwd)/libft_malloc.so
```

Now, any program you run in the same terminal session will use your custom memory allocation functions instead of the standard library functions.

## Contributing

Please read CONTRIBUTING.md for details on our code of conduct, and the process for submitting pull requests to us.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.

## TODO
- [X] block allocation
- [X] single allocation
- [X] single free
- [X] block free
- [X] struct for blockmetadata 
- [X] realloc
- [X] make reading/writing in blocks into struct for easier access so that offset and so gets easier
- [X] symbolic link

- [ ] alignment

- [ ] sorted zones for "quick" access
- [ ] lifetimes
- [ ] multithreading
- [ ] dynamic allocation
- [ ] size_t in max instead of uint32_t
- [ ] allignment %8 for f64 and stuff - LATER!!!
