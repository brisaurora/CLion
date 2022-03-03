#include <iostream>
char Legal_Big_characters[5]="JQKA";
char Legal_characters_transform[4][3]={"10","11","12","13"};

using namespace std;
int main() {
    cout<<"输入'#'停止输入"<<endl;
    string sentence;
    cin>>sentence;
    cout<<sentence<<endl;

    system("pause");
    return 0;
}
