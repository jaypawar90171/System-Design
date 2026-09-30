#include <bits/stdc++.h>
using namespace std;

// Strategy Interface for Walk
class WalkableRobot
{
    public:
        virtual void walk() = 0;
        virtual ~WalkableRobot() {};
};

// Concreate Strategy for walk
class NormalWalk: public WalkableRobot
{   
    public:
        void walk() override
        {
            cout << "Walking normally" << endl;
        }
};

class NoWalk: public WalkableRobot
{   
    public:
        void walk() override
        {
            cout << "No Walking" << endl;
        }
};

// Strategy Interface for Fly
class FlyableRobot
{
    public:
        virtual void fly() = 0;
        virtual ~FlyableRobot() {};
};

// Concreate Strategy for Fly
class NormalFly: public FlyableRobot
{   
    public:
        void fly() override
        {
            cout << "Fly normally" << endl;
        }
};

class NoFly: public FlyableRobot
{   
    public:
        void fly() override
        {
            cout << "No Fly" << endl;
        }
};

// Strategy Interface for Talk
class TalkableRobot
{
    public:
        virtual void talk() = 0;
        virtual ~TalkableRobot() {};
};

// Concreate Strategy for Talk
class NormalTalk: public TalkableRobot
{   
    public:
        void talk() override
        {
            cout << "Talk normally" << endl;
        }
};

class NoTalk: public TalkableRobot
{   
    public:
        void talk() override
        {
            cout << "No Talk" << endl;
        }
};



// Robot base classs
class Robot
{
    protected:
        WalkableRobot* walkBehavior;
        TalkableRobot* talkaBehavior;
        FlyableRobot* flyBehavior;

    public:
        Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        {
            this->walkBehavior = w;
            this->talkaBehavior = t;
            this->flyBehavior = f;
        }   

        void walk()
        {
            walkBehavior->walk();
        }

        void talk()
        {
            talkaBehavior->talk();
        }

        void fly()
        {
            flyBehavior->fly();
        }

        // Abstract method for subclass
        virtual void projection() = 0;
};

// Concreate Robot types
class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

// --- Main Function ---
int main() {
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    cout << "--------------------" << endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}