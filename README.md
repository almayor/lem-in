# lem-in

*This project is part of the official curriculum at [School 42](https://en.wikipedia.org/wiki/42_(school)).*

## Disclaimer

> At [School 42](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written to comply with a coding standard (also known as the "[Norm](./docs/subjects/norme.en.pdf)"). As a result, the implementation of certain parts may appear strange.

## Algorithm


## Overview

* [Official instructions](docs/subjects/lem-in.en.pdf)
* [Code documentation](https://almayor.github.io/lem-in)
* This project practices the following algorithmic topics
	* minimum cost maximum flow (Ford-Fulkerson, Suurballe)
	* path search in directed graphs (BFS, Dijkstra, Bellman-Ford)
	* sorts (quick sort, insertion sort)
	* efficient data representation (priority quues, graphs, arrays, queues, linked lists)

## Run

To compile, run

```sh
git clone https://github.com/almayor/lem-in
cd lem-in
git submodule --init --recursive
make
```
Then try some example maps

```sh
./lem-in < example-maps/flow-thousand.txt
```
or generate your own

```sh
./generator --flow-thousand | ./lem-in
```

(_NOTE_ that the `generator` has only been made available to us in a Linux compilation.)

## Test

Your can check that a generated solution is correct using the provided Python script `check-solution`

```sh
./lem-in < {your-map} | ./check-solution
```

Alternatively, you can run the whole batch of included tests with

```sh
make test
```

## Acknowledgements

We are grateful to the entire team behind School 42 and its [Moscow branch](https://21-school.ru
), as well as to my fellow students for help and support. Some ideas for tests found in `example-maps` are borrowed from a [similar project](https://github.com/davhojt/lem_in) by [davhojt](https://github.com/davhojt).

---
If you have any questions, please contact me on Github.
