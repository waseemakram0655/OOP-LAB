#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

// Matches spacing::size (80) so rules and text share one column width
const int TERM_WIDTH = 80;

// --- Waseem's centering (unchanged) -------------------------------------------------
class spacing;
class spacing {
  string text;
  int size=80;

  public:
  spacing(string t):text(t){}

  friend ostream& operator <<(ostream& out,const spacing &a);
};
ostream& operator <<(ostream& out,const spacing &a){
if (a.text.length() >= a.size) { out << a.text; return out; }
int pad=(a.size-a.text.length())/2;
for(int i=0;i<pad;i++){out<<" ";}
out<<a.text;
return out;
}
// -----------------------------------------------------------------------------------

void print_separator();
static double nisab = 430000.0;  // Silver-based Nisab (2026 market rates).
static double goldprice = 495000.0;   // PKR per tola
static double silverprice = 9757.0;   // PKR per tola
static const double ZAKAT_RATE = 0.025;

void show() {
    cout << spacing("JazakAllah Khair for using the Zakat Calculator.") << endl;
    cout << spacing("May Allah accept your Zakat and bless you abundantly.") << endl;
}

// From Final edition.c — education banks
const char *quran_verses[] = {
    "\"And establish prayer and give Zakat.\" - Quran 2:43",
    ("\"The example of those who spend their wealth in Allah's way is like\n"
     "                   a grain that sprouts seven ears, in every ear 100 grains.\" - "
     "Quran 2:261"),
    "\"Take from their wealth a charity to cleanse and purify them.\" - Quran 9:103",
    ("\"Those who hoard gold and silver and do not spend in Allah's way,\n"
     "                   give them tidings of a painful punishment.\" - Quran 9:34")};

const char *hadith[] = {
    "\"Charity does not decrease wealth.\" - Sahih Muslim 2588",
    "\"Protect yourself from the Fire even with half a date in charity.\" - Bukhari 1417",
    "\"Every act of goodness is charity.\" - Sahih Muslim 1005"};

const char *zakat_facts[] = {
    "Zakat means 'purification' and 'growth' in Arabic.",
    "Zakat is due after wealth is held for one lunar year (Hawl).",
    "The Nisab is equivalent to 87.48g of gold or 612.36g of silver.",
    "Zakat can be given to 8 categories mentioned in Quran 9:60."};

int quran_count = sizeof(quran_verses) / sizeof(quran_verses[0]);
int hadith_count = sizeof(hadith) / sizeof(hadith[0]);
int facts_count = sizeof(zakat_facts) / sizeof(zakat_facts[0]);

// --- Abstract base & concrete assets ------------------------------------------------
class Asset {
  public:
    virtual double getZakatableValue() const = 0;
    virtual ~Asset() {}
};

class Cash : public Asset {
    double pkr;

  public:
    Cash(double amountPkr) : pkr(amountPkr) {}
    double getZakatableValue() const { return pkr; }
};

class Gold : public Asset {
    double pkr;

  public:
    Gold(double tola, double pkrPerTola) : pkr(tola * pkrPerTola) {}
    double getZakatableValue() const { return pkr; }
};

class Silver : public Asset {
    double pkr;

  public:
    Silver(double tola, double pkrPerTola) : pkr(tola * pkrPerTola) {}
    double getZakatableValue() const { return pkr; }
};

class BankSavings : public Asset {
    double pkr;

  public:
    BankSavings(double amountPkr) : pkr(amountPkr) {}
    double getZakatableValue() const { return pkr; }
};

class Stocks : public Asset {
    double pkr;

  public:
    Stocks(double valuePkr) : pkr(valuePkr) {}
    double getZakatableValue() const { return pkr; }
};

class BusinessInventory : public Asset {
    double pkr;

  public:
    BusinessInventory(double valuePkr) : pkr(valuePkr) {}
    double getZakatableValue() const { return pkr; }
};

class OtherZakatable : public Asset {
    double pkr;

  public:
    OtherZakatable(double valuePkr) : pkr(valuePkr) {}
    double getZakatableValue() const { return pkr; }
};

class Receivables : public Asset {
    double pkr;

  public:
    Receivables(double lentPkr) : pkr(lentPkr) {}
    double getZakatableValue() const { return pkr; }
};

// Logically combine zakatable numbers (for operator+ demos)
class ZakatableBlock {
    double value;

  public:
    ZakatableBlock() : value(0) {}
    double getValue() const { return value; }
    friend ZakatableBlock operator+(ZakatableBlock z, const Asset &a) {
        z.value += a.getZakatableValue();
        return z;
    }
};

