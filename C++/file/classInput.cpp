#include <iostream>
#include <string>
#include <fstream>

class Food{
    private:
        std::string name;
        std::string country;
        short score;
    public:
        Food();
        Food(std::string newName, std::string newCountry, short newScore);
        std::string getName();
        std::string getCountry();
        short getScore();
        void setName(std::string newName);
        void setCountry(std::string newCountry);
        void setScore(short newScore);
};

using namespace std;
Food::Food(){};
Food::Food(string newName, string newCountry, short newScore)
{
    name = newName;
    country = newCountry;
    score = newScore;
}

string Food::getName()
{
    return name;
}

string Food::getCountry()
{
    return country;
}

short Food::getScore()
{
    return score;
}

void Food::setName(string newName)
{
    name = newName;
}

void Food::setCountry(string newCountry)
{
    country = newCountry;
}

void Food::setScore(short newScore)
{
    score = newScore;
}
//  ofstream& operater<< (ofstream os, const MyClass& object)
//  {
        
//     }

int main()
{
    Food pizza("pizza", "Italia",85);
    ofstream writeFile;
   
    writeFile.open("FOOD.bin", ios::in |ios::trunc|ios::binary);   
    writeFile.write((char*)&pizza,sizeof(Food));
    writeFile.close();        
    /* c형식의 객체 입력*/
    // FILE *fp = fopen("FOOD.txt", "w");
    // fwrite(&pizza, sizeof(Food),1,fp);
    // fclose(fp);
    Food banana;
    ifstream readFile;
    readFile.open("Food.bin", ios::out | ios::binary);
    readFile.read((char*)&banana, sizeof(Food));
    readFile.close();
    cout << banana.getName() << "\t" << banana.getCountry() << "\t" << banana.getScore() << endl;
}