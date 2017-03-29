# RNG
A simple C++ random number generator

The RNG uses Sebastiano Vigna's [xoroshiro128+ algorithm](http://xoroshiro.di.unimi.it/xoroshiro128plus.c).

It produces 64-bit integers. In my simple test its performance is more
than five times higher than mt19937_64 from the C++ standard library:

```
1000000000 rng128 calls
    0.2919 sec
1000000000 mt19937_64 calls
    1.59899 sec
```

As for the quality of the generator please refer to the results on
[Sebastiano Vigna's page](http://xoroshiro.di.unimi.it/).
