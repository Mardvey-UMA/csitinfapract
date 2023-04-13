#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <fstream>
using namespace std;

ofstream fout;

class Goods{
private:
    string name, type = "Good", cenz;
    double cost;
public:
    string getType(){
        return type;
    }
    string getName(){
        return name;
    }
    string getCenz(){
        return cenz;
    }
    double getCost(){
        return cost;
    }
    bool setName(string name){
        if (name != ""){
            this -> name = name;
            return true;
        }
        return false;
    }
    bool setCost(double cost){
        if (cost > 0){
            this -> cost = cost;
            return true;
        }
        return false;
    }
    bool setCenz(string cenz){
        if (cenz != ""){
            this -> cenz = cenz;
            return true;
        }
        return false;
    }
    bool setType(string type){
        if (type != ""){
            this -> type = type;
            return true;
        }
        return false;
    }
    bool isType(string type){
        return (this -> type == type);
    }
    void getInfo(){
        fout << "Name: " << name << " Cost: " << cost;
        fout << " Type: " << type << " Age Cenz: " << cenz << endl;
    }
};

class Toy : public Goods{
private:
    string manufactor, material;
public:
    Toy (string name, double cost, string cenz, string manufactor, string material){
        setName(name);
        setCost(cost);
        setCenz(cenz);
        setType("Toy");
        setMat(material);
        setManufact(manufactor);
    }
    bool setMat(string material){
        if (material != ""){
            this -> material = material;
            return true;
        }
        return false;
    }
    bool setManufact(string manufactor){
        if (manufactor != ""){
            this -> manufactor = manufactor;
            return true;
        }
        return false;
    }
    string getManufact(){
        return manufactor;
    }
    string getMat(){
        return material;
    }
    void getInfo(){
        fout << "Name: " << getName() << ", Cost: " << getCost();
        fout << ", Type: " << getType() << ", Age_Cenz: " << getCenz() << ", Factory: " << getManufact() << ", Material: " << getMat() << endl;
    }
};

class Book : public Goods{
private:
    string author, izdatel;
public:
    Book (string name, double cost, string cenz, string author, string izdatel){
        setName(name);
        setCost(cost);
        setCenz(cenz);
        setType("Book");
        setAuthor(author);
        setIzdatel(izdatel);
    }
    string getAuthor(){
        return author;
    }
    string getIzdatel(){
        return izdatel;
    }
    bool setIzdatel(string izdatel){
        if (izdatel != ""){
            this -> izdatel = izdatel;
            return true;
        }
        return false;
    }
    bool setAuthor(string author){
        if (author != ""){
            this -> author = author;
            return true;
        }
        return false;
    }
    void getInfo(){
        fout << "Name: " << getName() << ", Cost: " << getCost();
        fout << ", Type: " << getType() << ", Age_Cenz: " << getCenz() << ", Author: " << getAuthor() << ", Izdatel: " << getIzdatel() << endl;
    }
};

class SportsEquipment : public Goods{
private:
    string manufactor;
public:
    SportsEquipment (string name, double cost, string cenz, string manufactor){
        setName(name);
        setCost(cost);
        setCenz(cenz);
        setType("SportsEquipment");
        setManufact(manufactor);
    }
    bool setManufact(string manufactor){
        if (manufactor != ""){
            this -> manufactor = manufactor;
            return true;
        }
        return false;
    }
    string getManufact(){
        return manufactor;
    }
    void getInfo(){
        fout << "Name: " << getName() << ", Cost: " << getCost();
        fout << ", Type: " << getType() << ", Age_Cenz: " << getCenz() << ", Factory: " << getManufact() << endl;
    }

};
void find_goods(Goods* g, string type, int n){
    fout << "FIND RESULTS\n";
    for (int i = 0; i < n; i++){
        if (g[i].isType(type))
            g[i].getInfo();
    }
    //fout.open("output.txt");
}
int main(){
fout.open("output.txt");
int n = 21;
Goods* data_base = new Goods[n];
data_base[0] = Toy("Lego City Police Station", 59.99, "6-12", "Lego", "Plastic");
data_base[1] = Toy("Barbie Dreamhouse", 199.99, "3+", "Mattel", "Plastic");
data_base[2] = Toy("Nerf N-Strike Elite Disruptor", 12.99, "8+", "Hasbro", "Plastic");
data_base[3] = Toy("Hot Wheels Track Builder System", 29.99, "4-10", "Mattel", "Plastic");
data_base[4] = Toy("Funko Pop! Marvel: Avengers Endgame - Iron Man", 9.99, "3+", "Funko", "Vinyl");
data_base[5] = Toy("Hatchimals CollEGGtibles", 9.99, "5+", "Spin Master", "Plastic");
data_base[6] = Toy("Play-Doh Kitchen Creations Ultimate Swirl Ice Cream Maker", 24.99, "3+", "Hasbro", "Plastic");
data_base[7] = Book("The Hunger Games", 10.99, "13+", "Suzanne Collins", "Paperback");
data_base[8] = Book("Harry Potter and the Philosopher's Stone", 8.99, "9+", "J.K. Rowling", "Hardcover");
data_base[9] = Book("To Kill a Mockingbird", 9.99, "14+", "Harper Lee", "Paperback");
data_base[10] = Book("1984", 11.99, "16+", "George Orwell", "Paperback");
data_base[11] = Book("The Catcher in the Rye", 8.99, "16+", "J.D. Salinger", "Paperback");
data_base[12] = Book("The Great Gatsby", 9.99, "14+", "F. Scott Fitzgerald", "Paperback");
data_base[13] = Book("Pride and Prejudice", 7.99, "12+", "Jane Austen", "Paperback");
data_base[14] = SportsEquipment("Wilson NFL Super Grip Football", 14.99, "6+", "Wilson");
data_base[15] = SportsEquipment("Spalding NBA Street Basketball", 19.99, "8+", "Spalding");
data_base[16] = SportsEquipment("Callaway Men's Strata Complete Golf Set", 249.99, "18+", "Callaway");
data_base[17] = SportsEquipment("EastPoint Sports Table Tennis Table", 299.99, "8+", "EastPoint Sports");
data_base[18] = SportsEquipment("Razor A Kick Scooter", 29.99, "5+", "Razor");
data_base[19] = SportsEquipment("K2 Skate Men's Kinetic 80 Inline Skates", 99.99, "18+", "K2 Skate");
data_base[20] = SportsEquipment("Wilson Pro Staff Precision XL 110 Tennis Racquet", 69.99, "12+", "Wilson");

for (int i = 0; i < n; i++){
    data_base[i].getInfo();
}
fout.open("find_res.txt");
string t = "Toy";
find_goods(data_base, t, n);
}
