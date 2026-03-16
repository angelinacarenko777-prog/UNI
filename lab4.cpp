#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Player {
private:
    string name;
    int id;

public:
    Player(string name, int id) {
        this->name = name;
        this->id = id;
    }

    void printInfo() const {
        cout << "Player{name: " << name << ", id: " << id << "}" << endl;
    }
};

class Team {
private:
    string teamName;
    vector<Player*> players;

public:
    Team(string teamName) {
        this->teamName = teamName;
    }

    void addPlayer(Player* player) {
        players.push_back(player);
    }

    void removePlayer(Player* player) {
        players.erase(remove(players.begin(), players.end(), player), players.end());
    }

    void showTeamInfo() const {
        cout << "Team: " << teamName << endl;

        for (const auto& player : players) {
            player->printInfo();
        }
    }
};

class Door {
private:
    double width;
    double height;

public:
    Door(double width, double height) {
        this->width = width;
        this->height = height;
    }

    void printInfo() const {
        cout << "Door width: " << width << " height: " << height << endl;
    }
};

class Window {
private:
    double width;
    double height;

public:
    Window(double width, double height) {
        this->width = width;
        this->height = height;
    }

    void printInfo() const {
        cout << "Window width: " << width << " height: " << height << endl;
    }
};

class Room {
private:
    string type;

public:
    Room(string type) {
        this->type = type;
    }

    void printInfo() const {
        cout << "Room type: " << type << endl;
    }
};

class House {
private:
    vector<Room> rooms;
    vector<Door> doors;
    vector<Window> windows;

public:
    House() {
        rooms.emplace_back("Bedroom");
        rooms.emplace_back("Kitchen");
        rooms.emplace_back("Bathroom");

        doors.emplace_back(90, 200);
        doors.emplace_back(80, 200);

        windows.emplace_back(120, 100);
        windows.emplace_back(150, 120);
    }

    void showHouseInfo() const {

        cout << "\nHouse information:\n";

        cout << "\nRooms:\n";
        for (const auto& room : rooms) {
            room.printInfo();
        }

        cout << "\nDoors:\n";
        for (const auto& door : doors) {
            door.printInfo();
        }

        cout << "\nWindows:\n";
        for (const auto& window : windows) {
            window.printInfo();
        }
    }
};

int main() {

    Player p1("Alice", 1);
    Player p2("Bob", 2);
    Player p3("Charlie", 3);

    Team team("SuperStars");

    team.addPlayer(&p1);
    team.addPlayer(&p2);
    team.addPlayer(&p3);

    cout << "Team information:\n";
    team.showTeamInfo();

    cout << "\nPlayer exists outside team:\n";
    p1.printInfo();

    House house;

    house.showHouseInfo();

    cout << "\nDeleting house...\n";

    return 0;
}