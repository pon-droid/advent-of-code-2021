package main

import (
	"bufio"
	"log"
	"os"
	"strconv"
)

var flashes int = 0

func main() {
	cave := []int{}

	//flashed := []bool{}
	file, err := os.Open("input.txt")
	if err != nil {
		log.Fatal(err)
	}

	scanner := bufio.NewScanner(file)
	const S = 10
	for scanner.Scan() {
		temp := scanner.Text()
		for i := 0; i < S; i++ {
			btI, _ := strconv.Atoi(string(temp[i]))
			cave = append(cave, btI)
		}

	}

	print_cave(cave, S, S)
	for i := 0; i < 500; i++ {
		increment(&cave, S)

		glowing(&cave, S)

		if all_flash(cave, S) {
			println("+++++++++++++++++")
			println(i)
			break
		}

		print_cave(cave, S, S)

	}

	println(flashes)

}

func all_flash(cave []int, S int) bool {
	yes := true
	for i := range cave {
		if cave[i] != 0 {
			yes = false
		}
	}
	return yes
}

func flash(cave *[]int, S int, x int, y int) {
	(*cave)[y*S+x] = 0
	for row := -1; row <= 1; row++ {
		for col := -1; col <= 1; col++ {
			nx := x + col
			ny := y + row

			if nx < 0 || nx >= S || ny < 0 || ny >= S {
				continue
			}

			if (*cave)[ny*S+nx] == 0 {
				continue
			}

			(*cave)[ny*S+nx]++

		}
	}

}

func glowing(cave *[]int, S int) {
	unstable := false
	for y := 0; y < S; y++ {
		for x := 0; x < S; x++ {
			if (*cave)[y*S+x] > 9 {
				unstable = true
				flashes++
				flash(cave, S, x, y)
			}
		}
	}

	if unstable {
		glowing(cave, S)
	}
}

func increment(cave *[]int, S int) {
	for y := 0; y < S; y++ {
		for x := 0; x < S; x++ {
			(*cave)[y*S+x]++
		}
	}
}

func print_cave(cave []int, HEIGHT int, WIDTH int) {
	for y := 0; y < HEIGHT; y++ {
		for x := 0; x < WIDTH; x++ {
			print(cave[y*WIDTH+x])
		}
		print("\n")
	}
	println("====================")
}