// Add two different asset rows (by reference, polymorphic)
double operator+(const Asset &a, const Asset &b) {
    return a.getZakatableValue() + b.getZakatableValue();
}

// --- Wallet: array of base pointers, max 10 ----------------------------------------
class UserWallet {
    Asset *portfolio[10];
    int count;

  public:
    UserWallet() {
        for (int i = 0; i < 10; i++) {
            portfolio[i] = 0;
        }
        count = 0;
    }
    ~UserWallet() { clearAll(); }
    int getCount() const { return count; }
    Asset *getAt(int i) {
        if (i < 0 || i >= count) {
            return 0;
        }
        return portfolio[i];
    }
    bool add(Asset *p) {
        if (p == 0 || count >= 10) {
            return false;
        }
        portfolio[count] = p;
        count++;
        return true;
    }
    void clearAll() {
        for (int i = 0; i < count; i++) {
            if (portfolio[i] != 0) {
                delete portfolio[i];
                portfolio[i] = 0;
            }
        }
        count = 0;
    }
    // Polymorphic sum using + with ZakatableBlock
    double totalWithOperatorPlus() {
        ZakatableBlock block;
        for (int i = 0; i < count; i++) {
            block = block + *(portfolio[i]);
        }
        return block.getValue();
    }
};

class Liabilities {
    double loans;
    double bills;
    double others;

  public:
    Liabilities() {
        loans = 0;
        bills = 0;
        others = 0;
    }
    void setliabilities() {
        cout << spacing("Now You will be inquired about your liabilities\n\n");
        char x;
        cout << spacing("Do you have any loan to pay [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the value of loans on you in pkr") << endl;
            cin >> loans;
        } else
            loans = 0;
        cout << spacing("Do you have any bills pending on you [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the value of bills on you in pkr") << endl;
            cin >> bills;
        } else
            bills = 0;
        cout << spacing("Do you have any other liability [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the value of liabilities on you in pkr") << endl;
            cin >> others;
        } else
            others = 0;
        cout << "\n\n";
    }
    double get_liabilities_amount() { return (loans + others + bills); }
};

class Information;
void setzakat(Information &i, double p);

class Information {
    string name;
    string email;
    string phoneNumber;
    int age;
    double zakatpayable;

    friend void setzakat(Information &i, double p);

  public:
    Information() { zakatpayable = 0; }
    Information(string n, string e, string p, int ag, double x)
        : name(n), email(e), phoneNumber(p), age(ag), zakatpayable(x) {}
    string getname() { return name; }
    string getemail() { return email; }
    string getphone() { return phoneNumber; }
    int getage() { return age; }
    double getzakat() { return zakatpayable; }
    void setInformation() {
        cin.ignore(10000, '\n');
        cout << spacing("Enter name") << endl;
        getline(cin, name);
        cout << spacing("Enter email") << endl;
        cin >> email;
        cout << spacing("Enter phone number") << endl;
        cin >> phoneNumber;
        cout << spacing("Enter age") << endl;
        cin >> age;
    }

