/*
 =========================================================
 
 Things to implement:
 
 1. Create graph
 2. Scale graph according to output
 
 =========================================================
 
 Eventual:
 Dealing with parentheses
 Logarithmic functions
 Trig functions
 Compute derivatives and integrals
 
 =========================================================
*/

const int MAX_TERMS = 10;

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*
 ======================================
 Class definitions and member functions
 ======================================
*/

// Term class definition and member functions

class Term {
public:
    // Constructor
    Term(double degree, double coeff);
    //Accessor
    double degree();
    double coeff();
private:
    double m_degree;
    double m_coeff;
};

Term::Term(double degree, double coeff) {
    m_degree = degree;
    m_coeff =  coeff;
}

double Term::degree() {
    return m_degree;
}

double Term::coeff() {
    return m_coeff;
}

// Function class definition and member functions

class Function {
public:
    // Constructor/destructor
    Function();
    ~Function();
    //Mutators
    void takeInput();
    void calculateValues();
    //Accessors
    Term* terms(int index);
    double* values();
    int nTerms();
    void displayFunction();
private:
    Term* m_terms[MAX_TERMS];
    double m_values[51];
    int m_userTerms;
    int m_nTerms;
};

Function::Function() {
    m_nTerms = 0;
    cout << "How many terms are in your function? ";
    cin >> m_userTerms;
    takeInput();
    calculateValues();
}

Function::~Function() {
    for (int i = 0; i < m_nTerms; ++i) {
        delete m_terms[i];
    }
}

void Function::takeInput() {
    for (int i = 0; i < m_userTerms; ++i) {
        double degree = 0;
        double coeff = 0;
        
        cout << "What is the degree of term " << i + 1 << "? ";
        cin >> degree;
        
        cout << "What is the coefficient of term " << i + 1 << "? ";
        cin >> coeff;
        
        if (coeff != 0) {
            m_terms[i] = new Term(degree, coeff);
            ++m_nTerms;
        }
    }
}

void Function::calculateValues() {
    for (int i = 0; i < 51; ++i) {
        double value = 0;
        for (int j = 0; j < m_nTerms; ++j) {
            value += (m_terms[j]->coeff() * pow(i - 25, m_terms[j]->degree()));
        }
        m_values[i] = value;
    }
}

Term* Function::terms(int index) {
    return m_terms[index];
}

double* Function::values() {
    return m_values;
}

int Function::nTerms() {
    return m_nTerms;
}

/*
 plus sign if it's not the first term
 coefficient if it's not 1
 x if it's not to the 0 power
 ^y if it's not to the 1 power
*/

void Function::displayFunction() {
    for (int i = 0; i < m_nTerms; ++i) {
        if (i != 0) {
            cout << "+ ";
        }
        if (terms(i)->coeff() == 1 && terms(i)->degree() == 0) {
            cout << "1";
        }
        if (terms(i)->coeff() != 1) {
            cout << terms(i)->coeff();
        }
        if (terms(i)->degree() != 0) {
            cout << "x";
        }
        if (terms(i)->degree() != 1 && terms(i)->degree() != 0) {
            cout << "^" << terms(i)->degree();
        }
        cout << " ";
    }
    cout << endl;
}

/*
 ====================================
 Auxiliary functions and main routine
 ====================================
*/

int main() {
    Function f;
    f.displayFunction();
}