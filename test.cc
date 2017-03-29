#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "rng.h"

int
main()
{
	std::cout << std::hex << std::setfill('0');
	std::cout << "tsc_seed test:\n";
	for (int i = 0; i < 4; i++)
		std::cout << "\t0x" << std::setw(16) << rng::tsc_seed{}() << '\n';
	std::cout << "\nrandom_device_seed test:\n";
	for (int i = 0; i < 4; i++)
		std::cout << "\t0x" << std::setw(16) << rng::random_device_seed{}() << '\n';

	const int n_seed = 100'000;
	std::cout << std::dec << "\n";
	{
		auto start = std::chrono::steady_clock::now();

		for (int i = 0; i < n_seed; i++)
			rng::tsc_seed{}();

		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << n_seed << " tsc_seed calls\n\t" << diff.count() << " sec\n";
	}
	{
		auto start = std::chrono::steady_clock::now();

		for (int i = 0; i < n_seed; i++)
			rng::random_device_seed{}();

		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << n_seed << " random_device_seed calls\n\t" << diff.count()
			  << " sec\n";
	}

	const int n_gen = 1'000'000'000;
	std::cout << "\n";
	{
		rng::rng128 rng;
		uint64_t no_opt = 0;

		auto start = std::chrono::steady_clock::now();

		for (int i = 0; i < n_gen; i++) {
			std::atomic_signal_fence(std::memory_order_relaxed);
			no_opt |= rng();
		}

		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << n_gen << " rng128 calls\n\t" << diff.count() << " sec\n";
	}
	{
		std::mt19937_64 rng;
		uint64_t no_opt = 0;

		auto start = std::chrono::steady_clock::now();

		for (int i = 0; i < n_gen; i++) {
			std::atomic_signal_fence(std::memory_order_relaxed);
			no_opt |= rng();
		}

		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << n_gen << " mt19937_64 calls\n\t" << diff.count() << " sec\n";
	}

	return EXIT_SUCCESS;
}