    // Build wallet in main loop style: prompt, new, add, sum with + / polymorphism
    void calculatezakat() {
        Liabilities l;
        l.setliabilities();

        UserWallet wallet;
        char x;
        double t;

        cout << spacing("You will be inquired about your assets:\n\n");
        cout << spacing("Kindly enter the assets on which one year has been passed\n\n");

        cout << spacing("Do you have Gold [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the amount of gold you have in tola") << endl;
            cin >> t;
            Gold *g = new Gold(t, goldprice);
            wallet.add(g);
        }
        cout << spacing("Do you have silver [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the amount of silver you have in tola") << endl;
            cin >> t;
            Silver *s = new Silver(t, silverprice);
            wallet.add(s);
        }
        cout << spacing("Do you have cash [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the amount of cash you have in pkr") << endl;
            cin >> t;
            wallet.add(new Cash(t));
        }
        cout << spacing("Do you have bank savings [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter bank savings in pkr") << endl;
            cin >> t;
            wallet.add(new BankSavings(t));
        }
        cout << spacing("Do you have business inventory [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the value of business inventory you have in pkr") << endl;
            cin >> t;
            BusinessInventory *bi = new BusinessInventory(t);
            wallet.add(bi);
        }
        cout << spacing("Do you have shares of stocks  [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the value of stocks you have in pkr") << endl;
            cin >> t;
            wallet.add(new Stocks(t));
        }
        cout << spacing("Do you have any other business good zakatable [y/n]") << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the value of that good you have in pkr") << endl;
            cin >> t;
            wallet.add(new OtherZakatable(t));
        }
        cout << spacing("Do you have any other money lent to others which they will pay back "
                        "[y/n]")
             << endl;
        cin >> x;
        if (x == 'y' || x == 'Y') {
            cout << spacing("Enter the value of that money you have in pkr") << endl;
            cin >> t;
            Receivables *r = new Receivables(t);
            wallet.add(r);
        }
        cout << "\n\n";

        // Total zakatable: polymorphic + overloaded ZakatableBlock + Asset
        double grossAssets = wallet.totalWithOperatorPlus();
        if (wallet.getCount() >= 2) {
            double firstTwo = operator+(*(wallet.getAt(0)), *(wallet.getAt(1)));
            char cc[100];
            snprintf(cc, sizeof(cc), "Cross-check (first two rows, PKR): %.2f", firstTwo);
            cout << spacing(cc) << endl;
        }

        double liab = l.get_liabilities_amount();
        double netWorth = grossAssets - liab;

        char row[120];
        snprintf(row, sizeof(row), "Gross assets (PKR): %.2f", grossAssets);
        cout << spacing(row) << endl;
        snprintf(row, sizeof(row), "Total liabilities (PKR): %.2f", liab);
        cout << spacing(row) << endl;
        snprintf(row, sizeof(row), "Net zakatable (PKR): %.2f", netWorth);
        cout << spacing(row) << endl;
        snprintf(row, sizeof(row), "Nisab threshold (PKR): %.2f", nisab);
        cout << spacing(row) << endl;
        print_separator();

        if (netWorth >= nisab) {
            zakatpayable = netWorth * ZAKAT_RATE;
            snprintf(row, sizeof(row), "Zakat due at 2.5%%: PKR %.2f", zakatpayable);
            cout << spacing(row) << endl;
        } else {
            zakatpayable = 0;
            cout << spacing("Net worth is below Nisab. Zakat is not due on this profile.") << endl;
        }

        wallet.clearAll();
    }

    void showRandomEducation() {
        int choice = rand() % 3;
        print_separator();
        cout << "\n";
        if (choice == 0) {
            int idx = rand() % facts_count;
            cout << spacing(zakat_facts[idx]) << endl;
        } else if (choice == 1) {
            int idx = rand() % hadith_count;
            cout << spacing(hadith[idx]) << endl;
        } else {
            int idx = rand() % quran_count;
            cout << spacing(quran_verses[idx]) << endl;
        }
        print_separator();
        cout << "\n";
    }
};

void setzakat(Information &i, double p) { i.zakatpayable -= p; }

class chatbot {
  public:
    void intro() {
        print_separator();
        cout << spacing("Zakat Calculator Chatbot") << endl;
        print_separator();
        cout << spacing("Welcome. You will be asked a short series of questions to keep the calculation authentic.")
             << endl;
        print_separator();
        cout << spacing("In the name of Allah, the Most Gracious, the Most Merciful") << endl;
        print_separator();
    }
    void menu() {
        cout << spacing("1. Calculate Zakat") << endl;
        cout << spacing("2. View History") << endl;
        cout << spacing("3. Pay Zakat") << endl;
        cout << spacing("4. Zakat FAQ") << endl;
        cout << spacing("5. Charity Recommendations") << endl;
        cout << spacing("6. Exit") << endl;
        cout << spacing("\n\nEnter SNo") << endl;
    }
};

class History {
  public:
    void savepayment(string name, string email, double p, double zakat) {
        ofstream out;
        out.open("history.txt", ios::app);
        if (out.is_open()) {
            out << "Payment | User: " << name << " | Email: " << email << " | Paid: " << p
                << " | Remaining: " << zakat << "\n";
            out.close();
        }
    }
    // Persists like Final edition.c: append each run, survives restarts (plain text, ios::app)
    void saveProfile(string name, string email, string phone, int age, double zakatDue) {
        ofstream out;
        out.open("history.txt", ios::app);
        if (out.is_open()) {
            time_t t = time(0);
            char *d = ctime(&t);
            if (d != 0) {
                int L = (int)strlen(d);
                if (L > 0 && d[L - 1] == '\n') {
                    d[L - 1] = '\0';
                }
            }
            out << "Date: " << (d ? d : "unknown");
            out << "  Name: " << name;
            out << "  Total Zakat Due (PKR): " << zakatDue;
            out << "  Email: " << email << "  Phone: " << phone << "  Age: " << age << "\n";
            out.close();
        }
    }
    void viewhistory() {
        ifstream in;
        in.open("history.txt");
        print_separator();
        cout << spacing("Previous Zakat records") << endl;
        print_separator();
        string line;
        if (in.is_open()) {
            while (getline(in, line)) {
                cout << line << endl;
            }
            in.close();
        } else
            cout << spacing("No history found") << endl;
        print_separator();
    }
};

