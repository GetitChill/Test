#include <iostream>
#include <cassert>
#include <random>
#include <fstream>
#include <string>

//TODO Get discord
//TODO Try to understand the setup of the random generator and seed (ie the constructor stuff and all of that.)
//TODO make a makefile for this.
//TODO Set up Catch2
//TODO Add a copyright thingy
class player
{
public:
    player(int h, bool friendly_key) : health(h), friendly(friendly_key)
    {
        assert(friendly_key != 0 || friendly_key != 1 );
    }

    player() = default;

    void initPlayer()
    {
        //TODO Refactor this so that w and h aren't hard coded
        const int w = 10;
        const int h = 20;
        std::random_device r;
        std::mt19937 rng(r());

        std::uniform_real_distribution<float> wDist(0,w);
        std::uniform_real_distribution<float> hDist(0,h);

        x = wDist(rng);
        y = hDist(rng);

    }
    int getHealth() const
    {
       assert(health >= 0);
       return health;
    }

    int getFriendly() const
    {
       return friendly;
    }


    int getX() const
    {
        return x;
    }


    int getY() const
    {
        return y;
    }

    //this is a setter for the friendly value in player.
    void set_friendly(player& p)
    {
        p.friendly = 0;
    }

private:
    int health;

    float x;
    float y;

    bool friendly;
};

struct board
{
public:
    board()
    {
        for (unsigned int i = 0; i <= enemy_size; i++)
        {
            enemies[i].set_friendly(enemies[i]);
            enemies[i].initPlayer();
        }
    }

    float width = 10;
    float height = 20;

    static constexpr int enemy_size = 10;

    player getEnemy(const int i) const
    {
        return enemies[i];
    }

    int generate_random_int_Monster()
    {
        //TODO prevent this distribution from being hardcoded
        std::random_device r;
        std::mt19937 rng(r());
        std::uniform_int_distribution<int> xDist(0, width * height);
        return xDist(rng);
    }
private:
    //TODO try to implement your own dynamic array, so that we can create an array using the first random number generated
    player enemies[enemy_size];
};

//This is for generating a random number of enemies to spawn in. We'll store this value in a file.'




//I want to simplify how to manipulate files.
    //What do I want to do with this class? I want to just be able to do something like file a; then do something like a + "ahead", then add something to do with a line number.
    //I don't know how having board will mess this up.'
struct file
{
public:
    //TODO write a test for checking that this file is opening.
    file(const std::string intermediate_path, board b) : path(intermediate_path)
    {
        generate_file(b);
        //assert(!primary.is_open());
    }

    std::fstream primary;
    std::string path;


    void generate_file(board b)
    {
        primary.open(path);
        primary << "Random Number - class version fuckery of the highest degress\n" << b.generate_random_int_Monster();
        primary << "\n";
        primary.close();
    }

private:
};
int main()
{
    //TODO maybe look into RAI (I don't really know what that is tho :(
    board b;

    file p("input.txt", b);





    return 0;
}
