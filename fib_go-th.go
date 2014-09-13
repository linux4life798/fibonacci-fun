package main

import "os"
import "fmt"
import "strconv"


/* Keeps track of the number of go threads used */
var go_count int64 = 0

/* Compute the n'th Fibonacci number recursively */
func fibg(n int, ch chan int) {
	go_count++

	if n <= 2 {
		ch <- 1
	} else {
		ch1 := make(chan int)
		ch2 := make(chan int)

		go fibg(n-2, ch1)
		go fibg(n-1, ch2)

		f1 := <-ch1
		f2 := <-ch2

		ch <- (f1+f2)
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

	ch := make(chan int)
	go fibg(n, ch)
	res := <-ch
	fmt.Println(res)

	fmt.Printf("Number of threads used: %d\n", go_count)
}
