package taocp

import "testing"

func TestAlgoL(t *testing.T) {
	//fmt.Print("Nihonggo")
	/*
		for n := 2; n <= 15; n++ {
			var k float64
			k = float64(n)
			expr := Ppow2(k) //Ppow(2, 5)
			fmt.Printf("%d : %f\n", n, expr)
		}
	*/
	var n uint64
	n = 4
	AlgoL(n)

}
