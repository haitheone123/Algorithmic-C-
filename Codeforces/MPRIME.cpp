#include <iostream>
#include <vector>
#include <list>
#include <math.h>

int main()
{
    std::ios::sync_with_stdio(false);
    unsigned int count = 0;
    unsigned int order, current = 6;
    uint64_t final_number = 0;
    std::vector <uint64_t> primes;
    std::list <uint64_t> final_list;
    std::cin >> order;
    primes.push_back(2); primes.push_back(3); primes.push_back(5); primes.push_back(7); primes.push_back(11); primes.push_back(13);
    final_list.push_back(23); final_list.push_back(57); final_list.push_back(1113);
    while(count < order){
        final_number = final_list.front();
        final_list.pop_front();
        uint64_t sqrt_out = sqrt(final_number) + 1;
            //tạo vector số nguyên tố nhỏ hơn căn số ghép hoặc số ghép chia 2
        for(uint64_t i = (*(primes.end() - 1)) + 2; i <= ((current >= primes.size() - 2) ? (final_number / 2 + 1) : sqrt_out); i += 2){
            uint64_t sqrt_in = sqrt(i) + 1;
            bool checked_in = true;
            for (std::vector<uint64_t>::iterator it = primes.begin() + 1 ; it != primes.end(); ++it){
                if(i%(*it) == 0) {
                    checked_in = false;
                    break;
                }
                if((*it) >= sqrt_in)    break;
            }
            if(checked_in)    primes.push_back(i);
        }
            // check số ghép có phải số nguyên tố
        bool checked_out = true;
        for (std::vector<uint64_t>::iterator it = primes.begin() ; it != primes.end(); ++it){
            if(final_number % (*it) == 0){
                checked_out = false;
                break;
            }
            if((*it) >= sqrt_out)   break;
        }
        if(checked_out) count++;
            //thêm số ghép vào list
        if(final_list.size() == 0 && current < primes.size() - 2){
            uint64_t x1 = primes.at(current), x2 = primes.at(current+1);
            while(x2 != 0) {
                x1 *= 10;
                x2 /= 10;
            }
            final_list.push_back(x1 + (primes.at(current+1)));
            current += 2;
        }
    }
    std::cout <<  final_number << "\n";
	return 0;
}