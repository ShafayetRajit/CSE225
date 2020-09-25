#ifndef SORTEDTYPE_H_INCLUDED
#define SORTEDTYPE_H_INCLUDED


template <class ItemType>
class SortedType
{
struct NodeType
{
ItemType info;
NodeType* next;
};
public:
SortedType();
~SortedType();
bool IsFull();
int LengthIs();
void MakeEmpty();
void RetrieveItem(ItemType&,
bool&);
void InsertItem(ItemType);
void DeleteItem(ItemType);
void ResetList();
void GetNextItem(ItemType&);
private:
NodeType* listData;
int length;
NodeType* currentPos;
};

#endif // SORTEDTYPE_H_INCLUDED




#include <iostream>
using namespace std;
template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listData = NULL;
    currentPos = NULL;
}
template <class ItemType>
int SortedType<ItemType>::LengthIs()
{
    return length;
}
template<class ItemType>
bool SortedType<ItemType>::IsFull()
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(bad_alloc& exception)
    {
        return true;
    }
}
template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    NodeType* newNode;
    NodeType* predLoc;
    NodeType* location;
    bool moreToSearch;
    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);
    while (moreToSearch)
    {
    if (location->info < item)
    {
        predLoc = location;
        location = location->next;
        moreToSearch = (location != NULL);
    }
    else moreToSearch = false;
    }
    newNode = new NodeType;
    newNode->info = item;
    if (predLoc == NULL)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
    NodeType* location = listData;
    NodeType* tempLocation;
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;
    }
    else
    {
    while (!(item==(location->next)->info))
        location = location->next;
    tempLocation = location->next;
    location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, bool& found)
{
    NodeType* location = listData;
    bool moreToSearch = (location != NULL);
    found = false;
    while (moreToSearch && !found)
    {
        if (item == location->info)
            found = true;
        else if (item > location->info)
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
        else
            moreToSearch = false;
    }
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    NodeType* tempPtr;
    while (listData != NULL)
    {
        tempPtr = listData;
    listData = listData->next;
    delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
SortedType<ItemType>::~SortedType()
{
    MakeEmpty();
}
template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = NULL;
}
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
{
    if (currentPos == NULL)
        currentPos = listData;
    else
        currentPos = currentPos->next;
    item = currentPos->info;
}




#ifndef SEAT_INFO_H_INCLUDED
#define SEAT_INFO_H_INCLUDED
#include<iostream>
using namespace std;
class SeatInfo
{
private:
    int seat_num;
    string pass_name;
public:
    SeatInfo();
    SeatInfo(int, string);
    void print();
};

#endif // SEAT_INFO_H_INCLUDED



#include<iostream>

SeatInfo::SeatInfo(){
    pass_name = " ";
}

SeatInfo::SeatInfo(int number, string name)
{
    seat_num = number;
    pass_name = name;
}

void SeatInfo::print()
{
    if (pass_name == " ")
        return;
    else
        std::cout <<"Seat: " << seat_num << " Name : " << pass_name << endl;
}




#ifndef COACH_INFO_H_INCLUDED
#define COACH_INFO_H_INCLUDED


class CoachInfo{
private:
    int coach_number;
    double start_time;
    SeatInfo seats[40];
public:
    CoachInfo();
    CoachInfo(int, double);
    void print();
    void print_passengers();
    void add_passengers(int, string);
    bool operator>(CoachInfo a);
    bool operator<(CoachInfo a);
    bool operator!=(CoachInfo a);
    bool operator==(CoachInfo a);
};

#endif // COACH_INFO_H_INCLUDED




#include<iostream>

CoachInfo::CoachInfo()
{
    start_time = 0;
    coach_number = 0;
}

CoachInfo::CoachInfo(int number, double time)
{
    start_time = time;
    coach_number = number;
}

void CoachInfo::print()
{
    std::cout << "Coach number " << coach_number << " Departs at " << start_time << " o'clock" << std::endl;
}

void CoachInfo::print_passengers()
{
    for(int i=0; i<40; i++)
    {
        seats[i].print();
    }
}

void CoachInfo::add_passengers(int number, string name)
{
    seats[number-1] = SeatInfo(number, name);
}

bool CoachInfo::operator<(CoachInfo a)
{
    if (start_time < a.start_time)
        return true;
    else
        return false;
}

bool CoachInfo::operator>(CoachInfo a)
{
    if (start_time > a.start_time)
        return true;
    else
        return false;
}

bool CoachInfo::operator!=(CoachInfo a)
{
    if (start_time != a.start_time)
        return true;
    else
        return false;
}

bool CoachInfo::operator==(CoachInfo a)
{
    if (start_time == a.start_time)
        return true;
    else
        return false;
}



#include <iostream>


using namespace std;

int main()
{
    cout << "Welcome to ENA PORIBOHON!" << endl;

    SortedType<CoachInfo> coach_info;

    CoachInfo coach1(1088, 14.00);
    coach_info.InsertItem(coach1);

    CoachInfo coach2(2063, 10.00);
    coach_info.InsertItem(coach2);

    CoachInfo coach3(2069, 07.00);
    coach_info.InsertItem(coach3);

    int j = 0;
    CoachInfo temp_coach;
    while (j < coach_info.LengthIs())
    {
        coach_info.GetNextItem(temp_coach);
        temp_coach.print();
        j++;
    }
    cout << endl;

    coach_info.DeleteItem(coach2);

    CoachInfo coach4(3055, 16.00);
    coach_info.InsertItem(coach4);


    coach4.add_passengers(32, "Fahim");
    coach4.add_passengers(33, "Shafayet");
    coach3.add_passengers(20, "Moin");

    coach_info.ResetList();
    j = 0;
    while (j < coach_info.LengthIs())
    {
        coach_info.GetNextItem(temp_coach);
        temp_coach.print();
        j++;
    }
    cout << endl;

    cout << "Passengers of coach 3055" << endl;
    coach4.print_passengers();



    return 0;
}
