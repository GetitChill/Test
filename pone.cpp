#include <iostream>
#include <cassert>
#include <random>

//TODO make a makefile for this.
//TODO Set up github, and make a few commits for this project
//TODO Download up CMAKE
//TODO Set up Catch2
//TODO make a text based game to practice text, github, and testing
//TODO setup an autosave feature.



//We're going to have a player that chooses
//So we're going to have enemy locations, that are randomly generated


//Can enemy be a part of player? Probably not, cause player has a constructor.



class player
{
public:
    player(int h, bool friendly_key) : health(h), friendly(friendly_key)
    {
        assert(friendly_key != 0 || friendly_key != 1 );
    }

    //TODO test this overridden thingy;
    player() = default;


    int getHealth() const
    {
       assert(health >= 0);
       return health;
    }

    int getFriendly() const
    {
       return friendly;
    }

    //this is a setter for the friendly value in player.
    void set_friendly(player& p)
    {
        p.friendly = 0;
    }
    void set_random()
    {
        //So we need a generator
        std::mt19937 r;
        std::random_device rng;





        //A seed
        //A distribution (preferrably float)
        //x = rand, y = rand


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
        //We also need to assign random x's and y's to our enemies, and needs to be between the width and height of our stuff
        for (unsigned int i = 0; i <= enemy_size; i++)
        {
            enemies[i].set_friendly(enemies[i]);
        }
    }

    float width = 10;
    float height = 20;

    static constexpr int enemy_size = 10;

    player getEnemy(const int i) const
    {
        return enemies[i];
    }

private:
    player enemies[enemy_size];
};


int main()
{
    int x[10];
    x[0] = 8927;


    board b;

    for(unsigned int i = 0; i < b.enemy_size; i++)
    {
        b.getEnemy(i);
        std:: cout << b.getEnemy(i).getFriendly() << " ";
    }


    //Any non 0 will be converted to a 1.
    player p(100, -1);


    //std::cout << p.getHealth() << "         " << p.getFriendly();
    //std::cout << x[0] <<"   " <<  x[1];
    return 0;
}
