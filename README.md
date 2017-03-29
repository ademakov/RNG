# RNG
A simple C++ random number generator. It uses the latest and fastest
Sebastiano Vigna's algorithm: [xoroshiro128+](http://xoroshiro.di.unimi.it/xoroshiro128plus.c).

It produces 64-bit integers. In my simple test it is more than five times
faster than the mt19937_64 generator from the C++ standard library:

```
1000000000 rng128 calls
    0.2919 sec
1000000000 mt19937_64 calls
    1.59899 sec
```

As for the quality of the generator please refer to the results on
[Sebastiano Vigna's page](http://xoroshiro.di.unimi.it/).

In addition to the RNG itself there are two utility classes that
produce 64-bit seeds for initializing the RNG. One extracts entropy
from the system scheduler measuring it with x86 rdtsc instruction.
The other uses std::random_device from the standard C++ library.

Sample code:

```
rng::tsc_seed seed;
rng::rng128 gen(seed());
std::cout << "a random number: " << gen() << "\n";
```

On Linux random_device_seed is faster than tsc_seed. But on macOS
it is other way round.
