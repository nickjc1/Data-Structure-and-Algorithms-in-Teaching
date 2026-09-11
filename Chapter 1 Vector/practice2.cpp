#include <iostream>
#include <vector>

using namespace std;



void showProduct(const vector<string>*, int);

int main(){

    int index;

    vector<string> products = {
        "Keyboard",
        "Mouse",
        "Monitor",
        "Webcam",
        "Headphones"
    };



    // list out all the products
    for(int i = 0; i < 5; i++){
        cout << "Product " << i << " : " << products.at(i) << endl;
    }
    cout << endl;

    cout << "Enter a product index: ";
    cin >> index;

    const vector<string>* selectedProduct = &products;

    //tests to see if the index is in range
    try {
        showProduct(selectedProduct, index);
    }
    catch(const out_of_range& e){
        cout << "Error : product index is out of range." << endl;
    }
    











}

void showProduct(const vector<string>* myProducts, int index){
    
    //getting the product from the index

    cout << "Product at index " << index << " : " << myProducts->at(index) << endl;

}