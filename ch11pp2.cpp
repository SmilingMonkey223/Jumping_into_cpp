#include <iostream>
#include <string>

using namespace std;



struct SpaceShip {
  int x_coordinate;
  int y_coordinate;  
};

SpaceShip NewShip () {
  SpaceShip ship;
  ship.x_coordinate = 0;
  ship.y_coordinate = 0;
  return ship;
}

SpaceShip moveShip (SpaceShip ship) {
  ship.x_coordinate += 231;
  return ship;
}

int main() {
  bool ships_on_screen = true;
  int amount_of_ships = 3;
  SpaceShip my_ships[amount_of_ships];
  for (int i = 0; i < amount_of_ships; i++) {
    my_ships[i] = NewShip();
  }
  while (ships_on_screen) {
    int ship_num = 1;
    for (int i = 0; i < amount_of_ships; i++) { 
      cout << "Ship number: "<< ship_num << endl << "is currently at x coordinate " << my_ships[i].x_coordinate << endl 
        << "only " << 1024 - my_ships[i].x_coordinate << "meters until it is out of the area!\n";
      my_ships[i] = moveShip(my_ships[i]);
      ship_num++;
    }
    if (my_ships[2].x_coordinate > 1024) {
      ships_on_screen = false; 
    }
  }
  cout << "all ships are now out of the area, successfully gone\n";

}
