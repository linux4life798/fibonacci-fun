package main

import "os"
import "fmt"
import "strconv"

/* Compute the n'th Fibonacci number recursively */
func fib(n int) int {
	if n <= 2 {
		return 1
	} else {
		return fib(n-2) + fib(n-1)
	}
}

func usage() {
	fmt.Printf("This program will calulate the n'th fibonacci number.\n")
	fmt.Printf("Usage: %s <n>\n", "fib_go")
	fmt.Printf("n - specifies that we want the n'th fibonacci number\n")
}

func main() {
	if len(os.Args) != 2 {
		fmt.Println("Error - Insufficient or excess arguments.\n")
		usage()
		os.Exit(1)
	}

	n,err := strconv.Atoi(os.Args[1])
	if err != nil {
		fmt.Println("Error - The argument could not be parsed as an integer\n")
		//fmt.Println(err)
		usage()
		os.Exit(1)
	}
	if n  < 0 {
		fmt.Println("Error - Cannot compute fibonacci of a negative value yet")
		os.Exit(2)
	}

	fmt.Printf("fib(%d) = ", n)
	fmt.Println(fib(n))
}
