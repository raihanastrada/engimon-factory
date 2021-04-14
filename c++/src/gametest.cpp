#include "GameInit.hpp"
// TEST WITH g++ -o test gametest.cpp Skill.cpp GameInit.cpp


int main()
{
    GameInitiator g;
    pair<Engidex, CatalogSkill> d = g.init();

    Engimon huhi(d.first, 1001);
    huhi.PrintInfo();
}