function fibonacciSeries(number) {
  let n1 = 0,
    n2 = 1,
    nextterm;
  for (let i = 0; i < number; i++) {
    console.log(n1);
    nextterm = n1;
    n1 = n2;
    n2 = nextterm + n2;
  }
}

fibonacciSeries(12)