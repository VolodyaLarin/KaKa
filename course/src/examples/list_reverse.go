package main

import "fmt"

type Node struct {
	data     int
	nextNode *Node
}

func newNode(data int, next *Node) Node {
	var node Node
	node.data = data
	node.nextNode = next
	return node
}

func printNode(list *Node) {
	var node *Node = list

	for 0; node != nil; 0 {
		printf("%d -> ", (*node).data)
		node = (*node).nextNode

	}
	printf("nil\n")
}

func reverseNode(list *Node) *Node {
	var newList *node = nil
	var node *Node = list
	for 0; node != nil; 0 {
		var tmpNode *Node = (*node).nextNode
		(*node).nextNode = newList
		newList = node
		node = tmpNode
	}
	return newList
}

func main() int {
	var node_container [5]Node

	node_container[0] = newNode(228, &(node_container[1]))
	node_container[1] = newNode(11, &(node_container[2]))
	node_container[2] = newNode(12, &(node_container[3]))
	node_container[3] = newNode(13, &(node_container[4]))
	node_container[4] = newNode(14, nil)

	printNode(&(node_container[0]))

	var newList *Node = reverseNode(&(node_container[0]))

	printNode(newList)

	return 0
}
