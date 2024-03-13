package main

import "fmt"

func main() {

	var a = "initial"
	printf("%s\n", a)

	var b, c int = 1, 2
	printf("%d %d\n", b, c)

	var d = true
	printf("%d\n", d)

	var e int
	printf("%d\n", e)

	var (
		product      = "Mobile"
		quantity int = 50
		price        = 50.50
		inStock      = true
	)

	printf("%s %d %lf %d\n", product, quantity, price, inStock)

	f := "apple"
	printf("%s\n", f)

	m, n, o := 1, 2, 3
	printf("%d %d %d\n", m, n, o)

	m, _, s := 5, 6, "hello"

	printf("%d %s\n", m, s)

	m, n, o = 10, 11, 12
	printf("%d %d %d\n", m, n, o)

	m, _, o = 20, 21, 22
	printf("%d %d\n", m, o)
}