class support {
  public:
    virtual void show() = 0;
    virtual ~support() {}
};

class Suggestions : public support {
  public:
    void show() {
        print_separator();
        cout << spacing("Charity recommendations") << endl;
        print_separator();
        cout << spacing("1. Edhi Foundation (Welfare)") << endl;
        cout << spacing("2. Indus Hospital (Healthcare)") << endl;
        cout << spacing("3. Saylani Welfare Trust (Food / Education)") << endl;
        cout << spacing("4. IMCHF") << endl;
        print_separator();
    }
};

class FAQ : public support {
  public:
    void show() {
        print_separator();
        cout << spacing("Zakat FAQ") << endl;
        print_separator();
        printf("\n\n");
        cout << spacing("Q: What is Zakat?") << endl;
        cout << spacing("A: Zakat is obligatory charity - 2.5%% of wealth held for one year.");
        cout << "\n\n";
        cout << spacing("Q: Who must pay Zakat?\n");
        cout << spacing("A: Muslims whose wealth exceeds Nisab for one lunar year.") << endl;
        cout << "\n\n";
        cout << spacing("Q: What is Nisab?");
        cout << "\n";
        cout << spacing("A: The minimum threshold - equivalent to 87.48g gold or 612.36g silver.");
        cout << "\n\n";
        cout << spacing("Q: What wealth is Zakatable?");
        cout << "\n";
        cout << spacing("A: Cash, gold, silver, savings, business assets, money owed to you.");
        cout << "\n\n";
        cout << spacing("Q: What about real estate/property?\n");
        cout << spacing("A: Personal residence is exempt. Rental/investment property is "
                        "Zakatable.\n\n");
        cout << spacing("Q: What about vehicles?\n");
        cout << spacing("A: Personal use vehicles are exempt. Commercial vehicles are "
                        "Zakatable.\n\n");
        cout << spacing("Q: Can I deduct debts?\n");
        cout << spacing("A: Yes, immediate debts/bills reduce your Zakatable wealth.\n\n");
        cout << spacing("Q: Who receives Zakat?\n");
        cout << spacing("A: 8 categories in Quran 9:60 - poor, needy, collectors, new Muslims,");
        cout << spacing("freeing captives, debtors, in Allah's cause, travelers in need.\n\n");
        cout << spacing("Q: Special cases not covered here?\n");
        cout << spacing("A: Please consult a qualified Islamic scholar for guidance.\n\n");
        print_separator();
    }
};

void print_separator() {
    for (int i = 0; i < TERM_WIDTH; i++) {
        cout << "=";
    }
    cout << endl;
}

int main() {
    chatbot clientschatbot;
    clientschatbot.intro();
    srand((unsigned int)time(0));
    Information client;
    client.setInformation();
    History h;
    support *f;
    support *s;
    f = new FAQ;
    s = new Suggestions;
    int n = 1;
    while (n != 6) {
        clientschatbot.menu();
        cin >> n;
        if(cin.fail()){ cin.clear(); cin.ignore(10000, '\n'); n = 0; }
        switch (n) {
        case 1:
            client.calculatezakat();
            h.saveProfile(client.getname(), client.getemail(), client.getphone(), client.getage(),
                          client.getzakat());
            {
                char sum[100];
                snprintf(sum, sizeof(sum), "Recorded Zakat amount (PKR): %.2f", client.getzakat());
                cout << spacing(sum) << endl;
            }
            client.showRandomEducation();
            break;
        case 2:
            h.viewhistory();
            client.showRandomEducation();
            break;
        case 3: {
            double p;
            if (client.getzakat() > 0) {
                cout << spacing("Enter the amount you want to pay from your zakat") << endl;
                cin >> p;
                if (p <= client.getzakat()) {
                    setzakat(client, p);
                    h.savepayment(client.getname(), client.getemail(), p, client.getzakat());
                } else {
                    cout << spacing("Your amount is greater then the zakat due i.e. ")
                         << client.getzakat() << endl;
                    cout << spacing("Try Again") << endl;
                }
            } else
                cout << spacing("You are ineligible for zakat") << endl;
            client.showRandomEducation();
        } break;
        case 4:
            f->show();
            client.showRandomEducation();
            break;
        case 5:
            s->show();
            client.showRandomEducation();
            break;
        case 6:
            show();
            client.showRandomEducation();
            break;
        }
    }
    delete s;
    delete f;
    return 0;
}