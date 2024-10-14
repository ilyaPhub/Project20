#include <iostream>
using namespace std;

class Reservoir {
private:
    char name[50];  
    double width, length, maxDepth;
    char type[20]; 

public:
    Reservoir() {
        name[0] = '\0';
        width = length = maxDepth = 0.0;
        type[0] = '\0';
        cout << "Викликано конструктор за замовчуванням.\n";
    }

    Reservoir(const char* n, double w, double l, double d, const char* t) {
        setName(n);
        width = w;
        length = l;
        maxDepth = d;
        setType(t);
        cout << "Викликано конструктор з параметрами.\n";
    }

    Reservoir(const Reservoir& other) {
        setName(other.name);
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
        setType(other.type);
        cout << "Викликано конструктор копіювання.\n";
    }

    ~Reservoir() {
        cout << "Об'єкт \"" << name << "\" видалено.\n";
    }

    void setName(const char* n) {
        int i = 0;
        while (n[i] != '\0' && i < 49) {  
            name[i] = n[i];
            ++i;
        }
        name[i] = '\0'; 
    }

    const char* getName() const {
        return name;
    }

    void setWidth(double w) { width = w; }
    double getWidth() const { return width; }

    void setLength(double l) { length = l; }
    double getLength() const { return length; }

    void setMaxDepth(double d) { maxDepth = d; }
    double getMaxDepth() const { return maxDepth; }

    void setType(const char* t) {
        int i = 0;
        while (t[i] != '\0' && i < 19) {
            type[i] = t[i];
            ++i;
        }
        type[i] = '\0';
    }

    const char* getType() const {
        return type;
    }

    double calculateVolume() const {
        return width * length * maxDepth;
    }

    double calculateSurfaceArea() const {
        return width * length;
    }

    bool isSameType(const Reservoir& other) const {
        int i = 0;
        while (type[i] != '\0' && other.type[i] != '\0') {
            if (type[i] != other.type[i]) return false;
            ++i;
        }
        return type[i] == other.type[i];
    }

    bool hasLargerSurfaceArea(const Reservoir& other) const {
        return calculateSurfaceArea() > other.calculateSurfaceArea();
    }

    Reservoir& operator=(const Reservoir& other) {
        if (this != &other) {
            setName(other.name);
            width = other.width;
            length = other.length;
            maxDepth = other.maxDepth;
            setType(other.type);
        }
        return *this;
    }

    void displayInfo() const {
        cout << "Водойма: " << name << ", Тип: " << type
            << ", Розміри: " << width << "x" << length
            << ", Глибина: " << maxDepth << ", Об'єм: "
            << calculateVolume() << ", Площа: "
            << calculateSurfaceArea() << endl;
    }
};

void addReservoir(Reservoir reservoirs[], int& size, const Reservoir& res) {
    if (size < 10) { 
        reservoirs[size++] = res;
    }
    else {
        cout << "Масив заповнений!\n";
    }
}

void removeReservoir(Reservoir reservoirs[], int& size, int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; ++i) {
            reservoirs[i] = reservoirs[i + 1];
        }
        --size;
    }
    else {
        cout << "Невірний індекс.\n";
    }
}

int main() {
    Reservoir reservoirs[10]; 
    int size = 0;

    Reservoir r1("Озеро", 100, 200, 50, "пруд");
    Reservoir r2("Море", 500, 1000, 200, "море");

    addReservoir(reservoirs, size, r1);
    addReservoir(reservoirs, size, r2);

    for (int i = 0; i < size; ++i) {
        reservoirs[i].displayInfo();
    }

    cout << "Озеро і Море одного типу? "
        << (r1.isSameType(r2) ? "Так" : "Ні") << endl;

    cout << "Море має більшу площу? "
        << (r2.hasLargerSurfaceArea(r1) ? "Так" : "Ні") << endl;

    removeReservoir(reservoirs, size, 0);

    cout << "Залишкові водойми:\n";
    for (int i = 0; i < size; ++i) {
        reservoirs[i].displayInfo();
    }

    return 0;
}
