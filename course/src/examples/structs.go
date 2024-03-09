package main

import "fmt"

type person struct {
    name string
    age  int
    son struct {
        a int
    }
}

func newPerson(name string) person {
    var p person;
    p.name = name
    p.age = 42
    p.son.a = 12
    return p
}

func printPerson(p person) {
    printf("Person %s: %d age\n", p.name, p.age)
}

func main() {
    vasya := newPerson("Vasya")
    printPerson(vasya)

    vasya.age = vasya.age / 2
    printPerson(vasya)

   var dog struct {
        name   string
        isGood bool
    };

    dog.name = "Rex"
    dog.isGood = 1

    printf("Dog %s %d", dog.name, dog.isGood)
}