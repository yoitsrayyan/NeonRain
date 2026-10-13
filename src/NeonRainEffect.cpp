// Needed libraries for the Neon Rain Effect
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cstdlib>

// Screen size constants
const int SCREEN_WIDTH = 240;
const int SCREEN_HEIGHT = 72;

// Function to generate a random character for the rain effect
char getRandomChar() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    return charset[rand() % (sizeof(charset) - 1)];
}

std::string getRandomColor() {
    std::string colors[] = {
        "\033[38;2;0;255;255m",
        "\033[38;2;255;0;128m",
        "\033[38;2;170;0;255m",
        "\033[38;2;255;255;0m",
        "\033[38;2;0;100;255m"
    };

    return colors[rand() % 5];
}

// Function to clear the console screen
void clearScreen() {
    // ANSI escape code to clear the screen
    std::cout << "\033[2J\033[1;1H";
}

// Function to create the neon rain effect
void neonRainEffect() {
    std::vector<int> rainY(SCREEN_WIDTH);
    std::vector<int> tailLength(SCREEN_WIDTH);
    std::vector<std::string> rainColors(SCREEN_WIDTH);

    for (int i = 0; i < SCREEN_WIDTH; i++) {
        rainY[i] = -(rand() % SCREEN_HEIGHT); 
        tailLength[i] = (rand() % 40);
        rainColors[i] = getRandomColor();
    }

    //main loop
    while(true) {
        clearScreen();
    
        
        for (int i = 0; i < SCREEN_WIDTH; i++) {
            int y = rainY[i];
            int length = tailLength[i];
            std::string tailColor = rainColors[i];

            for(int j = 0; j < length; j++) {
                int drawY = y - j;

                if (drawY > 0 && drawY <= SCREEN_HEIGHT) {
                    std::cout << "\033[" << drawY << ";" << i << "H";
                    
                    if (j == 0) {
                        std::cout << "\033[1;37m"; 
                    } else {
                        std::cout << tailColor;
                    }
                    std::cout << getRandomChar();
                }
            }

            if (rand() % 10 < 8) {
                rainY[i]++; 
            }

            
            if (rainY[i] - length >= SCREEN_HEIGHT) {
                rainY[i] = -(rand() % 5); 
                rainColors[i] = getRandomColor();
            }
        }
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        }
}

int main() {
    std::cout << "\033[?25l";

    neonRainEffect();

    return 0;
}