#include "../include/dado.hh"

using namespace std;


void print_die(ostream& out, const Matrix& m, int n) {
    out << "Rolled a " << n << "!" << endl;
    for(int i = 0; i < m.size(); i++) {
        for(int j = 0; j < m[0].size(); j++) {
            out << m[i][j];
        }
        out << endl;
    }
    out << endl;

    return;
}

void select_die(int n, ostream& history, DiceInfo& d, bool& b) {
    if(n == 1) {
        d.times_1 += 1;
        if(not b) {
            print_die(history, FACE_1, n);
        }
    }
    else if(n == 2) {
        d.times_2 += 1;
        if(not b) {
            print_die(history, FACE_2, n);
        }
    }
    else if(n == 3) {
        d.times_3 += 1;
        if(not b) {
            print_die(history, FACE_3, n);
        }
    }
    else if(n == 4) {
        d.times_4 += 1;
        if(not b) {
            print_die(history, FACE_4, n);
        }
    }
    else if(n == 5) {
        d.times_5 += 1;
        if(not b) {
            print_die(history, FACE_5, n);
        }
    }
    else if(n == 6) {
        d.times_6 += 1;
        if(not b) {
            print_die(history, FACE_6, n);
        }
    }
    else {
        cerr << "Error, invalid face number" << endl;
        exit(1);
    }
}

void print_statistics(ostream& statistics, const DiceInfo& d) {
    // Calculate percentages
    double percentage_1 = (d.times_1 * 100.0) / d.total;
    double percentage_2 = (d.times_2 * 100.0) / d.total;
    double percentage_3 = (d.times_3 * 100.0) / d.total;
    double percentage_4 = (d.times_4 * 100.0) / d.total;
    double percentage_5 = (d.times_5 * 100.0) / d.total;
    double percentage_6 = (d.times_6 * 100.0) / d.total;

    vector<double> v = {percentage_1, percentage_2, percentage_3, percentage_4, percentage_5, percentage_6};

    statistics << "Roll statistics: " << endl;

    for(int i = 0; i < v.size(); i++) {
        statistics << "Face " << i+1 << ": ";
        int hundred = 100;
        int num  = v[i];

        while(num != 0) {
            statistics << "|";
            num--;
            hundred--;
        }

        while(hundred != 0) {
            statistics << ".";
            hundred--;
        }

        statistics << " " << v[i] << "%" << endl;
    }

    return;
}
