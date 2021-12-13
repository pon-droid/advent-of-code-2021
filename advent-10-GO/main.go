package main

import (
	"bufio"
	"log"
	"os"

	"fmt"
)

type stack []byte

//func (s stack) empt() bool { return len(s) == 0 }

func (s stack) top() byte { return s[len(s)-1] }

func (s *stack) push(i byte) { (*s) = append((*s), i) }

func (s *stack) pop() byte {
	d := (*s)[len(*s)-1]
	(*s) = (*s)[:len(*s)-1]
	return d
}

func (s stack) size() int { return len(s) }

func main() {
	serial := []string{}
	file, err := os.Open("input.txt")
	if err != nil {
		log.Fatal(err)
	}

	op_t := make(map[byte]byte)

	op_t[40] = 41
	op_t[91] = 93
	op_t[123] = 125
	op_t[60] = 62
	/*
		scores := make(map[byte]int)

		scores[41] = 3
		scores[93] = 57
		scores[125] = 1197
		scores[62] = 25137
	*/

	scores := make(map[byte]int)

	scores[41] = 1
	scores[93] = 2
	scores[125] = 3
	scores[62] = 4
	scanner := bufio.NewScanner(file)

	for scanner.Scan() {
		//fmt.Println(scanner.Text())
		temp := scanner.Text()
		serial = append(serial, temp)
	}
	/*
		for i := range serial {
			var begin stack
			var temp string = serial[i]
			var corrupt bool = false
			for j := 0; j < len(temp); j++ {
				//fmt.Printf("%c\n", temp[j])
				val, ok := op_t[temp[j]]
				if ok {
					begin.push(temp[j])
					println(val)
				} else if begin.size() == 0 || op_t[begin.top()] != temp[j] {
					corrupt = true
					sum += scores[temp[j]]
				} else {
					begin.pop()
				}
				if corrupt == true {
					break
				}


			}

		}
	*/
	var total []int
	for i := range serial {
		var begin stack
		var temp string = serial[i]
		var corrupt bool = false
		for j := 0; j < len(temp); j++ {
			//fmt.Printf("%c\n", temp[j])
			val, ok := op_t[temp[j]]
			if ok {
				begin.push(temp[j])
				println(val)
			} else if begin.size() == 0 || op_t[begin.top()] != temp[j] {
				corrupt = true
				//sum += scores[temp[j]]
			} else {
				begin.pop()
			}
			if corrupt {
				continue
			}
			var sum int = 0
			for begin.size() != 0 {

				ch := op_t[begin.top()]
				begin.pop()

				sum = sum * 5
				sum = sum + scores[ch]

			}

			total = append(total, sum)

		}

	}
	/*
		index := (len(total) / 2)
		println("=====================")
		for i := range total {
			println(total[i])
		}
		println("ANSWER IS ")
		println(total[index])
	*/
	println("==========================")
	for i := range total {
		println(total[i])
	}

}

func Calc(element []byte) int {
	var sum int = 0
	for i := range element {
		switch element[i] {
		case 41:
			sum = sum*5 + 1
		case 93:
			sum = sum*5 + 2
		case 125:
			sum = sum*5 + 3
		case 62:
			sum = sum*5 + 4
		}
	}
	fmt.Printf("Sum: ", sum)
	return sum
}
