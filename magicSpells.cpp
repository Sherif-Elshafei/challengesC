#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
  
  Fireball* pSpell1 = dynamic_cast<Fireball*>(spell);
  if (pSpell1 != nullptr){
    pSpell1->revealFirepower();
  }

  Frostbite* pSpell2 = dynamic_cast<Frostbite*>(spell);
  if (pSpell2 != nullptr){
    pSpell2->revealFrostpower();
  }

  Thunderstorm* pSpell3 = dynamic_cast<Thunderstorm*>(spell);
  if (pSpell3 != nullptr){
    pSpell3->revealThunderpower();
  }

  Waterbolt* pSpell4 = dynamic_cast<Waterbolt*>(spell);
  if (pSpell4 != nullptr){
    pSpell4->revealWaterpower();
  }

  Spell* pSpell5 = dynamic_cast<Spell*>(spell);
  string s5 = SpellJournal::read();
  string s6 = spell->revealScrollName();
  if ((pSpell5 != nullptr) && (s6 != "")){
    int c = 0, j = 0;
    for (int i = 0; i < s5.length(); i++) {
        if (s6.find(s5[i]) >= 0 and j == s5.find(s5[i]))
            c += 1;
        j += 1;
    }
    cout<<c-1<<endl;
  }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}