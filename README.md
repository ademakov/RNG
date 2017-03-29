# RNG
A simple C++ random number generator

The RNG uses Sebastiano Vigna's [xoroshiro128+ algorithm](http://xoroshiro.di.unimi.it/).

It produces 64-bit integers. In my simple test the performance is
30 percent higher than mt19937_64 from the C++ standard library:

```
500000000 rng128 calls
    0.954901 sec
500000000 mt19937_64 calls
    1.66395 sec
```
