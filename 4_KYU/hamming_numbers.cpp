#include <iostream>
#include <cstdint>
#include <vector>

class multiplier {
    public:
    multiplier(uint64_t m) {
        number = m;
        product = 2;
        end = false;
    }
    
    bool ended() {
        return end;
    }
    uint64_t getNumber() {
        return number;
    }
    uint64_t getProduct() {
        return product;
    }
    uint64_t show() {
        if(number*product < number) {
            return UINT64_MAX;
        }
        return number*product;
    }
    void next_product() {
        switch(product){
            case 2:
                product = 3;
                break;
            case 3:
                product = 5;
                break;
            case 5:
                end = true;
                break;
        }
    }

    private:
        uint64_t number;
        uint64_t product;
        bool end;
};

void print_vector (std::vector<multiplier> m) {
    for(auto n : m) {
        std::cout << n.getNumber() << " ";
    }
    std::cout << std::endl;
}

uint64_t hamber(int n) {
    std::vector<multiplier> multipliers;
    int minimal = 0;
    int first_pos = 0;

    multipliers.push_back(multiplier(1));

    while(multipliers.size() < n) {
        // La primera posición actual será la mínima
        minimal = first_pos;
        std::cout << "Starting in " << minimal << " (of "<< multipliers.size() - 1 << ")"<< std::endl;

        // Se busca el múltiplo más pequeño que no haya sido visitado
        for(unsigned long i = first_pos; i < multipliers.size(); i++){
            if(multipliers[i].show() <= multipliers[minimal].show()){
                minimal = i;
            }
        }
        std::cout << "Smallest product: " << multipliers[minimal].show();

        // Se añade el múltiplo más pequeño al vector
        if(multipliers[minimal].show() > multipliers.back().getNumber()){
            multipliers.push_back(multipliers[minimal].show());
            std::cout << " PUSHED";
        } else {
            std::cout << " < " << multipliers.back().getNumber();
        }

        std::cout << std::endl;

        // El múltiplo más pequeño aumenta su producto
        multipliers[minimal].next_product();
        std::cout << "Now " << multipliers[minimal].getNumber() << " multiplies to " << 
        multipliers[minimal].show() << std::endl;

        // Se comprueba si el múltiplo acabó
        if(multipliers[minimal].ended()) {
            first_pos = minimal + 1;
            std::cout << multipliers[minimal].getNumber() << " Ended." << std::endl;
        }
    }

    return multipliers.back().getNumber();
}

int main () {
    std::cout << "RESULTADO: " << hamber(4);
    return 0;
}