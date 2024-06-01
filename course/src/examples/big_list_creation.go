package main

import "fmt"

type Node struct {
	data     [100000]int
	nextNode *Node
}

func newNode(next *Node) *Node {
	var node Node
	node.nextNode = next
	return &node
}

func main() {
	var head *Node = nil

	for j := 0; j < 10; j++ {

		for i := 0; i < 1000; i++ {
			head = newNode(head)
		}

		// 	printNode(head)
		head = nil
		fmt.Printf("OK\n")

		for i := 0; i < 1000000; i++ {
			continue
		}

		for i := 0; i < 200; i++ {
			head = newNode(head)
		}
		head = nil
		fmt.Printf("OK\n")

		for i := 0; i < 1000000; i++ {
			continue
		}

	}
}
