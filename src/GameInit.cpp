#include "GameInit.hpp"
#include "Engimon.hpp"
#include "Skill.h"
#include "Elements.hpp"

map<pair<Element, Element>, float> Element::advantageIndex;
long long int Engimon::engimon_count = 0;

#define LINE cout << "-----------------------------" << endl;

void GameInitiator::addNewEntry(int id, string name, string skillname, Element a, Element b)
{
    Skill skill(skillname, 1, vector<Element>() = { a, b });
    e.addSpecies(name, id, skill, a, b);
}

void GameInitiator::addNewEntry(int id, string name, string skillname, Element a)
{
    Skill skill(skillname, 1, vector<Element>() = { a });
    e.addSpecies(name, id, skill, a);
}

void GameInitiator::addNewEntry(int id, string name, string skillname)
{
    vector<Element> elements;
    elements.push_back(el[id/1000]);
    int i = (id / 100) % 10;
    if (i != 0)
    {
        elements.push_back(el[i]);
    }    

    Skill skill(skillname, 1, elements);
    e.addSpecies(name, id, skill, elements);
}

Engidex GameInitiator::init()
{
    // Initialize Elements
    /*
        Element element("elementName");
        Element element2("element2Name");
        setAdvantage(element, element2);
    */

    Element fire("Fire");
    Element water("Water");
    Element electric("Electric");
    Element ground("Ground");
    Element ice("Ice");

    setAdvantage(fire, water, 0.0);
    setAdvantage(fire, ground, 0.5);
    setAdvantage(fire, ice, 2.0);
    
    setAdvantage(water, fire, 2.0);
    setAdvantage(water, electric, 0.0);

    setAdvantage(electric, water, 2.0);
    setAdvantage(electric, ground, 1.5);
    setAdvantage(electric, ice, 1.5);

    setAdvantage(ground, fire, 1.5);
    setAdvantage(ground, electric, 2.0);
    setAdvantage(ground, ice, 0.0);

    setAdvantage(ice, fire, 0);
    setAdvantage(ice, electric, 0.5);
    setAdvantage(ice, ground, 2);

    // Initialize Pokemon Species
    /*
    FORMAT:
        Skill skill(basepower, masterlevel, vector<Element> compatibleElement);
        Engidex::addSpecies(name, id, skill, elementName) (you can use string for el name)
    */

    /*
    ENGIDEX code format
    <first-element 1..5> <second-element 0..5> <index 1..9>

    example:
    Third engimon type with elements Electric and Fire has ENGIDEX code:
        1203

    Skill shock("100Volt", 1, 1, vector<Element>() = { electric });
    engidex.addSpecies("Pikamee", 3001, shock, electric);
    
    ELEMENT INDEXES
        Electric    1
        Fire        2
        Ground      3
        Ice         4
        Water       5
    */

    vector<Element> elements;
    elements.push_back(electric);
    elements.push_back(fire);
    elements.push_back(ground);
    elements.push_back(ice);
    elements.push_back(water);
    setElements(elements);

    Engidex engidex;
    setEngidex(engidex);

    return e;
}

