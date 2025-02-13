#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string>
#include <conio.h>
#include <time.h>
#include <mmsystem.h>

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <thread>
#include <fstream>
#include <string>
#include <map>
#include <Mmsystem.h>
#pragma comment(lib, "Winmm.lib")

#pragma comment(lib, "Winmm.lib")


#define RST "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

#include <Mmsystem.h>
#include <mciapi.h>
//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")


using namespace std;

const int CONSOLE_WIDTH = 100;
const int CONSOLE_HEIGHT = 31;
const int ground = 4;

void FixConsoleWindow();
void GotoXY(int x, int y);
void setConsoleSize();
void drawMap(int width, int height);
void cls();
void hidecursor();
void menu();
void ImpactEffect(int x, int y);
// class MovingObj
// {
// protected:
//     int mX, mY; // top left cordinate;
//     int height, width;

// public:
//     MovingObj() : mX(0), mY(0), height(0), width(0) {}
//     MovingObj(int cordX, int cordY, int hi, int wi) : mX(cordX), mY(cordY), height(hi), width(wi) {}
//     virtual void draw() = 0;
//     virtual bool impact(int cordX, int cordY) = 0;
// };

class CVEHICLE
{
protected:
    int mX, mY;
    bool toLeft;

public:
    CVEHICLE(int x, int y, bool goingLeft);
    void move();
    virtual void draw() = 0;
    int getX() { return mX; }
    int getY() { return mY; }
};

class CCAR : public CVEHICLE
{
public:
    const string shape = "C";
    CCAR(int x, int y, bool goingLeft);
    void draw();
};

class CTRUCK : public CVEHICLE
{
public:
    const string shape = "T";
    CTRUCK(int x, int y, bool goingLeft);
    void draw();
};

class CANIMAL
{
protected:
    int mX, mY;
    bool toLeft;

public:
    CANIMAL(int x, int y, bool goingLeft);
    void move();
    virtual void draw() = 0;
    int getX() { return mX; }
    int getY() { return mY; }
};

class CBIRD : public CANIMAL
{
public:
    const string shape = "B";
    CBIRD(int x, int y, int goingLeft);
    void draw();
};

class CDINOSAUR : public CANIMAL
{
public:
    const string shape = "D";
    CDINOSAUR(int x, int y, int goingLeft);
    void draw();
};

class CPEOPLE
{
private:
    int mX, mY;
    bool mState;

public:
    const string shape = "???";
    CPEOPLE();
    void revive();
    void Up();
    void Left(int speed);
    void Right(int speed);
    void Down();
    bool isImpact(const vector<CVEHICLE *> &vehicles);
    bool isImpact(const vector<CANIMAL *> &animals);
    bool isFinished();
    bool isDead();
    void draw();
    int getX() { return mX; }
    int getY() { return mY; }
};

class CGAME
{
private:
    int level;
    int lanes[5] = {0, 1, 2, 3, 4};
    vector<CTRUCK *> trucks;
    vector<CCAR *> cars;
    vector<CDINOSAUR *> dinos;
    vector<CBIRD *> birds;
    CPEOPLE human;

public:
    void shuffleLanes();
    CGAME();
    ~CGAME();
    void drawGame();
    CPEOPLE getPeople();
    vector<CVEHICLE *> getVehicle();
    vector<CANIMAL *> getAnimal();
    void resetGame(int lev);
    void exitGame(HANDLE);
    void startGame();
    void loadGame(ifstream);
    void saveGame(ofstream);
    void pauseGame(HANDLE);
    void resumeGame(HANDLE);
    void updatePosPeople(int direction);
    void updatePosVehicle();
    void updatePosAnimal();
    void deleteMovingObj();
    int getLevel() { return level; }
};


#endif