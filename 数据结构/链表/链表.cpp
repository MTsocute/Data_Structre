#include "链表/linklist.h"

int main() {
    // head node
    linkList lList = {0, nullptr};

    ini_link_list(lList, 10);
    cout << "The length of link list is: " << lList.length << endl;
    show_linklist(lList);

    delete_all(lList);
    show_linklist(lList);

//    insert_into_linklist(lList, 2, 100);
//    delete_from_linklist(lList ,0);
//    show_linklist(lList);
//    cout << "The length of link list is: " << lList.length << endl;

    return 0;
}