void GameInitiator::generatePokemon()
{
    // Skill shock("Shock", 1, vector<Element>() = { electric });
    // engidex.addSpecies("Pikamee", 1001, shock, electric);
    
    // Skill fireball("Fireball", 1, vector<Element>() = { fire });
    // engidex.addSpecies("Takanashi Kiara", 2001, shock, fire);

    // Skill groundpound("Ground Pound", 1, vector<Element>() = { ground });
    // engidex.addSpecies("Amelia Watson", 3001, shock, ground);

    // Skill icicle("Icicle", 1, vector<Element>() = { ice });
    // engidex.addSpecies("Amane Kanata", 4001, shock, ice);

    // Skill splash("Splash", 1, vector<Element>() = { water });
    // engidex.addSpecies("Gawr Gura", 5001, shock, water);

    // Skill magnetize("Magnetize", 1, vector<Element>() = { fire, electric });
    // engidex.addSpecies("Mori Calliope", 1301, shock, fire, electric);

    // Skill overgrowth("Overgrowth", 1, vector<Element>() = { water, ground });
    // engidex.addSpecies("Oozora Subaru", 5301, shock, water, ground);

    // Skill flashfreeze("Flash Freeze", 1, vector<Element>() = { water, ice });
    // engidex.addSpecies("Amatsuka Uto", 5401, shock, water, ice);

    addNewEntry(1001, "Pikamee", "Shock");
    addNewEntry(1002, "Tokino Sora", "Awe");
    addNewEntry(1003, "Roboco", "Charge");
    addNewEntry(1004, "Sakura Miko", "F.A.Q");
    addNewEntry(1005, "Hoshimachi Suisei", "Blessing of the TETRIS Gods");
    addNewEntry(1006, "AZKi", "Shocking Serenade");
    addNewEntry(1007, "Yozora Mel", "Lightning Cure");
    addNewEntry(1008, "Shirakami Fubuki", "Doko Mitendayo");
    addNewEntry(1009, "Natsuiro Matsuri", "Matsuri Special");

    addNewEntry(2001, "Takanasahi Kiara", "Fireball");
    addNewEntry(2002, "Aki Rosenthal", "Rosenthal");
    addNewEntry(2003, "Akai Haato", "Flaming Appetite");
    addNewEntry(2004, "Hitomi Chris", "Vanish into Flames");
    addNewEntry(2005, "Muraski Shion", "Shion Strike");
    addNewEntry(2006, "Nakiri Ayame", "Purify");
    addNewEntry(2007, "Yuzuki Choco", "Chocolate Medicine");
    addNewEntry(2008, "Ookami Mio", "Summon Children of Flames");
    addNewEntry(2009, "Nekomata Okayu", "Mogu Mogu");

    addNewEntry(3001, "Amelia Watson", "Ground Pound");
    addNewEntry(3001, "Inugami Korone", "Yubi");
    addNewEntry(3001, "Usada Pekora", "Commit War Crimes");
    addNewEntry(3001, "Uruha Rushia", "Desk Slam");
    addNewEntry(3001, "Shiranui Flare", "Arrow");
    addNewEntry(3001, "Noel", "Bonk");
    addNewEntry(3001, "Houshou Marine", "Horn");
    addNewEntry(3001, "Kiryu Coco", "Tail Whip");
    addNewEntry(3001, "Tsunomaki Watame", "Ram");

    addNewEntry(4001, "Amane Kanata", "Icicle");
    addNewEntry(4001, "Tokoyami Towa", "Devil's Snare");
    addNewEntry(4001, "Himemori Luna", "Summon Ice Knight");
    addNewEntry(4001, "Yukihana Lamy", "Ramy");
    addNewEntry(4001, "Momosuzu Nene", "Summon NAVY Seal Team Six");
    addNewEntry(4001, "Shishiro Botan", "Snipe");
    addNewEntry(4001, "Omaru Polka", "Snow Circus");
    addNewEntry(4001, "Mano Aloe", "Ice Slumber");
    addNewEntry(4001, "Pavolie Reine", "Ice Feather");

    addNewEntry(5001, "Gawr Gura", "Splash");
    addNewEntry(5001, "Spade Echo", "Wave");
    addNewEntry(5001, "Doris", "Dive");
    addNewEntry(5001, "Rosalyn", "Vortex");
    addNewEntry(5001, "Artia", "Funnel");
    addNewEntry(5001, "Hanasaki Miyabi", "Tsunami");
    addNewEntry(5001, "Kanade Izuru", "Spit");
    addNewEntry(5001, "Arurandeisu", "Drink");
    addNewEntry(5001, "Rikka", "Wet");


    addNewEntry(1301, "More Calliope", "Magnetize");
    addNewEntry(1301, "Moona Hoshinova", "Gravitate");
    addNewEntry(1301, "Airani Iofifteen", "Paint");
    addNewEntry(1301, "Kureiji Ollie", "Resurrect");
    addNewEntry(1301, "Anya Melfissa", "Blade Slash");
    addNewEntry(1301, "Ninomae Ina'nis", "Call Upon The Ancient One");
    addNewEntry(1301, "Yogiri", "Fire and Electric Attack 1");
    addNewEntry(1301, "Civia", "Summon '93 Honda Civic");

    addNewEntry(5301, "Oozora Subaru", "Shuba");
    addNewEntry(5301, "Minato Aqua", "Onionize");
    addNewEntry(5301, "Ayunda Risu", "N U T");
    addNewEntry(5301, "Kagami Kira", "Die");
    addNewEntry(5301, "Yakushiji Suzaku", "Call Dad");
    addNewEntry(5301, "Astel Leda", "Leda Attack");
    addNewEntry(5301, "Kishido Temma", "Temma Attack");
    addNewEntry(5301, "Yukoku Roberu", "Win");

    addNewEntry(5401, "Amatsuka Uto", "Angle Supreme Freeze");
    addNewEntry(5401, "Kageyama Shien", "Shien Freeze");
    addNewEntry(5401, "Aragami Oga", "Oga Freeze");
    addNewEntry(5401, "Tsukishita Kaoru", "Kaoru Freeze");
    addNewEntry(5401, "Yagoo", "Open Gates to Heaven");
    addNewEntry(5401, "AChan", "Sleep");
    addNewEntry(5401, "Daidou Shinove", "Roll Dice");
    addNewEntry(5401, "EnMa", "Slaughter");
    addNewEntry(5401, "JenMa", "Sleep");

}

