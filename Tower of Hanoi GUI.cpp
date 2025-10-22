#include <SFML/Graphics.hpp> 
#include <iostream> 
#include <cmath> 
#include <vector> 
#include <thread> 
#include <chrono> 
using namespace std;
using namespace sf;
const int MOVE_DELAY = 500;
RenderWindow window(VideoMode(900, 600), "Tower of Hanoi - Visualization"); 
    struct Disk { RectangleShape shape; int peg; };
void drawScene(vector<vector<Disk>>& pegs) {
    window.clear(Color(30, 30, 30));
    for (int i = 0; i < 3; i++) {
        RectangleShape peg(Vector2f(10, 300));
        peg.setFillColor(Color(200, 200, 200));
        peg.setPosition(200 + i * 250, 250);
        window.draw(peg);
    }
    for (int i = 0; i < 3; i++) {
        int height = 0;
        for (auto& disk : pegs[i]) {
            disk.shape.setPosition(150 + i * 250 +
                (50 - disk.shape.getSize().x / 2), 530 - height * 25);
            window.draw(disk.shape);
            height++;
        }
    }
    window.display();
    this_thread::sleep_for(chrono::milliseconds(MOVE_DELAY));
}
void Tower_of_Hanoi(int n, int src, int to, int aux,
    vector<vector<Disk>>& pegs) {
    if (n == 1) {
        Disk disk = pegs[src].back();
        pegs[src].pop_back();
        pegs[to].push_back(disk);
        drawScene(pegs);
        return;
    }
    Tower_of_Hanoi(n - 1, src, aux, to, pegs);
    Disk disk = pegs[src].back();
    pegs[src].pop_back();
    pegs[to].push_back(disk);
    drawScene(pegs);
    Tower_of_Hanoi(n - 1, aux, to, src, pegs);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    vector<vector<Disk>> pegs(3);
    for (int i = n; i >= 1; i--) {
        Disk d;
        d.shape.setSize(Vector2f(30 + i * 20, 20));
        d.shape.setFillColor(Color(100 + i * 20, 50 + i * 30, 200 - i *
            15));
        d.peg = 0;
        pegs[0].push_back(d);
    }

    drawScene(pegs);
    this_thread::sleep_for(chrono::seconds(1));
    Tower_of_Hanoi(n, 0, 2, 1, pegs);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
    }
}