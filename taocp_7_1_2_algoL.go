package main

import (
	"fmt"
	"math"
)

func main() {
	//fmt.Print("Nihonggo")
	/*
		for n := 2; n <= 15; n++ {
			var k float64
			k = float64(n)
			expr := Ppow2(k) //Ppow(2, 5)
			fmt.Printf("%d : %f\n", n, expr)
		}
	*/
	var n uint
	n = 4
	AlgoL(n)

}

/*AlgoL is the implementation of 7.1.2 Algorithm L (Find normal lengths).
This algorithm determines L(f) for all normal truth tables 0 ≤ f < 2^(2^n-1),
by building lists of all nonzero normal functions of length r for r ≥ 0.
*/
func AlgoL(n uint) {

	// L1. Initialize.
	var mP = uint64(Ppow2(float64(n)))
	fmt.Printf("n: %d ppower: %d\n", n, mP)
	L := make([]uint64, mP)

	for i := range L {
		L[i] = math.MaxUint64
	}
	L[0] = 0

	type set64 map[uint64]bool

	//To check how many list will be needed.
	//for n = 4, seems the maximum length is 7 or 8?
	var list [10]set64
	for i := range list {
		list[i] = make(set64)
	}
	x := make([]uint64, n+1)
	for k := 1; k <= int(n); k++ {
		x[k] = uint64((math.Pow(2, (math.Pow(2, float64(n)))) - 1) / (math.Pow(2, (math.Pow(2, float64(int(n)-k)))+1)))
		fmt.Printf("%x ", x[k])
		var y = list[0]
		y[x[k]] = true

	}

	/*
		c := int(math.Pow(2, (math.Pow(2, float64(n)) - 1)))
		fmt.Printf("0x%x Number of places when L(f) = ∞", c)
	*/

}

//Ppow2 return base 2 power of n
func Ppow2(n float64) (expr float64) {

	return Ppow(2, n)
}

//Ppow return power of n with base
func Ppow(base float64, n float64) (expr float64) {
	expr = math.Pow(base, (math.Pow(base, n) - 1))
	return expr
}
