# RNG
A simple C++ random number generator

The RNG uses Sebastiano Vigna's [xoroshiro128+ algorithm](http://xoroshiro.di.unimi.it/).

It only produces 64-bit integers. In my simple tests the performance is
30 percent higher than mt19937_64 from the C++ standard library.
