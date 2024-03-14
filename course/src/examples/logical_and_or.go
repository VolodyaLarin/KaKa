package main

import "fmt"

func retTrue(n int) bool {
	fmt.Printf("TrueCall%d ", n)
	return true
}
func retFalse(n int) bool {
	fmt.Printf("FalseCall%d ", n)
	return false
}

func main() {
	fmt.Printf("\nres of true(1)  && true(2)  %d\n\n", (retTrue(1) && retTrue(2)))
	fmt.Printf("\nres of false(1) && true(2)  %d\n\n", (retFalse(1) && retTrue(2)))
	fmt.Printf("\nres of true(1)  && false(2) %d\n\n", (retTrue(1) && retFalse(2)))
	fmt.Printf("=====\n")
	fmt.Printf("\nres of true(1)  || true(2)  %d\n\n", (retTrue(1) || retTrue(2)))
	fmt.Printf("\nres of false(1) || true(2)  %d\n\n", (retFalse(1) || retTrue(2)))
	fmt.Printf("\nres of true(1)  || false(2) %d\n\n", (retTrue(1) || retFalse(2)))
}
