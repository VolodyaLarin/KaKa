package main

func retTrue(n int) bool {
	printf("TrueCall%d ", n)
	return true
}
func retFalse(n int) bool {
	printf("FalseCall%d ", n)
	return false
}

func main() {
	printf("\nres of true(1)  && true(2)  %d\n\n", (retTrue(1) && retTrue(2)))
	printf("\nres of false(1) && true(2)  %d\n\n", (retFalse(1) && retTrue(2)))
	printf("\nres of true(1)  && false(2) %d\n\n", (retTrue(1) && retFalse(2)))
	printf("=====\n")
	printf("\nres of true(1)  || true(2)  %d\n\n", (retTrue(1) || retTrue(2)))
	printf("\nres of false(1) || true(2)  %d\n\n", (retFalse(1) || retTrue(2)))
	printf("\nres of true(1)  || false(2) %d\n\n", (retTrue(1) || retFalse(2)))
}
