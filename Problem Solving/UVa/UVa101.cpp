#include<iostream>
#include<vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> generateVector(int size) {
    vector<vector<int>> parentV;
    for (int i = 0; i < size; i++) {
        vector<int> childV;
        childV.push_back(i);
        parentV.push_back(childV);
    }

    return parentV;
}

// Gets the location of a block and assigns the co-ordinates to an address of an array
void getLocation(int blockNumber, const vector<vector<int>> *blocks, int *container) {
    for (int i = 0; i < blocks->size(); i++) {
        for (int j = 0; j < blocks->at(i).size(); j++) {
            if (blocks->at(i).at(j) == blockNumber) {
                container[0] = i;
                container[1] = j;
                return;
            }
        }
    }
}

// Returns blocks on top of another block to their initial position
void returnToInitialPosition(vector<vector<int>> *parent, vector<int> *onTopElements, int *location, int block,
                             bool onto = false) {
    for (int element : *onTopElements) {
        vector<int> v = {element};
        parent->push_back(v);
    }

    // Refresh the location
    getLocation(block, parent, location);
    vector<int> *child = &parent->at(location[0]);

    if (!onto) {
        // Remove 'a' and the elements on top of 'a'
        if (location[1] != 0) {
            child->erase(child->begin() + location[1], child->end());
        } else {
            parent->erase(parent->begin() + location[0]);
        }
    } else {
        child->erase(child->begin() + location[1] + 1, child->end());
    }
}

void pile(vector<vector<int>> *blocks, int *aLocation, int *bLocation) {
    vector<int> toBePiled = blocks->at(aLocation[0]);

    // Only selecting 'a' and elements on top of 'a' from the stack and pushing them on top of the stack containing 'b'
    for (int i = aLocation[1]; i < toBePiled.size(); i++) {
        blocks->at(bLocation[0]).push_back(toBePiled.at(i));
    }

    // now remove 'a' and elements on top of 'a'
    if (aLocation[1] != 0) {
        blocks->at(aLocation[0]).erase(blocks->at(aLocation[0]).begin() + aLocation[1], blocks->at(aLocation[0]).end());
    } else {
        blocks->erase(blocks->begin() + aLocation[0]);
    }
}

void moveOnto(vector<vector<int>> *blocks, int a, int b) {
    int bLocation[2];
    getLocation(b, blocks, bLocation);

    // Taking care of the blocks on top of 'b'.
    if ((blocks->at(bLocation[0]).size() - 1) > bLocation[1]) {
        vector<int> topOfB;
        for (int i = bLocation[1] + 1; i < blocks->at(bLocation[0]).size(); i++) {
            topOfB.push_back(blocks->at(bLocation[0]).at(i));
        }

        returnToInitialPosition(blocks, &topOfB, bLocation, b, true);
    }

    // Taking care of 'a' and the blocks on top of 'a'.
    int aLocation[2];
    getLocation(a, blocks, aLocation);

    if (blocks->at(aLocation[0]).size() > 1) {
        vector<int> topOfA;
        for (int i = aLocation[1] + 1; i < blocks->at(aLocation[0]).size(); i++) {
            topOfA.push_back(blocks->at(aLocation[0]).at(i));
        }

        returnToInitialPosition(blocks, &topOfA, aLocation, a);
    } else {
        blocks->erase(blocks->begin() + aLocation[0]);
    }

    // Now move a onto b
    getLocation(b, blocks, bLocation);
    blocks->at(bLocation[0]).push_back(a);
}

void moveOver(vector<vector<int>> *blocks, int a, int b) {
    int aLocation[2];
    getLocation(a, blocks, aLocation);

    // Taking care of the blocks on top of 'a'.
    if (blocks->at(aLocation[0]).size() > 1) {
        vector<int> topOfA;
        for (int i = aLocation[1] + 1; i < blocks->at(aLocation[0]).size(); i++) {
            topOfA.push_back(blocks->at(aLocation[0]).at(i));
        }

        returnToInitialPosition(blocks, &topOfA, aLocation, a);
    } else {
        blocks->erase(blocks->begin() + aLocation[0]);
    }

    // Now move a onto b
    int bLocation[2];
    getLocation(b, blocks, bLocation);
    blocks->at(bLocation[0]).push_back(a);
}

void pileOnto(vector<vector<int>> *blocks, int a, int b) {
    int bLocation[2];
    getLocation(b, blocks, bLocation);

    // Taking care of blocks on top of 'b'
    if ((blocks->at(bLocation[0]).size() - 1) > bLocation[1]) {
        vector<int> topOfB;
        for (int i = bLocation[1] + 1; i < blocks->at(bLocation[0]).size(); i++) {
            topOfB.push_back(blocks->at(bLocation[0]).at(i));
        }

        returnToInitialPosition(blocks, &topOfB, bLocation, b, true);
    }

    int aLocation[2];
    getLocation(a, blocks, aLocation);
    getLocation(b, blocks, bLocation);

    pile(blocks, aLocation, bLocation);
}

void pileOver(vector<vector<int>> *blocks, int a, int b) {
    int aLocation[2];
    getLocation(a, blocks, aLocation);
    int bLocation[2];
    getLocation(b, blocks, bLocation);

    pile(blocks, aLocation, bLocation);
}

bool isValidInput(int a, int b, vector<vector<int>> *blocks) {
    int aLocation[2], bLocation[2];
    getLocation(a, blocks, aLocation);
    getLocation(b, blocks, bLocation);

    return aLocation[0] != bLocation[0];
}

void executeInputs(vector<vector<int>> *blocks) {
    string operation, type;
    int a, b;

    while (cin >> operation) {
        if (operation == "quit")
            break;

        cin >> a >> type >> b;
        if (isValidInput(a, b, blocks)) {
            if (operation == "move" && type == "onto")
                moveOnto(blocks, a, b);
            else if (operation == "move" && type == "over")
                moveOver(blocks, a, b);
            else if (operation == "pile" && type == "onto")
                pileOnto(blocks, a, b);
            else if (operation == "pile" && type == "over")
                pileOver(blocks, a, b);
        }
    }

    sort(&blocks->at(0), &blocks->at(0) + blocks->size());

}

void printVector(const vector<vector<int>> *v, int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ':';
        for (auto blockStack : *v) {
            if (blockStack.at(0) == i) {
                for (auto block : blockStack)
                    cout << " " << block;
                break;
            }
        }
        cout << endl;
    }
}

int main() {
    int size;
    cin >> size;

    vector<vector<int>> blocks = generateVector(size);

    executeInputs(&blocks);

    printVector(&blocks, size);

    return 0;
}