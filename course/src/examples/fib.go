package main

import "fmt"

func fib(f1 int, f2 int, n int) {
	if n == 0 {
		fmt.Printf("Чиселко: %d", f2)
	} else {
		fib(f2, f1+f2, n-1)
	}
}

func main() {
	var x int = 0

	fmt.Printf("Введите номер: ")

	fmt.Scanf("%d", &x)

	if x > 20 {
		fmt.Printf("Я таких больших чисел не знаю")
	} else if x < 2 {
		fmt.Printf("Я в такое не умею")
	} else {
		fib(0, 1, x-2)
	}

	fmt.Printf("\n")
}
