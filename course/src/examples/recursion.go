package main

import "fmt"

func fact(n int) int {
	if n != 0 {
		return n * fact(n-1)
	}
	return 1
}

func main() {
	const n int = 7

	var res = fact(7)

	fmt.Printf("%d\n", res)
}
