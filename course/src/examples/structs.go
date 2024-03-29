package main

import "fmt"

type person struct {
	name string
	age  int
	son  struct {
		a int
	}
}

func newPerson(name string) person {
	var p person
	p.name = name
	p.age = 42
	p.son.a = 12
	return p
}

func printPerson(p person) {
	fmt.Printf("Person %s: %d age, son.a = %d\n", p.name, p.age, p.son.a)
}

func main() {
	vasya := newPerson("Vasya")
	printPerson(vasya)

	vasya.age = vasya.age / 2
	printPerson(vasya)

	var dog struct {
		name   string
		isGood bool
	}

	dog.name = "Rex"
	dog.isGood = true

	fmt.Printf("Dog %s %d\n", dog.name, dog.isGood)
}
